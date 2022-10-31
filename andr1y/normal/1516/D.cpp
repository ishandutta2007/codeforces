// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+228;
ll a[N], mxr[N];
ll lp[N], gp[N], prm[N], prc=0, cnt[N];
ll go[N][20];
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    for(ll i = 2;i<N;i++){
        if(!lp[i]){
            lp[i]=i, prm[prc++]=i;
            gp[i]=i;
        }
        for(ll j = 0;j<prc&&prm[j]<=lp[i]&&prm[j]*i<N;j++){
            lp[i*prm[j]]=prm[j];
            gp[i*prm[j]]=(prm[j]==lp[i] ? gp[i]*prm[j] : prm[j]);
        }
    }
    ll n, q;
    cin >> n >> q;
    for(ll i = 0;i<n;i++) cin >> a[i];
    ll count2=0;
    ll r=-1;
    for(ll l=0;l<n;l++){
        if(l){
            ll al = a[l-1];
            while(al>1){
                ll e = lp[al];
                al/=gp[al];
                cnt[e]--;
                if(cnt[e]==1) count2--;
            }
        }
        if(r<l){
            r=l;
            ll al=a[l];
            while(al>1){
                ll e = lp[al];
                al/=gp[al];
                cnt[e]++;
                if(cnt[e]==2) count2++;
            }
        }
        while(!count2&&r<n){
            r++;
            if(r==n) break;
            ll ar=a[r];
            while(ar>1){
                ll e = lp[ar];
                ar/=gp[ar];
                cnt[e]++;
                if(cnt[e]==2) count2++;
            }
        }
        mxr[l]=r-1;
    }
    for(ll i=0;i<20;i++) go[n][i]=n;
    for(ll i = n-1;i>=0;i--){
        go[i][0]=mxr[i]+1;
        for(ll L = 1;L<20;L++){
            go[i][L]=go[go[i][L-1]][L-1];
        }
    }
    while(q--){
        ll l, r;cin>>l>>r;--l, r--;
        ll res=1;
        for(ll L = 19;L>=0;L--){
            if(go[l][L]<=r){
                res+=(1LL<<L);
                l=go[l][L];
            }
        }
        cout<<res<<'\n';
    }
}