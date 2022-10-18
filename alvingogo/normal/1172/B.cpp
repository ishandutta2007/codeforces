#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define p_q priority_queue
using namespace std;
 
const int mod=998244353;
int mul(int x,int y){
    return 1ll*x*y%mod;
}
vector<int> fra;
void init(int x){
    fra.resize(x);
    fra[0]=1;
    for(int i=1;i<x;i++){
        fra[i]=mul(fra[i-1],i);
    }
}
struct no{
    vector<int> ch;
};
vector<no> v;
int ans=1;
void dfs(int r,int f){
    for(auto h:v[r].ch){
        if(h!=f){
            dfs(h,r);
        }
    }
    if(r==0){
        ans=mul(ans,fra[v[r].ch.size()]);
    }
    else{
        ans=mul(ans,fra[v[r].ch.size()-1]);
        ans=mul(ans,v[r].ch.size());
    }
}
int main(){
    AquA;
    init(2e5+7);
    int n;
    cin >> n;
    v.resize(n);
    for(int i=1;i<n;i++){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        v[a].ch.push_back(b);
        v[b].ch.push_back(a);
    }
    dfs(0,0);
    ans=mul(ans,n);
    cout << ans << "\n";
    return 0;
}