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
const ll maxn=4e5+123,inf=1e9,INF=1e15+123,N=1e6,mod=95542721;
using namespace std;    
int n=1,a,b;
ll sum[maxn][20],up1[maxn][20],up2[maxn][20],mx[maxn][20];
ll pr[maxn],c[maxn];
ll type,p,q,last;
void add(int p,ll w){
	n++;
	pr[n]=p;
	c[n]=w;
	up1[n][0]=p;
	sum[n][0]=c[n];
	for(int i=1;i<20;i++)
		up1[n][i]=up1[ up1[n][i-1] ][i-1];
	mx[n][0]=c[n];
	for(int i=1;i<20;i++)
		mx[n][i]=max(mx[n][i-1],mx[ up1[n][i-1] ][i-1]);
	if(mx[p][19]>=c[n]){
		int u=p;
		for(int i=19;i>=0;i--){
			if( mx[u][i]<c[n] ){
				u=up1[u][i];    
			}
		}       
		up2[n][0]=u;              
	}
	for(int i=1;i<20;i++)
		up2[n][i]=up2[ up2[n][i-1] ][i-1];
	for(int i=1;i<20;i++)
		sum[n][i]=sum[n][i-1]+sum[ up2[n][i-1] ][i-1];
	return;
}
ll get( int v, ll x){
	last=0;
	for(int i=19;i>=0;i--){
		if(up2[v][i]!=0 && sum[v][i]<=x){
			x=x-sum[v][i];
			v=up2[v][i];
			last+=(1<<i);
		}
	}
	if(c[v]<=x)
		last++;
	return last;
}
int main(){          	
//	IO
	c[0]=INF;
	for(int i=0;i<20;i++)
		sum[0][i]=INF,mx[0][i]=-INF;
	int Q;
	cin>>Q;
	while(Q--){
		scanf("%lld%lld%lld",&type,&p,&q);
	    ll r=p^last,w=q^last;
		if(type==1)
			add(r,w);
		else
			printf("%lld\n",get(r,w));
	}
}