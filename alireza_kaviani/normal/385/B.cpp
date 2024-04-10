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

const ll MAXN = 5010;
ll n , ans , cnt[MAXN];
string s;

int main()
{
    fast_io;

    cin >> s;
    n = s.size();

    for(ll i = 0 ; i < n ; i++)
    {
        if(s.substr(i , 4) == "bear")   cnt[i + 3]++;
    }
    partial_sum(cnt , cnt + MAXN , cnt);
    for(ll i = 0 ; i < n ; i++)
    {
        for(ll j = i + 3 ; j < n ; j++)
        {
            if((i == 0 && cnt[j]) || (i > 0 && cnt[j] - cnt[i + 2] > 0)) ans++;
        }
    }
    cout << ans << endl;

    return 0;
}