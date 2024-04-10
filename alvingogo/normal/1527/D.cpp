#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define p_q priority_queue
using namespace std;

struct no{
    vector<int> ch;
    int fa;
    int sz=1;
};
vector<no> v;
void dfs(int r,int f){
    v[r].fa=f;
    for(auto h:v[r].ch){
        if(h!=f){
            dfs(h,r);
            v[r].sz+=v[h].sz;
        }
    }
}
int main(){
    AquA;
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        v.clear();
        v.resize(n);
        for(int i=1;i<n;i++){
            int a,b;
            cin >> a >> b;
            v[a].ch.push_back(b);
            v[b].ch.push_back(a);
        }
        dfs(0,0);
        vector<long long> dp(n+1);
        dp[1]=dp[0]=1ll*n*(n-1)/2;
        vector<int> deg(n);
        deg[0]=1;
        multiset<int> s;
        s.insert(v[0].sz);
        for(auto h:v[0].ch){
            dp[1]-=1ll*v[h].sz*(v[h].sz-1)/2;
        }
        for(int i=1;i<n;i++){
            int lst=i;
            if(deg[i]==0){
                for(int e=v[i].fa;;e=v[e].fa){
                    if(deg[e]<0){
                        break;
                    }
                    deg[e]--;
                    if(e<i){
                        s.erase(s.find(v[e].sz));
                    }
                    if(e==0){
                        if(deg[0]==0){
                            v[0].sz-=v[lst].sz;
                            s.insert(v[0].sz);
                        }
                        break;
                    }
                    lst=e;
                    if(e<i){
                        break;
                    }
                }
                s.insert(v[i].sz);
            }
            if(s.size()>2){
                break;
            }
            dp[i+1]=1ll*(*s.begin())*(*next(s.begin()));
        }
        for(int i=0;i<n;i++){
            dp[i]-=dp[i+1];
        }
        for(auto h:dp){
            cout << h << " ";
        }
        cout << "\n";
    }
    
    return 0;
}