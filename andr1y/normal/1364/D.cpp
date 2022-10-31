// -- telegram @rentixous --
// -- keep calm and slava ukraini --
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+1488;
vector<ll> d[N];
vector<ll> d2[N];
vector<ll> lev[2];
void dfs1(ll v, ll p = -1, ll c = 0){
    lev[c].push_back(v);
    for(auto i : d[v]) if(i!=p) dfs1(i, v, c^1);
}
ll pp[N];
ll p2[N];
ll was[N];
vector<ll> cc;
void get_cycle(ll v, ll tt){
    while(v!=tt){
        cc.push_back(v);
        v=p2[v];
    }
    cc.push_back(tt);
}
void rpv(ll v, ll p=  -1){
    p2[v]=p;
    for(auto i : d2[v]){
        if(i!=p) rpv(i, v);
    }
}
void dfs2(){
    was[1]=1, pp[1]=-1;
    queue<ll> qq;
    qq.push(1);
    bool dd = 1;
    while(!qq.empty()&&dd){
        ll v = qq.front();
        qq.pop();
        was[v]=2;
        for(auto i : d[v]){
            if(i==pp[v]) continue;
            if(was[i]==2){
                rpv(v);
                get_cycle(i, v);
                dd=0;
                break;
            }else if(was[i]==0){
                was[i]=1;
                pp[i]=v;
                qq.push(i);
                d2[v].push_back(i);
                d2[i].push_back(v);
            }
        }
    }
}
signed main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll n, m, k;
    cin >> n >> m >> k;
    for(ll a, b, i = 0;i<m;i++){
        cin >> a >> b;
        d[a].push_back(b);
        d[b].push_back(a);
    }
    ll nd = (k+1)/2;
    if(m==n-1){
        dfs1(1);
        if(lev[0].size()>=nd){
            cout<<1<<'\n';
            for(ll i = 0;i<nd;i++) cout<<lev[0][i]<<' ';
        }else{
            cout<<1<<'\n';
            for(ll i = 0;i<nd;i++) cout<<lev[1][i]<<' ';
        }
    }else{
        dfs2();
        if(cc.size()<=k){
            cout << "2\n" << cc.size() << "\n";
            for(auto i : cc) cout<<i<<' ';
        }else{
            cout << "1\n";
            for(ll i = 0;i<nd;i++) cout<<cc[i+i]<<' ';
        }
    }
}