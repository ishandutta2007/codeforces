// Tima the best
#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
 

#define ll long long                   
#define ld long double                
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define o cout<<"BUG"<<endl;
#define	IOS ios_base::sync_with_stdio(0);
using namespace std;                    
const ll maxn=1e6,inf=1e8,mod=1e9+7,block=200,N=1e6;
int n,k,dp[maxn],d,a[maxn];
set<int>st;
bool get(int l, int r){
	l--,r--;
	if(l>r)
		return 0;
	return ( st.lower_bound(l)!=st.upper_bound(r) );	
}
int main(){
	#ifdef LOCAL
    	freopen ("test.in", "r", stdin);
	//#else
	//	freopen ("dictionary.in", "r", stdin);
	//	freopen ("dictionary.out", "w", stdout);
	#endif       
	scanf("%d%d%d",&n,&k,&d);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	dp[0]=1;
	st.insert(0);
	for(int i=1,j=1;i<=n;i++){
		while( abs(a[i]-a[j])>d )
			j++;	
	    dp[i]=get(j,i-k+1);
	    if(dp[i])
	    	st.insert(i); 
	}
	/*
	for(int i=1;i<=n;i++)
		cout<<a[i]<<" ";cout<<endl;
	for(int i=0;i<=n;i++)
		cout<<dp[i];
	*/

	if(dp[n])
	    cout<<"YES";
	else
		cout<<"NO";
}