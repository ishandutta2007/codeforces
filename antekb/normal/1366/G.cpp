#include<bits/stdc++.h>
#define sz(x) (x).size()
using namespace std;
const int N=10005;
int dp[N][N];
int tab[N];
int main(){
    string s, t;
    cin>>s>>t;
    for(int i=0; i<sz(s); i++){
        int k=0;
        for(int j=i; j>=0; j--){
            k+=2*(s[j]=='.')-1;
            if(k==0){tab[i]=j;break;}
            if(k<0)break;
        }
        if(k!=0)tab[i]=-1;
        //cout<<tab[i]<<" ";
    }
    //cout<<"\n\n";
    for(int i=0; i<=sz(s); i++){
        dp[i][sz(t)+1]=N;
        for(int j=sz(t); j>=0; j--){
            if(i==0 && j==0)continue;
            dp[i][j]=N;
            if(!i)continue;
            dp[i][j]=min(dp[i][j], dp[i-1][j]+1);
            if(tab[i-1]!=-1){
                dp[i][j]=min(dp[i][j], dp[tab[i-1]][j]);
            }
            if(!j){continue;}
            if(s[i-1]==t[j-1]){
                dp[i][j]=min(dp[i][j], dp[i-1][j-1]);
            }
            else{
                if(s[i-1]=='.') dp[i][j]=min(dp[i][j], dp[i-1][j+1]);

            }
        }
    }
    //for(int i=0; i<=sz(s); i++)
    //    for(int j=0; j<=sz(t); j++)
    //        cout<<dp[i][j]<<" \n"[j==sz(t)];
    cout<<dp[sz(s)][sz(t)];
}