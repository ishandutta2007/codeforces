#include <bits/stdc++.h>
using namespace std;

typedef long long                   ll;
typedef long double                 ld;
typedef pair<int,int>               pii;
typedef pair<ll,ll>                 pll;
typedef pair<double,double>         pdd;
typedef pair<ld,ld>                 pld;

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

int main()
{
    fast_io;

    int n , m , now = 0;
    cin >> n >> m;

    vector<pii> tel;
    for(int i = 0 ; i < n ; i++)
    {
        int x , y;
        cin >> x >> y;
        tel.push_back({x , y});
    }
    Sort(tel);

    for(int i = 0 ; i < n ; i++)
    {
        if(tel[i].X <= now && tel[i].Y >= now)
        {
            now = tel[i].Y;
        }
    }
    cout << (now == m ? "YES" : "NO");

    return 0;
}