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
ll n,k,ans,a[maxn];
set<int>st;
int main(){
    #ifdef LOCAL
        freopen ("test.in", "r", stdin);
    #endif                                     
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1)
            st.insert(i);
    }
    a[n+1]=1;
    st.insert(n+1);
    // mult=sum*k
    for(int i=1;i<=n;i++){
        ll len,j=i,q,mult=a[i],sum=a[i];
        while(j<=n){
            q=*st.lower_bound(j+1);
            len=q-j-1;
            if( mult%k==0 && mult>=sum*k && mult<=(sum+len)*k )
                ans++;           
            sum+=len+a[q];
            if( sum*k/k==sum && mult*a[q]/a[q]==mult)
                mult*=a[q];
            else
                break;
            j=q;
        }
    }
    cout<<ans;
    #ifdef LOCAL
        cout <<endl<< clock () * 1.0 / CLOCKS_PER_SEC << endl;
    #endif
}