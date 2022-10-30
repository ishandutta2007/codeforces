// -- //
#include <bits/stdc++.h>
#define pll pair<ll, ll>
#define x first
#define y second
using namespace std;
typedef long long ll;
const ll N = 2e5+228;
ll a[N];
pll pfs[N];
ll pfmin[N];
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n, qq;
        cin >> n >> qq;
        ll sum=0;
        for(ll i = 0;i<n;i++){
            cin >> a[i];
            sum+=a[i];
            pfs[i]={(i?pfs[i-1].x:0)+a[i], i};
        }
        sort(pfs, pfs+n, greater<pll>());
        pfmin[0]=pfs[0].y;
        for(ll i = 1;i<n;i++){
            pfmin[i]=min(pfmin[i-1], pfs[i].y);
        }
        while(qq--){
            ll e;
            cin >> e;
            if(sum<=0){
                ll l =0, r=n;
                while(r-l>1){
                    ll m = (l+r)>>1;
                    if(pfs[m].x>=e)l=m;
                    else r=m;
                }
                if(pfs[l].x<e) cout<<-1<<' ';
                else cout<<pfmin[l]<<' ';
            }else{
                ll gs = max(0ll, (e-pfs[0].x+sum-1)/sum);
                ll rs = gs*n, ts = sum*gs;
                ll need = e-ts;
                ll l =0, r=n;
                while(r-l>1){
                    ll m = (l+r)>>1;
                    if(pfs[m].x>=need)l=m;
                    else r=m;
                }
                cout<<rs+pfmin[l]<<' ';
            }
        }
        cout<<'\n';
    }
}