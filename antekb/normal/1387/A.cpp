#include<bits/stdc++.h>
#define st first
#define nd second
using namespace std;

const int N=1e5+5;
bool sgn[N], vis[N], vis2[N];
int val[N], num[N];
vector<pair<int, int> > E[N];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin>>n>>m;
    for(int i=0; i<m; i++){
        int u, v, w;
        cin>>u>>v>>w;
        w*=2;
        E[u].push_back({v, w});
        E[v].push_back({u, w});
    }
    for(int i=1; i<=n; i++){
        if(vis[i])continue;
        vector<int> V;
        V.push_back(i);
        vis[i]=1;
        sgn[i]=1;
        int czy=0, x=0;
        for(int j=0; j<V.size(); j++){
            int v=V[j];
            //cout<<v<<" "<<sgn[v]<<" "<<val[v]<<" "<<czy<<" "<<x<<"\n";
            for(auto u:E[v]){
                if(!vis[u.st]){
                    V.push_back(u.st);
                    sgn[u.st]=sgn[v]^1;
                    val[u.st]=u.nd-val[v];
                    vis[u.st]=1;
                }
                else{
                    if(sgn[u.st]!=sgn[v]){
                        if(val[u.st]+val[v]!=u.nd){
                            cout<<"NO"; return 0;
                        }
                    }
                    else{
                        czy=1;
                        if(sgn[v]==0)x=(val[u.st]+val[v]-u.nd)/2;
                        else x=-(val[u.st]+val[v]-u.nd)/2;
                    }
                }
            }
        }
        if(czy){

        }
        else{
            vector<int> V2;
            long long B=0;
            for(int j:V){
                if(sgn[j])V2.push_back(-val[j]);
                else V2.push_back(val[j]);
                B-=V2[V2.size()-1];
            }
            sort(V2.begin(), V2.end());
            int A=V.size();
            A=-A;
            long long opt=1e18;
            for(int j=0; j<V2.size(); j++){

                if(A*V2[j]+B<opt){
                    x=V2[j];
                    opt=A*V2[j]+B;
                }
                //cout<<A<<" "<<B<<" "<<V2[j]<<" "<<opt<<" "<<x<<"\n";
                A+=2;
                B-=2*V2[j];
                if(A*V2[j]+B<opt){
                    x=V2[j];
                    opt=A*V2[j]+B;
                }
                //cout<<A<<" "<<B<<" "<<V2[j]<<" "<<opt<<" "<<x<<"\n";
            }
        }
        for(int j:V){
            if(sgn[j])num[j]=x+val[j];
            else num[j]=-x+val[j];
        }
    }
    for(int i=1; i<=n; i++){
        for(auto u:E[i]){
            if(num[u.st]+num[i]!=u.nd){
                cout<<"NO";
                return 0;
            }
        }
    }
    cout<<"YES\n";
    for(int i=1; i<=n; i++){
        cout<<(double)num[i]/2<<" ";
    }
}