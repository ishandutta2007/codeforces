#include<bits/stdc++.h>
#define st first
#define nd second
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int N=5e5+5, INF=1e9+5;
int tab[N];
vi E[N];
int main(){
    int t=1;
    //cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        for(int i=0; i<m; i++){
            int u, v;
            cin>>u>>v;
            E[u].push_back(v);
            E[v].push_back(u);
        }
        for(int i=1; i<=n; i++){
            cin>>tab[i];
        }
        bool b=1;
        for(int i=1; i<=n; i++){
            vi V;
            for(int j:E[i]){
                V.push_back(tab[j]);
            }
            sort(V.begin(), V.end());
            int a=1;
            for(int j=0; j<V.size(); j++){
                if(V[j]==a) a++;
                if(V[j]>a) break;

            }
            if(a!=tab[i]) b=0;
            if(!b)break;
        }
        if(!b)cout<<"-1";
        else{
            vi V;
            for(int i=1; i<=n; i++){
                V.push_back(i);
            }
            sort(V.begin(), V.end(), [](int x, int y){return tab[x]<tab[y];});
            for(int i:V){
                cout<<i<<" ";
            }
        }
    }
}