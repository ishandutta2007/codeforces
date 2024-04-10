//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>


using namespace std;


using ll = long long;
using ld = long double;

#define X first
#define Y second

const ll mod = 1000000007;
//const ll mod = 998244353;



void solve()
{
    pair<ld,ld> x;
    cin >> x.X >> x.Y;
    {
        ll wx, wy;
        cin >> wx >> wy;
        x.X = wx-x.X;
        x.Y = wy-x.Y;
    }
    ld V, T;
    cin >> V >> T;
    vector<pair<ld,ld>> dV(2);
    for (ll i=0;i<2;i++)
    {
        cin >> dV[i].X >> dV[i].Y;
    }
    ld L = 0, R = 1e12;
    for (ll w=0;w<200;w++)
    {
        ld M = (L+R)*0.5;
        pair<ld,ld> dx = x;
        if (M<T)
        {
            dx.X -= dV[0].X*M;
            dx.Y -= dV[0].Y*M;
        } else
        {
            dx.X -= dV[0].X*T+(M-T)*dV[1].X;
            dx.Y -= dV[0].Y*T+(M-T)*dV[1].Y;
        }
        ld S = sqrt(dx.X*dx.X+dx.Y*dx.Y);
        if (S>V*M) L = M;
        else R = M;
    }
    cout.precision(20);
    cout << R << "\n";
}


int main()
{
    ios_base::sync_with_stdio(false);
    ll T;
    T = 1;
    //cin >> T;
    while (T--) solve();
}