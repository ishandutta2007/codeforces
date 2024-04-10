//password1488
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5+228;
ll a[N], pref_days[N], pref_sums[N];
inline ll sum1n(ll n) __attribute((always_inline));
inline ll sum1n(ll n){
    if(n<=0) return 0;
    return (n*(n+1))>>1;
}
signed main(){
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    ll n, x;
    cin >> n >> x;
    for(ll i = 0;i<n;i++){
        cin >> a[i];
        pref_days[i] = a[i];
        pref_sums[i] = sum1n(a[i]);
        if(i)pref_days[i]+=pref_days[i-1], pref_sums[i]+=pref_sums[i-1];
    }
    ll mv=0;
    for(ll i = 0;i<n;i++){
        if(a[i]>=x){
            mv=max(mv, sum1n(a[i])-sum1n(a[i]-x));
            continue;
        }
        ll l = 0, r=n;
        while(r-l>1){
            ll m= (l+r)>>1;
            ll bc= (i-m+n)%n;
            ll sd=0;
            if(bc<=i){
                sd=pref_days[i]-(bc?pref_days[bc-1]:0);
            }else{
                sd=pref_days[i]+pref_days[n-1]-(bc?pref_days[bc-1]:0);
            }
            if(sd>=x) r=m;
            else l=m;
        }
        ll bc= (i-l+n)%n;
        ll sd=0, sds=0;
        if(bc<=i){
            sd=pref_sums[i]-(bc?pref_sums[bc-1]:0);
            sds=pref_days[i]-(bc?pref_days[bc-1]:0);
        }else{
            sd=pref_sums[i]+pref_sums[n-1]-(bc?pref_sums[bc-1]:0);
            sds=pref_days[i]+pref_days[n-1]-(bc?pref_days[bc-1]:0);
        }
        ll lds=x-sds;
        bc--;
        bc+=n;
        bc%=n;
        sd+=sum1n(a[bc])-sum1n(a[bc]-lds);
        mv=max(mv, sd);
    }
    cout<<mv<<'\n';
}