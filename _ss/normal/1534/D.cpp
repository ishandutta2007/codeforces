#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(vr) vr.begin(),vr.end()
#define vi vector<int>
#define vll vector<ll>
const int N = 1e5 + 10;
set<pii> E;

void add_edge(int u, int v)
{
    if (u > v) swap(u, v);
    E.insert(mp(u, v));
}

int main()
{
    //freopen("ss.inp", "r", stdin);
    int n;
    cin >> n;
    cout << "? 1" << endl;
    vi vt[2];
    for (int i = 1, x; i <= n; i++)
    {
        cin >> x;
        if (x == 1) add_edge(1, i);
        if (i != 1) vt[x & 1].eb(i);
    }
    if (vt[0].size() > vt[1].size()) swap(vt[0], vt[1]);
    for (int x : vt[0])
    {
        cout << "? " << x << endl;
        for (int i = 1, y; i <= n; ++i)
        {
            cin >> y;
            if (y == 1) add_edge(x, i);
        }
    }
    cout << "!\n";
    for (pii p : E) cout << p.fi << " " << p.se << "\n";
    cout << endl;
    return 0;
}