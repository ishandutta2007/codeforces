#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define FILL(i,n) memset(i,n,sizeof i)
#define X first
#define Y second
#define ET cout << "\n"
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(),v.end()
#define pb push_back
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#ifdef bbq
#define debug(...) {\
    fprintf(stderr,"%s - %d (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);\
    _do(__VA_ARGS__);\
}
#define DB(a,s,e) {for(int _i=s;_i<e;++_i) cerr << a[_i] << " ";cerr << "\n";}
template<typename T>void _do(T &&x){cerr<<x<<endl;}
template<typename T,typename ...S> void _do(T &&x,S &&...t){cerr<<x<<", ";_do(t...);}
template<typename a,typename b> ostream& operator << (ostream &s,const pair<a,b> &p){return s<<"("<<p.X<<","<<p.Y<<")";}
#else
#define debug(...)
#define DB(a,s,e)
#endif

const ll MOD = 1e9 + 7;
map<ll, ll> cnt;
ll offset, sum;

void insert(ll x, ll v) {
    (cnt[x - offset] += v) %= MOD;
    (sum += v) %= MOD;
}

ll query(ll x) {
    auto p = cnt.find(x - offset);
    if (p == cnt.end())
        return sum;
    return (sum - p -> Y + MOD) % MOD;
}

ll dp[200005], arr[200005];

int main() {
    IOS();
    int t;
    cin >> t;
    while (t--) {
        int n;
        ll ans = 1;
        cnt.clear(), sum = 0, offset = 0;
        cin >> n >> arr[1];
        insert(arr[1], 1);
        dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            cin >> arr[i];
            offset += arr[i];
            dp[i] =  query(arr[i]);
            insert(arr[i], dp[i]);
            (ans += dp[i]) %= MOD;
        }
        cout << ans << "\n";
    }
}