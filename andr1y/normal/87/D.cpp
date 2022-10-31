// -- //
#include <bits/stdc++.h>
#define pll pair<ll, ll>
#define x first
#define y second
using namespace std;
typedef long long ll;
const ll N = 1e5+228;
vector<pll> d[N];
ll tin[N], tout[N], timer=0;
void orient(ll v, ll p = -1){
    tin[v]=++timer;
    for(auto i : d[v]){
        if(i.x==p) continue;
        orient(i.x, v);
    }
    tout[v]=timer;
}
bool upper(ll a, ll b){
    return tin[a]<=tin[b]&&tout[a]>=tout[b];
}
pll edg[N];
ll lens[N];
ll ppp[N];
ll p[N], rng[N], sz[N];
ll _f(ll a){
    return p[a]==a?a:p[a]=_f(p[a]);
}
ll ff(ll a){
    return (p[a]==a)?a:ff(p[a]);
}
void _u(ll a, ll b){
    p[b]=a;
}
pair<ll, pll> qu[N];
ll quc=0;
ll mv=0;
ll mvs[N], mc=0;
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll n;
    cin >> n;
    for(ll a, b, c, i = 0;i+1<n;i++){
        cin >> a >> b >> c;
        d[a].push_back({b, i});
        d[b].push_back({a, i});
        lens[i]=c;
        edg[i]={a, b};
        ppp[i]=i;
    }
    orient(1);
    for(ll i = 1;i<=n;i++) p[i]=i, sz[i]=1;
    sort(ppp, ppp+n-1, [&](ll a, ll b){
        return lens[a]<lens[b];
    });
    for(ll i = 0;i<n-1;i++){
        ll j = ppp[i];
        ll a = edg[j].x, b = edg[j].y, c = lens[j];
        if(upper(b, a)) swap(a, b);
        qu[quc++]={j, {a, b}};
        ll ea=a, ef=ff(a);
        while(true){
            sz[ea]+=sz[b];
            if(ea==ef) break;
            ea=p[ea];
        }
        _u(a, b);
        if(i==n-2||c!=lens[ppp[i+1]]){
            for(j=0;j<quc;j++){
                a = qu[j].y.x, b = qu[j].y.y, c = ff(a);
                ll v = (sz[b])*(sz[c]-sz[b]);
                if(v>mv){
                    mv=v;
                    mvs[0]=qu[j].x;
                    mc=1;
                }else if(v==mv){
                    mvs[mc++]=qu[j].x;
                }
            }
            quc=0;
        }
    }
    sort(mvs, mvs+mc);
    cout<<mv+mv<<' '<<mc<<'\n';
    for(ll i = 0;i<mc;i++) cout<<mvs[i]+1<<' ';
}