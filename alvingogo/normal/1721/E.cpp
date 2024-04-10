#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define p_q priority_queue
using namespace std;

int main(){
    AquA;
    string s;
    cin >> s;
    int n=s.length();
    s="$"+s;
    vector<int> f(n+15);
    vector<vector<int> > dp(n+1,vector<int>(26,0));
    dp[0][s[1]-'a']=1;
    f[0]=-1;
    f[1]=0;
    for(int i=2;i<=n;i++){
        int w=f[i-1];
        while(w>=0 && s[w+1]!=s[i]){
            w=f[w];
        }
        f[i]=w+1;
        for(int j=0;j<26;j++){
            dp[i-1][j]=dp[f[i-1]][j];  
        }
        dp[i-1][s[i]-'a']=i;
    }
    int q;
    cin >> q;
    for(int z=0;z<q;z++){
        string t;
        cin >> t;
        for(auto h:t){
            s.push_back(h);
        }
        int m=t.length();
        for(int i=n+1;i<=n+m;i++){
            int w=f[i-1];
            while(w>=0 && s[w+1]!=s[i]){
                if(w<n){
                    w=dp[w][s[i]-'a']-1;
                    break;
                }
                w=f[w];
            }
            f[i]=w+1;
            cout << f[i] << " ";
        }
        cout << "\n";
        for(int i=0;i<m;i++){
            s.pop_back();
            f[n+m-i]=0;
        }
    }
    return 0;
}