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

int arr[100005], nxtsum[100005], bksum[100005];

int main() {
    IOS();
    int n, q, k;
    cin >> n >> q >> k;
    for (int i = 1; i <= n; ++i)
        cin >> arr[i];
    for (int i = 2; i <= n; ++i)
        bksum[i] = bksum[i - 1] + arr[i] - arr[i - 1] - 1;
    for (int i = 1; i < n; ++i)
        nxtsum[i] = nxtsum[i - 1] + arr[i + 1] - arr[i] - 1;
    while (q--) {
        int l, r;
        cin >> l >> r;
        int ans = bksum[r] - bksum[l] + nxtsum[r - 1] - nxtsum[l - 1];
        if (arr[r] < k)
            ans += k - arr[r];
        if (arr[l] > 1)
            ans += arr[l] - 1;
        cout << ans << "\n";
    }
}