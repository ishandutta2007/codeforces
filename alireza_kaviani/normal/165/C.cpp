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

const ll MAXN = 1e6 + 10;
ll n , k , ans = 0 , cnt[MAXN];
string s;

int main()
{
    fast_io;

    cin >> k >> s;
    n = s.size();
    for(ll i = 0 ; i < n ; i++)
    {
        cnt[i] = (i == 0 ? (s[i] == '1') : cnt[i - 1] + (s[i] == '1'));
    }

    for(ll i = 0 ; i < n ; i++)
    {
        ll st = lower_bound(cnt + i , cnt + n , k + (i == 0 ? 0 : cnt[i - 1])) - cnt , en = upper_bound(cnt + i , cnt + n , k + (i == 0 ? 0 : cnt[i - 1])) - cnt;
        ans += en - st;
    }
    cout << ans << endl;

    return 0;
}