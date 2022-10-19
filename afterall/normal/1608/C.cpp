#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int , int >
#define F first
#define S second
//#define endl '\n'
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
using namespace std;
const int N=2e5+100;
pii a[N];
pii b[N];
vector <int> g[N];
vector <int> ind[N];
vector <pii> f;
ll visit[N];
ll p1=0;
void dfs(ll v){
    visit[v]=1;
    for (int i=0;i<g[v].size();i++){
        ll u=g[v][i];
        if (visit[u]==0){
            dfs(u);

        }
    }
    p1++;
    f.pb({p1,v});
}
ll mol[N];
void sdf(ll v,ll k){
    mol[v]=k;
    for (int i=0;i<ind[v].size();i++){
        ll u=ind[v][i];
        if (mol[u]==0 && visit[u]==1){
            sdf(u,k);
        }
    }
}
void Main(){
    ll n;
    cin >> n ;
    f.clear();
    p1=0;
    for (int i=1;i<=n;i++){
        mol[i]=0;
        g[i].clear();
        ind[i].clear();
        visit[i]=0;
    }
    for (int i=1;i<=n;i++){
        cin >> a[i].F;
        a[i].S=i;
    }
    for (int i=1;i<=n;i++){
        cin >> b[i].F;
        b[i].S=i;
    }
    sort(a+1,a+n+1);
    sort(b+1,b+n+1);
    for (int i=n-1;i;i--){
        g[a[i+1].S].pb(a[i].S);
        ind[a[i].S].pb(a[i+1].S);

        g[b[i+1].S].pb(b[i].S);
        ind[b[i].S].pb(b[i+1].S);
    }
    ll p2=1;
    for (int i=1;i<=n;i++){
        if (visit[i]==0){
            f.clear();
            p1=0;
            dfs(i);
            sort(f.begin(),f.end());
            reverse(f.begin(),f.end());
            for (int j=0;j<f.size();j++){
                ll u=f[j].S;
                //cout << p2 << "vgbnj" << endl;
                if (mol[u]==0){
                    sdf(u,p2);

                    p2++;
                }
            }
        }
    }
    for (int i=1;i<=n;i++){
        if (mol[i]!=mol[a[n].S]) cout << 0;
        else cout << 1 ;
    }
    cout << endl;
    return ;
}
int32_t main(){
    sync;
    ll t=1;
    cin >> t;
    while(t--) Main();
}