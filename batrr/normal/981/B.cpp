// Tima the best
#include <bits/stdc++.h>
/*
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
*/                       
#define ll long long   
#define ull unsigned long long                   
#define ld long double                
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define o cout<<"BUG"<<endl;
#define	IOS ios_base::sync_with_stdio(0);
using namespace std;                    
const ll maxn=1e5+123,inf=1e9,mod=1e9+7;
ll n,a,x,ans;
map<ll,ll>cost;    
int main(){
	#ifdef LOCAL
		freopen ("test.in", "r", stdin);
	//#else
	//	freopen ("headmasters.in", "r", stdin);
	//	freopen ("headmasters.out", "w", stdout);
    #endif        
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a>>x;
    	cost[a]=x;
    	ans+=x;
    }
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a>>x;
    	ans=max(ans,ans-cost[a]+x);
    }
    cout<<ans;
}