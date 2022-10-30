// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5+228;
const ll inf = 0x3f3f3f3f3f3f3f3f;
ll d[N], d1[N], d2[N], a[N], ac=0;
vector<ll> g[N];
queue<ll> qq;

signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n, m;
        cin >> n >> m;
        for(ll i = 1;i<=n;i++) g[i].clear(), d[i]=inf;
        for(ll a,b, i=0;i<m;i++){
            cin >> a >> b;
            g[a].push_back(b);
        }
        qq.push(1);
        d[1]=d1[1]=d2[1]=0;
        ac=0;
        while(!qq.empty()){
            ll v  = qq.front();qq.pop();
            a[ac++]=v;
            d1[v]=d[v];
            d2[v]=d[v];
            for(auto i : g[v]){
                if(d[i]==inf){
                    d[i]=d[v]+1;
                    qq.push(i);
                }
            }
        }
        for(ll ip= 0;ip<n;ip++){
            ll i = a[ip];
            for(auto j : g[i]){
                if(d[i]>=d[j]){
                    d1[i]=min(d1[i], d[j]);
                }
            }
        }
        //for(ll i = 1;i<=n;i++) cerr<<d1[i]<<" a "; cerr<<'\n';
        for(ll ip= n-1;ip>=0;ip--){
            ll i = a[ip];
            d2[i]=d1[i];
            for(auto j : g[i]){
                if(d[i]<d[j]){
                    d2[i]=min({d2[i], d1[j], d2[j]});
                }
            }
        }
        for(ll i = 1;i<=n;i++) cout<<d2[i]<<' ';
        cout<<'\n';
    }
}