#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <assert.h>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <string>
#include <utility>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <complex>

#define inf 1000000007
#define pii pair<int,int>
#define pip pair<int,pii>
#define pll pair<long long,long long>
#define pif pair<int,double>
#define eps 1e-7

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define pb push_back
#define maxn 500500
#define mod 1000000007

typedef long long ll;
using namespace std;

char str[maxn];
int v[maxn];
int dp[21][maxn];
int LOG;
int n;
 
int logn;
bool comp(int a,int b){
     
     if(logn == 0)
             return str[a] < str[b];
        
     if(dp[logn-1][a] < dp[logn-1][b])
                      return 1;
     if(dp[logn-1][a] > dp[logn-1][b])
                      return 0;                    
     
     a = min(n,a+(1<<(logn-1)));
     b = min(n,b+(1<<(logn-1)));
     
     if(dp[logn-1][a] < dp[logn-1][b])
                      return 1;
     return 0;
     
}
 
int lcp(int a,int b){
    
    if(b > a)
            swap(a,b);
    
    if(a == b)
         return n-a;
        
    int ret = 0;
    
    
    for(int i=LOG-1;i>=0;i--)
            if(a + ret + (1 << i) <= n)
                    if(dp[i][a+ret] == dp[i][b+ret])
                            ret += (1 << i);
 
    return ret;
    
    
    
}

int sum[maxn];

vector<int> vv[2*maxn];

int rk(int id,int a){

	return upper_bound(vv[id].begin(),vv[id].end(),a)-vv[id].begin();

}

int range(int id,int l,int r){

	int ret = rk(id,r) - rk(id,l-1);
	debug("range[%d] %d..%d = %d\n",id-maxn,l,r,ret);
	return ret;
}
int lg[maxn];

int rmq[21][maxn];

int getmin(int a,int b){
	int sz = b-a+1;
	if(a == b)
		return sum[a];
	sz = lg[sz];
	int r =  min(rmq[sz][a], rmq[sz][b-(1<<sz)+1]);
	debug("min(%d..%d) = %d\n",a,b,r);
	return r;
}
 
main(){
       
	lg[2] = 1;
	for(int i=3;i<maxn;i++){
		lg[i] = lg[i-1];
		if(i == (i&-i))
			lg[i]++;
	}

             	scanf("%d",&n);
             	scanf(" %s",str);
                
                LOG = 1;
                for(int i=1;i<=n;i*=2)LOG++;
                
                
                if(n == 1){
                     printf("0\n");
                     return 0;}
                
                
                
                for(int i=0;i<n;i++)
                        v[i] = i ;
                for(int i=0;i<LOG;i++)
                         dp[i][n] = -1;
                
                for(logn=0;logn<LOG;logn++){
                                           
                                           sort(v,v+n,comp);
                                           
                                           int g = 0;
                                           dp[logn][v[0]] = 0;
                                           
                                           for(int i=1;i<n;i++){
                                                   if(comp(v[i-1],v[i]))g++;
                                                   dp[logn][v[i]] = g;
                                                   }
                                           
                                           }

 	debug("!! %c\n",str[0]);
	sum[0] = (str[0] == '(') ? 1 : -1;
	for(int i=1;i<n;i++)
		sum[i] = sum[i-1] + ((str[i] == '(') ? 1 : -1);

	for(int i=0;i<n;i++)
		rmq[0][i] = sum[i];
	for(int i=1;i<21;i++)
		for(int j=0;j<n;j++)
			rmq[i][j] = min(rmq[i-1][j], rmq[i-1][min(n-1,j+(1<<(i-1)))]);

	for(int i=0;i<n;i++)
		vv[sum[i]+maxn].pb(i);

	ll ans = 0;

	for(int i=0;i<n;i++)
		debug("sum[%d] = %d\n",i,sum[i]);

	for(int i=0;i<n;i++)
		debug("sa[%d] = %d\n",i,v[i]);

	for(int i=0;i<n;i++){

		int l, r;
		l = v[i];
		if(i){
			int a = lcp(v[i],v[i-1]);
			l = v[i] + a;
		}

		int low = v[i], up = n-1;
		while(low != up){
			int mid = (low+up+1)/2;
			if(getmin(v[i],mid) < (v[i]?sum[v[i]-1]:0))
				up = mid-1;
			else
				low = mid;
		}

		r = low;

		debug("i %d l %d r %d\n",i,l,r);

		if(l > r)
			continue;

		ans += range((v[i]?sum[v[i]-1]:0)+maxn,l,r);
	
	}

	cout << ans << endl;

}