#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define p_q priority_queue
using namespace std;

struct no{
    vector<int> ch;
    int dp=0;
};
vector<no> v;
void dfs(int r,int f){
    int cnt=0;
    for(auto h:v[r].ch){
        if(h!=f){
            dfs(h,r);
            v[r].dp+=v[h].dp;
            cnt+=(v[h].dp==0);
        }
    }
    v[r].dp+=max(0,cnt-1);
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
            a--;
            b--;
            v[a].ch.push_back(b);
            v[b].ch.push_back(a);
        }  
        if(n==1){
            cout << 0 << "\n";
            continue;
        }
        int flag=0;
        int ans=0;
        for(int i=0;i<n;i++){
            if(v[i].ch.size()>=3){
                flag=1;
                dfs(i,i);
                ans=v[i].dp;
                break;
            }
        }
        if(!flag){
            cout << 1 << "\n";
        }
        else{
            cout << ans << "\n";
        }
    }
    return 0;
}