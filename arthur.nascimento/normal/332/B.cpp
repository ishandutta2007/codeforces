#include <iostream>
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

#define INF (1<<30)
#define pii pair<int,int>
#define eps 1e-9

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

using namespace std;

long long sum[200200];
long long v[200200];
long long sumb[200200];
int bestb[200200];

long long soma(int a,int b){
	if(a)
	return sum[b]-sum[a-1];
	return sum[b];
}



main(){
    
    int n,k;
    scanf("%d%d",&n,&k);

    for(int i=0;i<n;i++)
    	cin >> v[i];

    sum[0] = v[0];
    for(int i=1;i<n;i++)
    	sum[i] = sum[i-1] + v[i];
    	 
    bestb[n-k] = n-k; 
    sumb[n-k] = soma(n-k,n-1);

    for(int i = n-k-1; i>=k; i--){

	bestb[i] = bestb[i+1];
	sumb[i] = sumb[i+1];
	
	if(soma(i,i+k-1) >= sumb[i]){
		sumb[i] = soma(i,i+k-1);
		bestb[i] = i;
		}

    	}

	long long resp = -1;
	int ra,rb;

    for(int i=0;i<=n-2*k;i++){

	if(soma(i,i+k-1) + sumb[i+k] > resp){
		resp = soma(i,i+k-1) + sumb[i+k];
		ra = i;
		rb = bestb[i+k];
		}	

    	}

    printf("%d %d\n",ra+1,rb+1);
    
}