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
ll n,m,cnt[maxn];
int main(){
    #ifdef LOCAL
        freopen ("test.in", "r", stdin);
    #endif                                     
    cin>>n>>m;
    for(int i=n;i>=1;i--){
        cnt[i]=n/i;
        cnt[i]=cnt[i]*(cnt[i]-1)/2;
        for(int j=i+i;j<=n;j+=i)
            cnt[i]-=cnt[j];
    }
    if(cnt[1]<m || m<n-1)
        cout<<"Impossible",exit(0);
    cout<<"Possible"<<endl;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++){
            if( __gcd(i,j)==1 ){
                cout<<i<<" "<<j<<endl;
                m--;
                if(m==0)
                    exit(0);
            }
        }
}