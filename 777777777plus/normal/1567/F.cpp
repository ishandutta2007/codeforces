#include<bits/stdc++.h>
using namespace std;
typedef vector<int>vi;
int main(){
    ios::sync_with_stdio(0);
//    freopen("B.in","r",stdin);
    int n,m;cin>>n>>m;
    set<int> ar;
    for(int i=0;i<n;i++){
        string s;cin>>s;
        for(int j=0;j<m;j++)if(s[j]=='X')ar.insert(i*m+j);
    }
    vi wk{-1,-m,1,m};
    vi edg[n*m];
    for(auto i:ar){
        vi v;
        for(auto j:wk){
            if(!ar.count(i+j)){
                v.push_back(i+j);
            }
        }
        if(v.size()%2){cout<<"NO";return 0;}
        for(int i=0;i<v.size();i+=2){
            edg[v[i]].push_back(v[i+1]);
            edg[v[i+1]].push_back(v[i]);
        }
    }
    vi ans(n*m,0);
    for(int i=0;i<n*m;i++)if(!ar.count(i)&&ans[i]==0){
        function<void(int,int)>dfs=[&](int u,int c){
            ans[u]=c;
            for(auto v:edg[u])if(ans[v]==0){
                dfs(v,c^5);
            }
        };dfs(i,1);
    }
    for(auto i:ar)for(auto j:wk)if(!ar.count(i+j))ans[i]+=ans[i+j];
    cout<<"YES"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<ans[i*m+j]<<' ';
        }
        cout<<endl;
    }
}