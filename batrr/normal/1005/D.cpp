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
string s;
int n,dp[maxn],a[maxn];
int check(int l,int r){
    int res=0;
    while(l<=r)
        res+=a[l++];
    return (res%3==0);
}
int main(){
    #ifdef LOCAL
        freopen ("test.in", "r", stdin);
    #endif                                     
    cin>>s;
    n=s.size();
    for(int i=0;i<n;i++)
        a[i+1]=(s[i]-'0')%3;
    for(int i=1;i<=n;i++)
        for(int j=max(0,i-4);j<i;j++)
            dp[i]=max(dp[i],dp[j]+check(j+1,i));
    cout<<dp[n];
}