#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int , int >
#define F first
#define S second
#define endl '\n'
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
using namespace std;
const int N=1e6+10;
ll mark[N];
ll match[N];
int match2[N];

vector <int> g[N];
bool dfs(ll v){
    mark[v]=1;
    for (int i=0;i<g[v].size();i++){
        ll u=g[v][i];
        if (match[u]==-1 || (!mark[match[u]] && dfs(match[u]))){
            match[u]=v;
            match2[v]=u;
            //cout << u << " " << match[u] << endl;

            return 1;
        }

    }
    return 0;
}
void Main(ll n,ll m,vector <int> a){
    
    memset(match,-1,sizeof match);
    memset(match2,0,sizeof match2);
    memset(mark,0,sizeof mark);
    ll f=1;
    ll last=0;
    while (f--){
        memset(mark, 0, sizeof(mark));
        for (int v=last+1; v<=n; v++) {
            if (dfs(v)){
                f=1;
                last=v;
                break;
            }
        }
    }
    ll cnt=0;
    for (int i=1;i<=n;i++){
        if (match[i]>-1){
            //cout << i << " " << a[i-1] << endl;
            cnt+=a[match[i]-1];
        }
    }
    cout << cnt << endl;
}
map <int,int> mp;
int32_t main(){
    sync;   
    ll n;
    cin >> n ;
    vector <int> a;
    vector <int> b;
    for (int i=1;i<=n;i++){
        ll x;
        cin >> x;
        b.pb(x);
        for (int k=1;k<=n;k++){
            if (mp[k*x]==0){
                mp[k*x]++;
                a.pb(k*x);
               // cout << " ekrf " << k*x << endl;
            }
        }
    }
    sort(a.begin(),a.end());
    for (int i=0;i<a.size();i++){
        mp[a[i]]=i+1;
    }
    ll z=0;
    for (auto u : b){
        z++;
        for (int k=1;k<=n;k++){
            g[mp[k*u]].pb(z);
          //  cout << k*u << " " << mp[k*u] << " yal " << z << endl;
        }
    }
    Main(a.size(),b.size(),a);

}