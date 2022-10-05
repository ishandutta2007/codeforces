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
ll n,a[maxn],suf[maxn],sum,ans;
multiset<ll>st;
int main(){
    #ifdef LOCAL
        freopen ("test.in", "r", stdin);
    #endif                                     
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=n-1;i>=0;i--){
        suf[i]=suf[i+1]+a[i];
        st.insert(suf[i]);
    }
    for(int i=0;i<n;i++){
        st.erase(st.find(suf[i]));
        sum+=a[i];
        if(st.find(sum)!=st.end())
            ans=sum;
    }
    cout<<ans;
}