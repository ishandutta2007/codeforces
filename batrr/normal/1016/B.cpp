#include <bits/stdc++.h>

#define ll long long                   
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define IOS ios_base::sync_with_stdio(0);

using namespace std;                    

const ll maxn=2e5+123,inf=1e18,mod=1e9+7;
int n,m,q,pre[maxn];
string s,t;
int main(){
    #ifdef LOCAL
        freopen ("test.in", "r", stdin);
    #endif                                     
    cin>>n>>m>>q;
    cin>>s>>t;
    for(int i=0;i<n;i++){
        pre[i+1]=pre[i];
        if( i+m-1<n && s.substr(i,m)==t )
            pre[i+1]++;
       // cout<<pre[i]<<" ";
    }
    while(q--){
        int l,r;
        cin>>l>>r;
        if(r-l+1>=m)
            cout<<pre[r-m+1]-pre[l-1]<<endl;
        else
            cout<<0<<endl;
    }
}