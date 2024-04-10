// -- //
#include <bits/stdc++.h>
#define pll pair<ll, ll>
#define x first
#define y second
using namespace std;
typedef long long ll;
const ll N = 2e5+228;
pair<ll, pll> ed[N];
pair<ll, pll> ored[N];
vector<pll> d[N];
ll p[N][20], mxl[N][20], tin[N], tout[N], timer=0;
ll dsu[N];
ll _f(ll v){return dsu[v]==v?v:dsu[v]=_f(dsu[v]);}
void _u(ll a, ll b){a=_f(a), b=_f(b);if(a^b) dsu[b]=a;}
void dfs(ll v, ll _p = 0, ll _l = 0){
    p[v][0]=_p;
    mxl[v][0]=_l;
    tin[v]=++timer;
    for(ll L = 1;L<20;L++) p[v][L]=p[p[v][L-1]][L-1], mxl[v][L]=max(mxl[v][L-1], mxl[p[v][L-1]][L-1]);
    for(auto i : d[v])
        if(i.x!=_p) dfs(i.x, v, i.y);
    tout[v]=timer;
}
bool upper(ll a, ll b){
    return tin[a]<=tin[b]&&tout[a]>=tout[b];
}
ll lca(ll a, ll b){
    ll rs=0;
    for(ll L = 19;L+1;L--) if(p[a][L]&&!upper(p[a][L], b)) rs=max(rs, mxl[a][L]), a=p[a][L];
    if(!upper(a, b)) rs=max(rs, mxl[a][0]), a=p[a][0];
    for(ll L = 19;L+1;L--) if(p[b][L]&&!upper(p[b][L], a)) rs=max(rs, mxl[b][L]), b=p[b][L];
    if(!upper(b, a)) rs=max(rs, mxl[b][0]), b=p[b][0];
    assert(a==b);
    return rs;
}
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll n, m;
    cin >> n >> m;
    for(ll i = 1;i<=n;i++) dsu[i]=i;
    for(ll i=0;i<m;i++){
        cin >> ed[i].y.x >> ed[i].y.y >> ed[i].x;
        ored[i]=ed[i];
    }
    sort(ed, ed+m);
    ll cc=0;
    for(ll i = 0;i<m;i++){
        if(_f(ed[i].y.x)!=_f(ed[i].y.y)){
            _u(ed[i].y.x, ed[i].y.y);
            d[ed[i].y.x].push_back({ed[i].y.y, ed[i].x});
            d[ed[i].y.y].push_back({ed[i].y.x, ed[i].x});
            cc+=ed[i].x;
        }
    }
    dfs(1);
    for(ll i =0;i<m;i++){
        ll a = ored[i].y.x, b = ored[i].y.y, l = ored[i].x;
        ll k = lca(a, b);
        cout<<cc-k+l<<'\n';
    }
}