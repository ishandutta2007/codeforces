// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 3e5+228;
const ll N2 = 1e6+228;
ll a[N], k[N2];
ll b[15], bc=0;
ll lp[N2];
ll primes[N2], pc=0;
ll cnt[N2];
ll bb[N2], bq=0;
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	for(ll i = 2;i<N2;i++){
        if(lp[i]==0){
            primes[pc++]=i;
            lp[i]=i;
        }
        for(ll j = 0;j<pc&&primes[j]<=lp[i]&&primes[j]*i<N2;j++){
            lp[primes[j]*i]=primes[j];
        }
	}
	k[1]=1;
	for(ll i = 2;i<N2;i++){
        bc=0;
        for(ll j = i;j>1;j=j/lp[j]){
            if(bc==0||b[bc-1]!=lp[j]) b[bc++] = lp[j];
            else bc--;
        }
        ll e=1;
        for(ll j=0;j<bc;j++) e*=b[j];
        k[i]=e;
	}
    ll q;
    cin >> q;
    while(q--){
        bq++;
        ll n;
        cin >> n;
        ll mx=0;
        for(ll i = 0;i<n;i++){
            cin >> a[i];
            ll e = k[a[i]];
            cnt[e]++;
            if(cnt[e]>=mx) mx=cnt[e];
        }

        ll v2=0;
        ll sqc=0;
        for(ll i = 0;i<n;i++){
            ll e = k[a[i]];
            if(bb[e]==bq) continue;
            bb[e]=bq;
            if(e==1){
                sqc+=cnt[e];
            }else{
                if(cnt[e]&1) v2=max(v2, cnt[e]);
                else sqc+=cnt[e];
            }
        }
        v2=max(v2, sqc);
        for(ll i = 0;i<n;i++){
            ll e = k[a[i]];
            cnt[e]--;
        }
        ll qq, ee;
        cin >> qq;
        while(qq--){
            cin >> ee;
            if(ee==0){
                cout<<mx<<'\n';
            }else{
                cout<<v2<<'\n';
            }
        }
    }
}