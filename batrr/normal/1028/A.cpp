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
int n,m,mxi,mxj,mni,mnj;
string s;
int main(){
    cin>>n>>m;   
    mxi=mxj=-1e9;
    mni=mnj=1e9;
    for(int i=0;i<n;i++){
        cin>>s;
        for(int j=0;j<m;j++)    
            if(s[j]=='B')                     
                mxi=max(mxi,i),mni=min(mni,i),
                mxj=max(mxj,j),mnj=min(mnj,j);
    }                      
    cout<<1+(mxi+mni)/2<<" ";
    cout<<1+(mxj+mnj)/2<<endl;
    return 0;
}