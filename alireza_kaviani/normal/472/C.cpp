#include <bits/stdc++.h>
using namespace std;

typedef long long                   ll;
typedef long double                 ld;
typedef pair<int,int>               pii;
typedef pair<ll,ll>                 pll;
typedef pair<double,double>         pdd;
typedef pair<ld,ld>                 pld;
typedef pair<string , string>       pss;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define Mp                          make_pair
#define endt                        '\t'
#define ends                        ' '
#define error(x)                    cerr << #x << " = " << x << endl
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
inline int input(){int n; cin >> n ; return n;}
ll pw(ll a , ll b)  { return (!b ? 1 : (b & 1 ? a * pw(a * a , b / 2) : pw(a * a , b / 2))); }

int main()
{
    fast_io;

    string p = "";
    int n;
    cin >> n;

    vector<pss> h(n);
    for(int i = 0 ; i < n ; i++)
    {
        cin >> h[i].X >> h[i].Y;
        if(h[i].X > h[i].Y) swap(h[i].X , h[i].Y);
    }
    for(int i = 0 ; i < n ; i++)
    {
        int x = input() - 1;
        if(i == 0)  p = h[x].X;
        else
        {
            if(h[x].Y < p)    return cout << "NO" << endl , 0 ;
            else if(h[x].X > p)     p = h[x].X;
            else if(h[x].Y > p)     p = h[x].Y;
        }
    }
    cout << "YES" << endl;

    return 0;
}