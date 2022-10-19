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
inline ll input(){ll n; cin >> n ; return n;}
ll pw(ll a , ll b)  { return (!b ? 1 : (b & 1 ? a * pw(a * a , b / 2) : pw(a * a , b / 2))); }

const ll MAXN = 1.5e5 + 10;
ll n , k , q , t[MAXN] , mark[MAXN], type , id;
vector<ll> vec;

int main()
{
    fast_io;

    cin >> n >> k >> q;
    for(ll i = 1 ; i <= n ; i++) cin >> t[i];

    while(q--)
    {
        cin >> type >> id;
        if(type == 1)
        {
            vec.push_back(t[id]);
            sort(all(vec) , greater<ll>());
            if(vec.size() > k)  vec.pop_back();
            mark[id] = 1;
        }
        if(type == 2)
        {
            if(mark[id] && t[id] >= vec.back()) cout << "YES" << endl;
            else    cout << "NO" << endl;
        }
    }

    return 0;
}