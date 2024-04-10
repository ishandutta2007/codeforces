#include <bits/stdc++.h>

#define ll long long                   
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define IOS ios_base::sync_with_stdio(0);

using namespace std;                    

const ll maxn=3e5+123,inf=1e18,mod=1e9+7;
ll n,a[maxn],b[maxn],a1[maxn],a2[maxn],b1[maxn],b2[maxn],pa[maxn],pb[maxn],ans,cur;
int main(){
    #ifdef LOCAL
        freopen ("test.in", "r", stdin);
    #endif
    IOS
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        pa[i]=pa[i-1]+a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
        pb[i]=pb[i-1]+b[i];
    }
    for(int i=n;i>=1;i--){          
        a1[i]=a1[i+1]+(pa[n]-pa[i]);
        b1[i]=b1[i+1]+(pb[n]-pb[i]);    
        a2[i]=a2[i+1]+a[i]*(n-i);
        b2[i]=b2[i+1]+b[i]*(n-i);
    }
    ans=pb[n]*n+a1[1]+b2[1];
    for(int i=1;i<=n;i++){
        if(i%2==1){
            cur+=a[i]*(2*i-2)+b[i]*(2*i-1);
        }else{
            cur+=b[i]*(2*i-2)+a[i]*(2*i-1);
        }
       
        if(i%2==1){
            ans=max(ans,cur+(pa[n]-pa[i] )*(2*i+n-i)+(pb[n]-pb[i])*(2*i)+a2[i+1]+b1[i+1]);
        }else{
            ans=max(ans,cur+(pa[n]-pa[i] )*(2*i)+(pb[n]-pb[i])*(2*i+n-i)+a1[i+1]+b2[i+1]);
        }
       // cout<<i<<" "<<cur<<" "<<ans<<endl;
    }
    cout<<ans;               
}