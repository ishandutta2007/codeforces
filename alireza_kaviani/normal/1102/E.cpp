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
#define tab                         '\t'
#define sep                         ' '
#define error(x)                    cerr << #x << " = " << x << endl
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io                     freopen("in.txt" , "r+" , stdin) ; freopen("out.txt" , "w+" , stdout);
inline ll input(){ll n; cin >> n ; return n;}
ll pw(ll a , ll b , ll md)  { return (!b ? 1 : (b & 1 ? a * pw(a * a % md , b / 2 , md) % md : pw(a * a % md , b / 2 , md) % md)); }

const ll MAXN = 3e5 + 10 , MOD = 998244353;
ll n , ind , x , ans , a[MAXN];
map<ll , ll> p , cnt , cnt2;
set<ll> st;

ll Find(ll v)
{
    return (p[v] == 0 ? v : p[v] = Find(p[v]));
}

void Union(ll v , ll u)
{
    ll pv = Find(v) , pu = Find(u);
    if(pv == pu)    return;
    p[max(pv , pu)] = min(pv , pu);
}

int main()
{
    fast_io;  /** if you sure your code is true but get TLE use scanf and printf*/

    cin >> n;
    for(ll i = 0 ; i < n ; i++)
    {
        cin >> a[i];
        cnt[a[i]]++;
    }

    for(ll i = 0 ; i < n ; i++)
    {
        x = -1;
        cnt2[a[i]]++;
        for( ; ind < i ; ind++)
        {
            if(cnt2[a[ind]] != cnt[a[ind]])
            {
                x = ind;
                break;
            }
        }
        if(x != -1)
        {
            Union(a[i] , a[x]);
        }
    }

    for(ll i = 0 ; i < n ; i++)
    {
        st.insert(Find(a[i]));
    }
    for(auto &i : st)
    {
        if(i != Find(a[0]))
        {
            ans++;
        }
    }
    cout << pw(2 , ans , MOD);

    return 0;
}