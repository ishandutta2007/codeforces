#include<iostream>
#include<algorithm>
using namespace std;
const int N=200005;
int n,m,t,a[N];
long long b[N];
long long cal(long long x){
    long long ans=0;
    b[x]=0;
    for(int i=x+1;i<=n;i++){
        long long tmp=b[i-1]+1;    
        ans+=(tmp+a[i]-1)/a[i];
        b[i]=(tmp+a[i]-1)/a[i]*a[i];
    }
    for(int i=x-1;i>0;--i){
        long long tmp=b[i+1]+1;    
        ans+=(tmp+a[i]-1)/a[i];
        b[i]=(tmp+a[i]-1)/a[i]*a[i];
    }
    return ans;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(0); 
    cout.tie(0);
    // cin>>t;
    t=1;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        long long ans=1e18;
        for(int i=1;i<=n;i++)
            ans=min(ans,cal(i));
        cout<<ans<<'\n';
    }
    return 0;
}