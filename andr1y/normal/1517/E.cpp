// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5+228;
const ll M = 998244353;
ll a[N];
ll pf[2][N];
ll getres(ll l, ll r){
    return pf[l&1][r]-(l?pf[l&1][l-1]:0);
}
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n;
        cin >> n;
        ll sai=0;
        for(ll i = 0;i<n;i++){
            cin >> a[i];
            pf[0][i]=pf[1][i]=0;
            pf[i&1][i]=a[i]+a[i];
            if(i){
                pf[0][i]+=pf[0][i-1];
                pf[1][i]+=pf[1][i-1];
            }
            sai+=a[i];
        }
        ll sp=0, res=0;
        for(ll i = 0;i<=n;i++){
            if(sai-sp<sp) res++;
            if(i==n) break;
            sp+=a[i];
        }
        //last p
        ll tbal=-sai;
        for(ll i = 1;i<n;i++){
            tbal+=a[n-i]*2;
            ll tp=tbal, ep=tbal+a[0]+a[0];
            if(tbal>0) res++;
            if((tbal+a[0]+a[0]>0)&&n-i>1) res++;
            /*for(ll j = n-i-2;j>0;j-=2){
                tp+=a[j]+a[j];
                if(tp>0) res++;
            }*/
            ll l = (((n-i)&1)?1:2), yl=l, r=n-i, rr=n-i-2;
            if(l<=rr&&getres(l, rr)+tp>0){
                while(r-l>3){
                    ll m=l+((((r-l+2)/2)-1)/2)*2;
                    if(m<=rr&&getres(m, rr)+tp>0) l=m;
                    else r=m;
                }
                res+=(l-yl+2)/2;
            }
            /*for(ll j = n-i-2;j>1;j-=2){
                ep+=a[j]+a[j];
                if(ep>0) res++;
            }*/
            l = (((n-i)&1)?3:2), yl=l, r=n-i, rr=n-i-2;
            if(l<=rr&&getres(l, rr)+ep>0){
                while(r-l>3){
                    ll m=l+((((r-l+2)/2)-1)/2)*2;
                    if(m<=rr&getres(m, rr)+ep>0) l=m;
                    else r=m;
                }
                res+=(l-yl+2)/2;
            }
            res%=M;
        }
        //last c
        tbal=-sai;
        for(ll i = 2;i<n;i++){
            tbal+=a[n-i]*2;
            ll tp=tbal, ep=tbal+a[0]+a[0];
            if(tbal>0) res++;
            if((tbal+a[0]+a[0]>0)&&n-i>1) res++;
            /*for(ll j = n-i-2;j>0;j-=2){
                tp+=a[j]+a[j];
                if(tp>0) res++;
            }*/
            ll l = (((n-i)&1)?1:2), yl=l, r=n-i, rr=n-i-2;
            if(l<=rr&&getres(l, rr)+tp>0){
                while(r-l>3){
                    ll m=l+((((r-l+2)/2)-1)/2)*2;
                    if(m<=rr&&getres(m, rr)+tp>0) l=m;
                    else r=m;
                }
                res+=(l-yl+2)/2;
            }
            /*for(ll j = n-i-2;j>1;j-=2){
                ep+=a[j]+a[j];
                if(ep>0) res++;
            }*/
            l = (((n-i)&1)?3:2), yl=l, r=n-i, rr=n-i-2;
            if(l<=rr&&getres(l, rr)+ep>0){
                while(r-l>3){
                    ll m=l+((((r-l+2)/2)-1)/2)*2;
                    if(m<=rr&getres(m, rr)+ep>0) l=m;
                    else r=m;
                }
                res+=(l-yl+2)/2;
            }
            res%=M;
        }
        res%=M;
        cout<<res<<'\n';
    }
}