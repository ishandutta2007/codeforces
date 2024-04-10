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
int n,k,used[maxn],last,ans;
pair<int,int>a[maxn];
int main(){
    #ifdef LOCAL
        freopen ("test.in", "r", stdin);
    #endif                                     
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i].f;
        a[i].s=i;
    }
    sort(a,a+n);
    for(int i=n-k;i<n;i++){
        used[a[i].s]=1;
        ans+=a[i].f;
    }
    cout<<ans<<endl;
    for(int i=0;i<n;i++){
        if(used[i]==0)
            continue;
        k--;
        if(k==0)
            cout<<n-last<<" ";
        else
            cout<<i-last+1<<" ";
        last=i+1;
    }
}