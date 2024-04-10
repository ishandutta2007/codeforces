#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <assert.h>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <utility>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
 
#define inf (999999999999LL)
#define pii pair<int,int>
#define pip pair<int,pii>
#define pll pair<long long,long long>
#define eps 1e-8
  
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif
 
#define pb push_back    
#define maxn 1001000			
#define mod 1000000007
 
using namespace std;

int v[maxn];
int res[maxn];

int smooth(int a,int b){
	debug("smooth %d %d\n",a,b);
	if(a > b) return -1;
	if(v[a-1] == v[b+1]){
		for(int i=a;i<=b;i++)
			res[i] = v[a-1];
		int ret = (b-a+1)/2;
		if(a%2 == b%2 && v[(a+b)/2] == v[a-1]) ret++;
		if(a == b) return (v[a]==res[a])?0:1;
		return ret;
	}
	for(int i=a;i<=(a+b)/2;i++)
		res[i] = v[a-1];
	for(int i=(a+b)/2+1;i<=b;i++)
		res[i] = v[b+1];
	int t = (b-a+1);
	int r = 0;
	if(a%2 == b%2){
		if((t-1)%4 == 0)
			res[(a+b)/2] = v[(a+b)/2];
		else
			res[(a+b)/2] = v[(a+b)/2]^1, r++;
	}
	return (b-a+1)/2;
	
}

main(){
		
		int n;
		scanf("%d",&n);
		
		for(int i=0;i<n;i++)
			scanf("%d",v+i), res[i] = v[i];
		
		int pos = 0, ans = 0;
		for(int i=1;i<n-1;i++){
			if(v[i] == v[i-1]){
				ans = max(ans,smooth(pos+1,i-1));
				pos = i;
			}
		}
		ans = max(ans,smooth(pos+1,n-2));
		
		printf("%d\n",ans);
		
		for(int i=0;i<n;i++)
			printf("%d ",res[i]);
		printf("\n");
		
}