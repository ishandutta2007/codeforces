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
#define o cout<<"BUG"<<endl;
#define IOS ios_base::sync_with_stdio(0);

using namespace std;                    

const ll maxn=2e5+123,inf=1e18,mod=1e9+7,N=360360;
string s,t;
int dp[maxn];
int main(){
    #ifdef LOCAL
        freopen ("test.in", "r", stdin);
    #endif
    cin>>s>>t; 
    for(int i=0;i<s.size();i++)
        if(s[i]=='0')
            s[i]=0;
        else
            s[i]=1;
    for(int i=0;i<t.size();i++)
        if(t[i]=='0')
            t[i]=0;
        else
            t[i]=1;
   
    for(int i=0;i<s.size();i++){
        if(i!=0)
            dp[i]=dp[i-1];
        if( i>0 && s[i]+t[i]+s[i-1]+t[i-1]<=1 ){
            if(i>=2)
                dp[i]=max(dp[i],dp[i-2]+1);
            else
                dp[i]=max(dp[i],1);
        }

        if( i>=2 && s[i]+t[i]+s[i-1]+t[i-1]+s[i-2]+t[i-2]==0 ){
            if(i>=3)
                dp[i]=max(dp[i],dp[i-3]+2);
            else
                dp[i]=max(dp[i],2);
        }

    }
    cout<<dp[s.size()-1];
}