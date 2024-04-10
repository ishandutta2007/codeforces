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

const ll MAXN = 100;
ll n , t[MAXN];

int main()
{
    fast_io;

    cin >> n;
    for(int i = 0 ; i < n ; i++)    cin >> t[i];

    for(int i = 0 ; i < n ; i++)
    {
        for(int j = i + 1 ; j < n ; j++)
        {
            for(int k = j + 1 ; k < n ; k++)
            {
                set<ll> st;
                st.insert(t[i]) ; st.insert(t[j]) ; st.insert(t[k]);
                if(st.size() == 3 && max({t[i] , t[j] , t[k]}) - min({t[i] , t[j] , t[k]}) <= 2) return cout << "YES" << endl , 0;
            }
        }
    }
    cout << "NO" << endl;

    return 0;
}