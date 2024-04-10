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

int t[100005], x[100005], y[100005], dp[100005];

int main() {
    IOS();
    int n, r, mx = -1e9;
    cin >> r >> n, r <<= 1, x[0] = y[0] = 1;
    for (int i = 1; i <= n; ++i)
        cin >> t[i] >> x[i] >> y[i];
    for (int i = 1, bk = 0; i <= n; ++i) { 
        while (t[i] - t[bk] >= r)
            mx = max(mx, dp[bk]), ++bk;
        dp[i] = mx + 1;
        for (int j = bk; j < i; ++j)
            if (abs(x[i] - x[j]) + abs(y[i] - y[j]) <= t[i] - t[j])
                dp[i] = max(dp[i], dp[j] + 1);
    }
    cout << *max_element(dp, dp + n + 1) << "\n";
}