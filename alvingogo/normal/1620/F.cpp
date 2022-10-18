#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define p_q priority_queue
using namespace std;

int main(){
    AquA;
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i=0;i<n;i++){
            cin >> v[i];
        }
        vector<array<array<int,2>,2> > dp(n);
        vector<array<array<pair<int,int>,2>,2> > from(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<2;j++){
                for(int k=0;k<2;k++){
                    dp[i][j][k]=1e9;
                    from[i][j][k]={-1,-1};
                }
            }
        }
        dp[0][0][0]=-1e9;
        dp[0][1][0]=-1e9;
        for(int i=1;i<n;i++){
            for(int j=0;j<2;j++){
                for(int k=0;k<2;k++){
                    if(dp[i-1][j][k]<5e8){
                        int x=(j?-v[i-1]:v[i-1]),y=dp[i-1][j][k];
                        if(x<y){
                            swap(x,y);
                        }
                        int u=v[i];
                        if(u>x){
                            if(dp[i][0][0]>y){
                                dp[i][0][0]=y;
                                from[i][0][0]={j,k};
                            }
                        }
                        else if(u>y){
                            if(dp[i][0][1]>x){
                                dp[i][0][1]=x;
                                from[i][0][1]={j,k};
                            }
                        }
                        u=-v[i];
                        if(u>x){
                            if(dp[i][1][0]>y){
                                dp[i][1][0]=y;
                                from[i][1][0]={j,k};
                            }
                        }
                        else if(u>y){
                            if(dp[i][1][1]>x){
                                dp[i][1][1]=x;
                                from[i][1][1]={j,k};
                            }
                        }
                    }
                }
            }
        }
        int p=-1,r=-1;
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                if(dp[n-1][i][j]<5e8){
                    p=i;
                    r=j;
                }
            }
        }
        if(p<0){
            cout << "NO\n";
            continue;
        }
        vector<int> ans(n);
        for(int i=n-1;i>=0;i--){
            ans[i]=p?-v[i]:v[i];
            int y=p,z=r;
            p=from[i][y][z].fs;
            r=from[i][y][z].sc;
        }
        cout << "YES\n";
        for(int i=0;i<n;i++){
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}