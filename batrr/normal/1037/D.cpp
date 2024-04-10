#include <bits/stdc++.h>
/*
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
*/
#define ll long long                   
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define IOS ios_base::sync_with_stdio(0);

using namespace std;                    

const int maxn=2e5+123,inf=1e9,mod=1e9+7;
vector<int> g[maxn];
int n,a[maxn],val[maxn];
bool was[maxn];
int main(){
    cin>>n;
    for(int i=1;i<n;i++){
        int v,u;
        cin>>v>>u;
        g[v].pb(u);
        g[u].pb(v);
    }
    for(int i=0;i<n;i++)
        cin>>a[i];
    
    set< pair< int ,int > > st,tmp;

    int m=1;

        if( a[0]!=1 ){
            cout<<"No";
            exit(0);    
        }

    for(auto to:g[a[0]]){
        st.insert({m,to});
        val[to]=m;
    }
         
    was[a[0]]=1;
    
    for(int i=1;i<n;i++){
        if( st.empty() ){
            st=tmp;
            tmp.clear();
        }
        int v=a[i];
        was[v]=1;
        
        if( st.begin()->f != val[v] ){
            cout<<"No";
            exit(0);    
        }

        st.erase({val[v],v});
        m++;
        for(auto to:g[v])
            if( !was[to] ){
                tmp.insert({m,to});
                val[to]=m;
            }
        
    }  
    cout<<"Yes";
    return 0;
}