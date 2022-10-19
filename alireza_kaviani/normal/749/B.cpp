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

    vector<pii> pos;
    set<pii> ans;
    for(int i = 0 ; i < 3 ; i++)
    {
        int x , y;
        cin >> x >> y;
        pos.push_back({x , y});
    }

    for(int i = 0 ; i < 3 ; i++)
    {
        for(int j = 0 ; j < 3 ; j++)
        {
            if(i != j)
            {
                int k = 3 - (i + j) , dx = pos[i].X - pos[j].X , dy = pos[i].Y - pos[j].Y ;
                int nx = pos[k].X + dx , ny = pos[k].Y + dy;
                ans.insert({nx , ny});
            }
        }
    }

    cout << ans.size() << endl;
    for(auto &p : ans)
    {
        cout << p.X << ends << p.Y << endl;
    }

    return 0;
}