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
ll pw(ll a , ll b)  { return (!b ? 1 : (b & 1 ? a * pw(a * a , b / 2) : pw(a * a , b / 2))); }

int main()
{
    fast_io;

    int p , q , l , r , ans = 0;
    cin >> p >> q >> l >> r;

    vector<pii> vec(p) , sec(q);
    for(int i = 0 ; i < p ; i++)    cin >> vec[i].X >> vec[i].Y;
    for(int i = 0 ; i < q ; i++)    cin >> sec[i].X >> sec[i].Y;

    for(int i = l ; i <= r ; i++){
        int ok = 0;
        for(int j = 0 ; j < p ; j++){
            for(int k = 0 ; k < q ; k++){
                int x = sec[k].X + i , y = sec[k].Y + i;
                if(!(vec[j].Y < x || vec[j].X > y)) ok = 1;
            }
        }
        ans += ok;
    }
    cout << ans << endl;

    return 0;
}