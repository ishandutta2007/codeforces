#include<bits/stdc++.h>
#define st first
#define nd second
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int N=2e5+5, INF=1e9+5;
vi E[N];
int d[N], siz[N], tab[N];
void dfs(int v){
    siz[v]=1;
    for(int u:E[v]){
        if(!siz[u]){
            d[u]=d[v]+1;
            dfs(u);
            siz[v]+=siz[u];
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cout.tie(0);
    int n, k;
    cin>>n>>k;
    for(int i=1; i<n; i++){
        int a, b;
        cin>>a>>b;
        E[a].push_back(b);
        E[b].push_back(a);
    }
    dfs(1);
    for(int i=0; i<n; i++){
        tab[i]=siz[i+1]-d[i+1]-1;
    }
    sort(tab, tab+n);
    ll ans=0;
    for(int i=0; i<k; i++){
        ans-=tab[i];
    }
    cout<<ans;
}