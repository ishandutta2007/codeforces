#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define p_q priority_queue
using namespace std;

struct no{
    vector<int> ch;
};
vector<no> v;
int dfs(int r,int f,int k){
    int cnt=0;
    for(auto h:v[r].ch){
        if(h!=f){
            int u=dfs(h,r,k);
            if(u==0){
                return 0;
            }
            if(u==1){
                cnt++;
            }
        }
    }
    if(cnt%k==0){
        return 1;
    }
    else if((cnt+1)%k==0){
        return -1;
    }
    else{
        return 0;
    }
}
const int mod=998244353;
void add(int& x,int y){
    x+=y;
    x-=mod*(x>=mod);
    x+=mod*(x<0);
}
int mul(int x,int y){
    return 1ll*x*y%mod;
}
int po(int x,int y){
    int z=1;
    while(y){
        if(y&1){
            z=mul(z,x);
        }
        x=mul(x,x);
        y>>=1;
    }
    return z;
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
        vector<int> dp(n+1);
        dp[1]=po(2,n-1);
        for(int i=2;i<n;i++){
            if((n-1)%i==0){
                dp[i]=(dfs(0,0,i)!=0);
            }
        }
        for(int i=n;i>0;i--){
            for(int j=i+i;j<=n;j+=i){
                add(dp[i],-dp[j]);
            }
        }
        for(int i=1;i<=n;i++){
            cout << dp[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}