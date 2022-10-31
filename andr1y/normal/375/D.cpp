// -- //
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define pll pair<ll, ll>
#define x first
#define y second
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> yree;
const ll N = 1e5+228;
vector<ll> d[N];
pll e[N];
ll a[N], pp[N], sz[N], unc[N];
vector<ll> kds[N];
map<ll, ll> cc[N];
yree cvv[N];
void dfs(ll v, ll p = -1){
    e[v]={0, v};
    pp[v]=p;
    sz[v]=1;
    for(auto i : d[v]){
        if(i==p) continue;
        dfs(i, v);
        e[v].x=max(e[v].x, e[i].x+1);
        sz[v]+=sz[i];
        kds[v].push_back(i);
    }
    sort(begin(kds[v]), end(kds[v]), [&](ll a, ll b){
        return sz[a]>sz[b];
    });
}
ll qr[N], qk[N];
vector<ll> qrs[N];
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll n, q;
    cin >> n >> q;
    for(ll i = 1;i<=n;i++) {
        cin >> a[i];
        unc[i]=i;
    }
    for(ll a, b, i=1;i<n;i++){
        cin >> a >> b;
        d[a].push_back(b);
        d[b].push_back(a);
    }
    dfs(1);
    sort(e+1, e+n+1);
    for(ll v, i = 0;i<q;i++){
        cin >> v >> qk[i];
        qrs[v].push_back(i);
    }
    for(ll ij=1;ij<=n;ij++){
        ll v = e[ij].y;
        if(kds[v].empty()){
            cc[v][a[v]]=1;
            cvv[v].insert(1);
        }else{
            unc[v]=unc[kds[v][0]];
            for(ll jj = 1;jj<kds[v].size();jj++){
                ll k = kds[v][jj];
                for(auto i : cc[unc[k]]){
                    ll color= i.x, cnt = i.y;
                    if(cc[unc[v]].count(color)){
                        ll &ee = cc[unc[v]][color];
                        cvv[unc[v]].erase(cvv[unc[v]].find_by_order(cvv[unc[v]].order_of_key(ee)));
                        ee+=cnt;
                        cvv[unc[v]].insert(ee);
                    }else{
                        cc[unc[v]][color]=cnt;
                        cvv[unc[v]].insert(cnt);
                    }
                }
            }
            if(cc[unc[v]].count(a[v])){
                ll &ee = cc[unc[v]][a[v]];
                cvv[unc[v]].erase(cvv[unc[v]].find_by_order(cvv[unc[v]].order_of_key(ee)));
                ee++;
                cvv[unc[v]].insert(ee);
            }else{
                cc[unc[v]][a[v]]=1;
                cvv[unc[v]].insert(1);
            }
        }
        for(auto i : qrs[v]){
            ll e = cvv[unc[v]].size()-cvv[unc[v]].order_of_key(qk[i]);
            qr[i]=e;
        }
    }
    for(ll i = 0;i<q;i++) cout<<qr[i]<<'\n';
}