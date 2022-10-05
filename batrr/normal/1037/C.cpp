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
#define IOS ios_base::sync_with_stdio(0);

using namespace std;                    

const int maxn=2e5+123,inf=1e9,mod=1e9+7;
string s,t;
int n,ans;
int main(){
    cin>>n;
    cin>>s>>t;
    for(int i=0;i<n;i++){
        if(s[i]==t[i])
            continue;
        
        if(i<n-1 && s[i+1]==t[i] && s[i]==t[i+1] )
            swap(s[i],s[i+1]);
        ans++;
    }
    cout<<ans;
    return 0;
}