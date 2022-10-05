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
int u,v,n,ansv,cnt[maxn];
int main(){
	#ifdef LOCAL
		freopen ("test.in", "r", stdin);
	//#else
	//	freopen ("headmasters.in", "r", stdin);
	//	freopen ("headmasters.out", "w", stdout);
    #endif        
    cin>>n;
    for(int i=1;i<n;i++){
    	int u,v;
        cin>>u>>v;
    	cnt[v]++;
    	cnt[u]++;
    }
    for(int i=1;i<=n;i++){
    	if( cnt[i]>2 ){
    		if(ansv==0)
    			ansv=i;
    		else
    			return cout<<"No",0;
    	}
    }
    if(ansv==0)
    	ansv=1;
   	vector<int>ans;
   	for(int i=1;i<=n;i++)
   		if(i!=ansv && cnt[i]==1)
   			ans.pb(i);
  	cout<<"Yes"<<endl;
  	cout<<ans.size()<<endl;
  	for(int i=0;i<ans.size();i++)
  		cout<<ans[i]<<" "<<ansv<<endl;          
}