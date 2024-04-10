//password1488
#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long ll;
const ll N = 2e5+228;
vector<ll> d[N];
//ll tin[N], tout[N], timer = 0;
ll aa[N], pd[N];
//pair<ll, ll> t[4*N];
//ll w[4*N];
//bool lf[4*N];
//ll tlb[N];
void dfs(ll v = 1, ll p = 0, ll h = 0){
    pd[v] = 1;
    for(auto i : d[v]){
        if(i == p) continue;
        dfs(i, v, h+1);
        pd[v]+=pd[i];
    }
    aa[v] = h-pd[v]+1;
}
//pair<ll, ll> cb(pair<ll, ll> a, pair<ll, ll> b){
//    if(a.x > b.x) return a;
//    else return b;
//}
//void push(ll v){
//    if(!lf[v]){
//        t[v+v].x += w[v];
//        t[v+v+1].x += w[v];
//        w[v+v] += w[v];
//        w[v+v+1] += w[v];
//    }
//    w[v] =0;
//}
//void build(ll v, ll tl, ll tr){
//    if(tl==tr){
//        t[v] ={aa[tl], tl};
//        lf[v] = 1;
//        return;
//    }
//    ll tm = (tl+tr)>>1;
//    build(v+v, tl, tm);
//    build(v+v+1, tm+1, tr);
//    t[v] = cb(t[v+v], t[v+v+1]);
//}
//void ic(ll v, ll tl, ll tr, ll l, ll r, ll val){
//    if(tl >= l && tr <= r){
//        t[v].x+=val;
//        w[v]+=val;
//        return;
//    }
//    push(v);
//    ll tm = (tl+tr)>>1;
//    if(tm >= l && tl <= r) ic(v+v, tl, tm, l, r, val);
//    if(tr >= l &&tm+1<= r) ic(v+v+1, tm+1, tr, l, r, val);
//    t[v] = cb(t[v+v], t[v+v+1]);
//}
signed main(){
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    ll n, k;
    cin >> n >> k;
    for(ll a, b, i = 1;i<n;i++){
        cin >> a >> b;
        d[a].push_back(b);
        d[b].push_back(a);
    }
    dfs();
    ll ans = 0;
//    ll done = 0;
//    for(ll fd = 0;fd<=n+3&&done<k;fd++){
//        if(fromdno[fd].size()+done <= k){
//            for(auto i : fromdno[fd]) ans+=i.first-pd[i.second]+1;
//            done+=fromdno[fd].size();
//        }else{
//            sort(begin(fromdno[fd]), end(fromdno[fd]), [&](auto a, auto b){
//                return a.first-pd[a.second]>b.first-pd[b.second];
//            });
//            for(ll j = 0;k^done;j++){
//                ans+=fromdno[fd][j].first-pd[fromdno[fd][j].second]+1;
//                done++;
//            }
//        }
//    }
    sort(aa+1, aa+1+n, greater<ll>());
    for(ll i = 1;i<=k;i++){
        ans += aa[i];
    }
    cout << ans << '\n';
}