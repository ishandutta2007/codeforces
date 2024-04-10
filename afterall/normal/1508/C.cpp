#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef complex<double> point;
typedef long double ld;
#define pb push_back
#define pii pair < ll , ll >
#define F first
#define S second
//#define endl '\n'
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
const int N=2e5+100,inf=(ll)1e18+100;
vector <int> g[N];
set <pair <int,int> > s;
vector <int> q[N];
int val[N];
bool mark[N];
ll mol[N];
map <pii,int> mp;
vector <pair <int,pii> > yal;
vector <pair <int,pair <pii,pii> > > ya;
ll par2[N];
ll getpar2(ll v){
    if (par2[v]==v) return v;
    return par2[v]=getpar2(par2[v]);
}
ll par[N];
ll getpar(ll v){
    if (par[v]==v) return v;
    return par[v]=getpar(par[v]);
}
int32_t main(){
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);

    int n,m;
    cin >> n >> m;
    ll xo=0;
    for (int i=0;i<m;i++){
        int u,v,w;
        cin >> u >> v >> w;
        u--, v--;
        g[u].pb(v);
        g[v].pb(u);
        mp[{u,v}]=w;
        mp[{v,u}]=w;
        xo ^= w;
    }
    for (int i=0;i<n;i++){
        s.insert({val[i],i});
    }
    int cnt=0;
    int k=0;
    while(s.size()){
        int v=s.begin()->S;
        q[k].pb(v);
        mark[v]=true;
        s.erase(s.begin());

        for (int i=0;i<q[k].size();i++){
            v=q[k][i];
            cnt++;
            for (int j=0;j<g[v].size();j++){
                int u=g[v][j];
                if (!mark[u]){
                    s.erase({val[u],u});
                    val[u]=cnt;
                    s.insert({val[u],u});
                }
            }
            while(s.size() and s.begin()->F<cnt){
                q[k].pb(s.begin()->S);
                mark[s.begin()->S]=true;
                s.erase(s.begin());
            }
        }
        k++;
    }

   // cout << k << endl;
    for (int i=0;i<k;i++){
      //  cout << q[i].size() << " ";
        for (int j=0;j<q[i].size();j++){
            //cout << q[i][j]+1 << " ";
            mol[q[i][j]]=i;
        }
    }
    ll ans=0;
    for (int i=0;i<k;i++){
        for (int j=i+1;j<k;j++){
            ll mn=(ll)1e15;
            for (auto u : q[i]){
                for (auto v : q[j]){
                   //mn=min(mn,mp[{u,v}]);
                    yal.pb({mp[{u,v}],{i,j}});
                    ya.pb({mp[{u,v}],{{i,j},{u,v}}});
                }
            }
        }
    }
    sort(yal.begin(),yal.end());
    sort(ya.begin(),ya.end());
    for (int i=0;i<n;i++) par[i]=i,par2[i]=i;
    ll cc=-1;
    for (auto U : yal){
        cc++;
        ll u=U.S.F,v=U.S.S,w=U.F;
        u=getpar(u);
        v=getpar(v);
        if (u!=v){
            par[u]=v;
            ans+=w;
         //   cout << w << endl;
            u=ya[cc].S.S.F,v=ya[cc].S.S.S;
           // cout << u << " " << v << endl;
            u=getpar2(u);
            v=getpar2(v);
            par2[u]=v;
        }
    }
 //   for (int i=0;i<n;i++) cout << par2[i] << " ";
   // cout << " CD " << endl;
    ll mn=(ll)1e15;
    ll z=n*(n-1)/2-m;

    for (int i=0;i<k;i++){
        for (auto v : q[i]){
            for (auto u : g[v]){
                if (getpar2(u)!=getpar2(v)){
                    mn=min(mn,mp[{u,v}]);
                }
            }
        }
        z-=q[i].size()-1;

    }
    if (z==0) ans+=min(mn,xo);
    kill(ans);
    return 0;
}
/*
5 8
1 3 1000
1 5 1000
1 4 1000
2 3 100
2 5 0
2 4 1
4 3 1000
4 1 5
*/