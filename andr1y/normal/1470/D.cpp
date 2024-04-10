// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 3e5+228;
vector<ll> d[N];
char color[N];
bool was[N];
ll cc[N];
ll tt=0;
void dfs(ll v){
    was[v]=1;
    tt++;
    for(auto i :d[v]){
        if(!was[i]) dfs(i);
    }
}
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n, m;
        cin >> n >> m;
        for(ll i = 1;i<=n;i++){
            d[i].clear();
            color[i]=0;
            was[i]=0;
            cc[i]=0;
        }
        tt=0;
        for(ll a, b, i=0;i<m;i++){
            cin >> a >> b;
            d[a].push_back(b);
            d[b].push_back(a);
        }
        dfs(1);
        if(tt<n){
            cout<<"NO\n";
            continue;
        }
        queue<ll> white;
        color[1]=2;
        for(auto i : d[1]){
            color[i]=1;
            white.push(i);
        }
        while(!white.empty()){
            ll v = white.front(); white.pop();
            ll nv=-1;
            for(;cc[v]<d[v].size();cc[v]++){
                ll i = d[v][cc[v]];
                if(color[i]==0){
                    nv=i;
                    cc[v]++;
                    break;
                }
            }
            if(nv==-1) continue;
            if(cc[v]!=d[v].size()) white.push(v);
            color[nv]=2;
            for(auto i : d[nv]){
                if(color[i]!=1){
                    color[i]=1;
                    white.push(i);
                }
            }
        }
        vector<ll> black;
        for(ll i = 1;i<=n;i++) if(color[i]==2) black.push_back(i);
        cout<<"YES\n"<<black.size()<<'\n';
        for(auto i : black) cout<<i<<' ';cout<<'\n';
    }
}