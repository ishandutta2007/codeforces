// -- telegram @rentixous --
// -- keep calm and slava ukraini --
#include <bits/stdc++.h>
#define pll pair<ll, ll>
#define x first
#define y second
using namespace std;
typedef long long ll;
const ll N = 1e5+1488;
vector<pll> d[N];
ll cc[N];
ll n;
vector<ll> e[2];
bool ok =1;
void do_color(ll v, ll cs, ll pp){
    e[pp].push_back(v);
    cc[v]=pp+1;
    for(auto i : d[v]){
        ll mbp = (i.y==cs?pp:(pp+1)%2);
        if(cc[i.x]){
            if(cc[i.x]-1 != mbp){
                ok=0;
            }
        }else{
            do_color(i.x, cs, mbp);
        }
    }
}
vector<ll> cnt(ll color){
    if(color==1){
        for(ll i = 1;i<=n;i++) cc[i]=0;
        ok=1;
    }
    vector<ll> res;
    for(ll i = 1;i<=n;i++){
        if(!cc[i]){
            e[0].clear();
            e[1].clear();
            do_color(i, color, 0);
            if(!ok) break;
            if(e[0].size()>e[1].size()) swap(e[0], e[1]);
            for(auto j : e[0]) res.push_back(j);
        }
    }
    if(!ok){
        vector<ll> e2;
        e2.push_back(-1);
        return e2;
    }else return res;
}
signed main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll m;
    cin >> n>> m;
    for(ll a, b, i = 0;i<m;i++){
        char c;
        cin >> a >> b >> c;
        ll c2=0;
        if(c=='B') c2=1;
        d[a].push_back({b, c2});
        d[b].push_back({a, c2});
    }
    vector<ll> v1 = cnt(0);
    vector<ll> v2 = cnt(1);
    bool bv1 = (v1.size()==1&&v1[0]==-1);
    bool bv2 = (v2.size()==1&&v2[0]==-1);
    if(bv1&&bv2){
        cout<<"-1\n";
    }else if(!bv1&&bv2){
        cout<<v1.size()<<'\n';
        for(auto i: v1) cout<<i<<' ';
    }else if(bv1&&!bv2){
        cout<<v2.size()<<'\n';
        for(auto i: v2) cout<<i<<' ';
    }else{
        if(v1.size()>v2.size()) swap(v1, v2);
        cout<<v1.size()<<'\n';
        for(auto i: v1) cout<<i<<' ';
    }
}