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
#define	IOS ios_base::sync_with_stdio(0);
using namespace std;                    
const ll maxn=1e5+12,inf=1e9,LOG=18,mod=1e9+7;
int n,l,x[maxn],b[maxn],p[maxn];
double dp[maxn];
bool get(double w,bool flag){
	for(int i=1;i<=n;i++)
		dp[i]=1e18;
    for(int i=1;i<=n;i++)
    	for(int j=0;j<i;j++)
    		if(dp[i]>dp[j]-w*b[i]+sqrt( abs(x[i]-x[j]-l) ))
    			p[i]=j,dp[i]=dp[j]-w*b[i]+sqrt(abs(x[i]-x[j]-l));
    if(flag){
    //    cout<<fixed<<w<<endl;
    //	cout<<dp[n]<<endl;
    	int v=n;
    	vector<int>ans;
    	while(v!=0){
    		ans.pb(v);
    		v=p[v];
    	}
    	for(int i=0;i<ans.size();i++)
    		cout<<ans[ans.size()-1-i]<<" ";
    }
    //cout<<fixed<<w<<" "<<dp[n]<<endl;
    return (dp[n]<=0);
}
int main(){
	#ifdef LOCAL
		freopen ("test.in", "r", stdin);
    #endif
    cin>>n>>l;
    for(int i=1;i<=n;i++)
    	cin>>x[i]>>b[i];
   	double l=0,r=1000;
   	for(int i=0;i<100;i++){
   		double m=(l+r)/2.0;
   	    if( !get(m,0) )
   			l=m;
   		else
   			r=m;	
   	}
   	get(l,1);  

}