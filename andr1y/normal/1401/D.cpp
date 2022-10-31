#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+228;
const ll M = 1e9+7;
vector<ll> d[N];
ll aa[N], bb[N], kf[N], ac=0, pd[N], n;
void dfs1(ll v, ll p = -1){
    pd[v]=1;
    for(auto i : d[v]){
        if(i==p) continue;
        dfs1(i, v);
        pd[v]+=pd[i];
        ll e = pd[i]*(n-pd[i]);
        aa[ac++]=e;
    }
}
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	ll q;
	cin >> q;
	while(q--){
        ll m;
        cin >> n;
        for(ll i = 1;i<=n;i++){
            d[i].clear();
        }
        ac=0;
        for(ll a, b, i = 1;i<n;i++){
            cin >> a >> b;
            d[a].push_back(b);
            d[b].push_back(a);
            aa[i-1]=0;
        }
        cin >> m;
        for(ll i = 0;i<m;i++) cin >> bb[i];
        sort(bb, bb+m, greater<ll>());
        dfs1(1);
        sort(aa, aa+ac, greater<ll>());
        if(m<=ac){
            for(ll i = 0;i<ac;i++) kf[i] = (i<m?bb[i]:1);
        }else{
            ll ovf=m-ac+1;
            kf[0]=1;
            for(ll i = 0;i<ovf;i++) kf[0]=(kf[0]*bb[i])%M;
            for(ll i = ovf, j=1;i<m;i++, j++) kf[j] = bb[i];
        }
        ll res=0;
        for(ll i = 0;i<ac;i++){
            res+=((aa[i]%M)*kf[i])%M;
            res%=M;
        }
        cout<<res<<'\n';
	}
}