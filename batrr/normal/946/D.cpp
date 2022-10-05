#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
 
#include <cstring>
#include <string>
#include <cmath>    
#include <algorithm>
 
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>                                                      
#include <stack>
#include <list>
#include <deque>                                              
 
#include <ctime>
#include <cassert> 
 
#define nm "C" 
#define stdi freopen(nm".in","r",stdin);
#define stdo freopen(nm".out","w",stdout);
#define IO stdi stdo                   
#define ld long double                                                                                                             	
#define ll long long                                                                                                            
#define ull unsigned long long 
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define o cout<<"BUG"<<endl;
#define Bystro ios_base::sync_with_stdio(0), cin.tie(0)

using namespace std;                    
const ll maxn=1e5+123,N=1e4+12,inf=1e9,mod=1e9+7,INF=1e18,block=1000;
const ld eps=1e-12,PI=3.141592653589793238462643383279;
string s[501];
int n,m,k,dp[560][560],tmp[550];
int main(){
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		cin>>s[i];
	for(int i=1;i<=n;i++){
		vector<int>v;
		for(int j=0;j<m;j++)
			if(s[i][j]=='1')
				v.pb(j+1);                                 
		
		for(int q=0;q<=k;q++)
			dp[i][q]=inf,tmp[q]=inf;
		
		tmp[v.size()]=0;
		
		for(int l=0;l<v.size();l++)
			for(int r=l;r<v.size();r++)
				tmp[v.size()-(r-l+1)]=min(tmp[v.size()-(r-l+1)],v[r]-v[l]+1);
		
		for(int q=0;q<=k;q++)
			for(int w=0;q+w<=k;w++)	
				dp[i][q+w]=min(dp[i][q+w],dp[i-1][q]+tmp[w]);

	}
	for(int i=1;i<=k;i++)
		dp[n][i]=min(dp[n][i],dp[n][i-1]);
	cout<<dp[n][k];     
}