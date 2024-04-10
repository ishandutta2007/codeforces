// -- //
#include <bits/stdc++.h>
#define pll pair<ll, ll>
#define x first
#define y second
using namespace std;
typedef int ll;
const ll N = 1e5+228;
vector<ll> d[N];
pair<ll, pll> qs[N];
vector<ll> onq[N];
ll pers[N], pc=0, id[N];
ll tin[N], tout[N], timer=0;
void dfs(ll v){
    tin[v]=++timer;
    for(auto i :d[v]){
        dfs(i);
    }
    tout[v]=timer;
}
bool upper(ll a, ll b){
    return tin[a]<=tin[b]&&tout[a]>=tout[b];
}
char qr[N];
ll p[N];
ll _f(ll v){
    return p[v]==v?v:p[v]=_f(p[v]);
}
void _u(ll a, ll b){
    a=_f(a), b=_f(b);
    if(a==b) return;
    p[b]=a;
}
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	ll n, m;
	cin>>n>>m;
	for(ll i = 1;i<=n;i++) p[i]=i;
	for(ll i = 0;i<m;i++){
	    ll a, b, c=0;
	    cin >> a >> b;
	    if(a!=2) cin>>c;
	    qs[i]={a, {b, c}};
	    if(a==1){
	        d[c].push_back(b);
	        id[b]=1;
	    }
	    if(a==2){
	        pers[++pc]=i;
	    }
	    if(a==3){
	        onq[pers[c]].push_back(i);
	    }
	}
	for(ll i = 1;i<=n;i++){
	    //cout<<tin[i]<<' '<<id[i]<<'\n';
	    if(!tin[i]&&!id[i]){
	        dfs(i);
	        //cout<<i<<'\n';
	    }
	}
	for(ll i =0;i<m;i++){
	    if(qs[i].x==1){
	        _u(qs[i].y.x, qs[i].y.y);
	    }else if(qs[i].x==2){
	        ll bt = qs[i].y.x;
	        for(auto j : onq[i]){
	            ll tp = qs[j].y.x;
	            qr[j]=(_f(tp)==_f(bt)&&upper(tp,bt)?2:1); 
	        }
	    }
	}
	for(ll i  =0;i<m;i++){
	    if(!qr[i])continue;
	    if(qr[i]==2) cout<<"YES\n";
	    else cout<<"NO\n";
	}
}