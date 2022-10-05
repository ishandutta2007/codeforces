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
#define Bystro ios_base::sync_with_stdio(0);
using namespace std;                    
const ll maxn=700,mod=1e9+7;       
int n,dp[700][700],l[maxn],r[maxn],cur,t[maxn][maxn];
char ans[2000];
pair< int , int > p[700][700];
void rec(int l, int r){
	if(l==r){
		ans[++cur]='(';
		ans[++cur]=')';
		return ;
	}
	int pl=p[l][r].f,pr=p[l][r].s;
	if(t[l][r]==1){
		ans[++cur]='(';
		rec(l+1,r);
		ans[++cur]=')';	
	}

	if(t[l][r]==3){
		ans[++cur]='(';
		ans[++cur]=')';	
		rec(l+1,r);
	}

	if(t[l][r]==2){
		ans[++cur]='(';
		rec(pl,pr);
		ans[++cur]=')';	
		rec(pr+1,r);
	}

}
int main(){	
	Bystro
	cin>>n;                                        
	for(int i=1;i<=n;i++)
		cin>>l[i]>>r[i];
	for(int i=1;i<=n;i++)
		if(l[i]<=1 && 1<=r[i])
			dp[i][i]=1;
	
	for(int len=2;len<=n;len++){
		for(int i=1;i+len-1<=n;i++){
			int x;
			x=(len-1)*2+1;
			if(l[i]<=x && x<=r[i] && dp[i+1][i+len-1]){
				dp[i][i+len-1]=1;  
				p[i][i+len-1]=mp(i+1,i+len-1);
				t[i][i+len-1]=1;
			}

			for(int j=i+1;j<i+len-1;j++){
				x=(j-i)*2+1;
				if(l[i]<=x && x<=r[i] && dp[i+1][j] && dp[j+1][i+len-1] ){
					dp[i][i+len-1]=1;  
					p[i][i+len-1]=mp(i+1,j);
					t[i][i+len-1]=2;
				}
			}
		
		    x=1;
		    if(l[i]<=x && x<=r[i] && dp[i+1][i+len-1] ){
				dp[i][i+len-1]=1;  
				p[i][i+len-1]=mp(i,i);
				t[i][i+len-1]=3;
			
			}
			
		}
	}               /*
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			cout<<dp[i][j];
		cout<<endl;
	}             */          
	if(dp[1][n]==0){
		cout<<"IMPOSSIBLE";
		return 0;
	}
	rec(1,n);
	for(int i=1;i<=2*n;i++)
		cout<<ans[i];
}