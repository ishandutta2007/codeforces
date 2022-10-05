#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")

#define ll long long                   
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define o cout<<"BUG"<<endl;
#define IOS ios_base::sync_with_stdio(0);

using namespace std;                    

const int maxn=5e5+123,LOG=18,inf=1e9,block=450,N=1e7;
const ll INF=1e18;

ll n,m,ans,d,a[maxn],cnt[maxn];
set<int>st;
int main(){
    #ifdef LOCAL
        freopen ("test.in", "r", stdin);
    #endif
    IOS

    cin>>n>>m;
    for(int i=0;i<m;i++)
        st.insert(i);
    for(int i=0;i<n;i++){
        cin>>a[i];
        
        cnt[a[i]%m]++;   

        while(cnt[a[i]%m]>n/m){
            cnt[a[i]%m]--;
            
            if(st.lower_bound(a[i]%m)==st.end())
                d=(*st.lower_bound(0)-a[i]%m+m)%m;
            else
                d=*st.lower_bound(a[i]%m)-a[i]%m;
            ans+=d;
            a[i]+=d;
            
            cnt[a[i]%m]++;
        }

        if(cnt[a[i]%m]==n/m)
            st.erase(a[i]%m);
    }                        
            
    cout<<ans<<endl;
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
}