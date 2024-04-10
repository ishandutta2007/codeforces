#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,sse3,sse4,popcnt,abm,mmx")


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
#define ld double                                                                                                             	
#define ll long long                                                                                                            
#define ull unsigned long long 
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define o cout<<"BUG"<<endl;
#define Bystro ios_base::sync_with_stdio(0), cin.tie(0)

using namespace std;                    

const ll maxn=4100,N=400,inf=1e9,mod=1e9+7;
const ld eps=1e-12;
int pre[4001][4001],x;
int dp[4001][801],c[4001][4001];
int n,k,cur;
short m,opt;
inline int getm( short i1 ,short j1 , short i2 , short j2){
	return pre[i2][j2]+pre[i1-1][j1-1]-pre[i2][j1-1]-pre[i1-1][j2];
}
inline void rec( short l,  short r , short  optl ,short optr ,short k){
	if(l>r)
		return ;
	m=(l+r)/2;
	cur=inf;
	for(short i=optl;i<=min(m,optr);i++){
		x=dp[i][k-1]+c[i+1][m];
		if(x<=cur){
	    	cur=x,opt=i;
		}	
	}	
	dp[m][k]=cur;          
	rec(l,m-1,optl,opt,k);
	rec(m+1,r,opt,optr,k);
	return;
}
inline void read(int &x)
{
   char ch;bool f=0;int a=0;
   while(!((((ch=getchar())>='0')&&(ch<='9'))||(ch=='-')));
  	 if(ch!='-')a*=10,a+=ch-'0';else f=1;
   while(((ch=getchar())>='0')&&(ch<='9'))a*=10,a+=ch-'0';
  	 if(f)a=-a;x=a;
}
   
signed main(){
	//IO
	scanf("%d%d",&n,&k);
	for(short i=1;i<=n;i++){
		for(short j=1;j<=n;j++){
			read(x);
			pre[i][j]=pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1]+x;
		}
	}

	for(short i=1;i<=n;i++)
		for(short j=i+1;j<=n;j++)
			c[i][j]=c[i][j-1]+getm(i,j,j,j);
	
	for(short i=1;i<=n;i++)
		dp[i][1]=c[1][i];
	for(short j=2;j<=k;j++)
		rec(j,n,j-1,n,j);

	printf("%d",dp[n][k]);
}