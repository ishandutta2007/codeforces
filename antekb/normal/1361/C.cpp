#include<bits/stdc++.h>
#define st first
#define nd second
#define pb(x) push_back(x)
#define mp(a, b) make_pair(a, b)
#define all(x) (x).begin(), (x).end()
#define sz(x) (x).size()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int N=(1<<20)+5, INF=2e9+5, mod=1e9+7;
vector<pii> E[N];
int vis[N], tab[N], uzy[N];
int n;
void dfs(int v){
    vis[v]=1;
    for(pii u:E[v]){
        if(!vis[u.st])dfs(u.st);
    }
}
bool check(int k){
    for(int i=0; i<n;i++){
        int u=tab[2*i]&((1<<k)-1), v=tab[2*i+1]&((1<<k)-1);
        E[u].push_back({v, 2*i});
        E[v].push_back({u, 2*i+1});
    }
    int t=0;
    for(int i=0; i<(1<<k); i++){
        if(sz(E[i])&1)return 0;
        if(E[i].size() && !vis[i]){
            if(t++)return 0;
            else dfs(i);
        }
    }
    return 1;
}
void czysc(int k){
    for(int i=0; i<(1<<k); i++){
        vis[i]=0;
        E[i].clear();
    }
}
vi res;
void euler(int v, int prv){
    while(sz(E[v])){
        pii x=E[v].back();
        E[v].pop_back();
        if(uzy[x.nd/2]) continue;
        uzy[x.nd/2]=1;
        euler(x.st, x.nd);
    }
    if(prv!=-1){
        res.pb(prv^1);
        res.pb(prv);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>tab[2*i]>>tab[2*i+1];
    }
    for(int i=20; i>=0; i--){
        //cout<<"a";
        if(check(i)){
            euler(tab[0]&((1<<i)-1), -1);
            cout<<i<<"\n";
            for(int j:res){
                cout<<j+1<<" ";
            }
            break;
        }
        czysc(i);
    }
}