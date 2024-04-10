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
int main(){
    #ifdef LOCAL
        freopen ("test.in", "r", stdin);
    #endif                                     
    cin>>s>>t;
    s='1'+s;
    t='2'+t;
    for(int i=1;i<=min(s.size(),t.size());i++){
        if(s[s.size()-i]!=t[t.size()-i]){
            cout<<s.size()+t.size()-2*i;    
            return 0;
        }
    }
    
}