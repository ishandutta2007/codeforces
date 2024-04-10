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
int n,ans,cnt=1;
set<int>st;
int L,R,l,r;
int main(){
    ans=1;
    L=-1e9,R=1e9;
    st.insert(L);
    st.insert(R);
    cin>>n;
    for(int i=0;i<n;i++){
        string s;
        int x;
        cin>>s>>x;
        if(s=="ADD"){
            st.insert(x);
            if( L<x && x<R )
                cnt++;
        }else{
            cnt=1;
            set<int> :: iterator it;
            
            it=st.find(x);
            it--;

            l=*it;
            it=st.find(x);
            it++;
            r=*it;

            st.erase(x);
            if( L<x && x<R )
                ans=ans*2%mod;
            else
            if( L==x || x==R)
                ans=ans;
            else
                cout<<0,exit(0);
            L=l,R=r;
        }
    }
    cout<<1ll*ans*cnt%mod;
}