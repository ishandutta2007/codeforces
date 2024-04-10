#include <bits/stdc++.h>

#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")

#define ll long long                   
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define o cout<<"BUG"<<endl;
#define	IOS ios_base::sync_with_stdio(0);
using namespace std;                    
const ll maxn=2e6+123,inf=1e18,LOG=18,block=450;
int n,k,cnt[maxn],cur,x,ans,up[maxn];
int main(){
    #ifdef LOCAL                         
		freopen ("test.in", "r", stdin);
    #endif
    IOS
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>x;
		cnt[x]++;
    }
	for(int i=1e6;i>=1;i--){ 	
		cur+=up[i];
		if(!cur)
			ans+=cnt[i];
		up[i-1]+=cnt[i];  
		if(i-k-1>=0)
			up[i-k-1]-=cnt[i];
	}
	cout<<ans;
}