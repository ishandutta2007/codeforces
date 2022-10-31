// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5+228;
ll a[2][N], cnt[2][N];
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n, nl, nr;
        cin >> n >> nl >> nr;
        ll l=0, r=1;
        for(ll i = 1;i<=n;i++) cnt[0][i]=cnt[1][i]=0;
        for(ll i = 0;i<nl;i++){
            cin >> a[l][i];
            cnt[l][a[l][i]]++;
        }
        for(ll i = 0;i<nr;i++){
            cin >> a[r][i];
            cnt[r][a[r][i]]++;
        }
        if(nl<nr){
            swap(nl, nr);
            swap(l, r);
        }
        ll flow = (nl-nr)/2;
        ll res=flow;
        for(ll i = 1;i<=n;i++){
            if(cnt[l][i]>=cnt[r][i]){
                ll e = (cnt[l][i]-cnt[r][i])/2;
                e=min(flow, e);
                flow-=e;
                cnt[l][i]-=e;
                cnt[r][i]+=e;
            }
        }
        if(flow){
            for(ll i = 1;i<=n&&flow;i++){
                if(cnt[l][i]>cnt[r][i]){
                    cnt[l][i]--;
                    cnt[r][i]++;
                    flow--;
                }
            }
        }
        ll tres=0;
        for(ll i = 0;i<=n;i++) tres+=abs(cnt[l][i]-cnt[r][i]);
        tres/=2;
        res+=tres;
        cout<<res<<'\n';
    }
}