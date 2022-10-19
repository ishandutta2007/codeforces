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
#define pll pair<long long,long long>
#define eps 1e-9
 
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define mod 1000000007
 
using namespace std;

long long fat[100100];

long long exp(long long a,int b,bool f=1){

	if(f)
		debug("%I64d^%d\n",a,b);
		
	if(b == 0)
		return 1;

	if(b == 1)
		return a;

	long long k = exp(a,b/2,0);

	k = (k*k)%mod;

	if(b%2)
		k = (k*a)%mod;

	return k;

}

long long inv(long long n){
	return exp(n%mod,mod-2,0);}

long long C(int n,int k){
	debug("C %d %d\n",n,k);
	if(k > n)
		return 0;
	return (fat[n] * inv(fat[k] * fat[n-k]))%mod;}

int pos[100100];
int val[100100];

int qnt = 0;

main(){

		fat[0] = 1;

		for(int i=1;i<=100000;i++)
			fat[i] = (fat[i-1]*i) % mod;


		int n;
		scanf("%d",&n);

		for(int i=0;i<n;i++){
			int a;
			scanf("%d",&a);
			if(a)
				pos[qnt] = i+1,
				val[qnt] = a,
				qnt++;
		}

		int p1 = 0;
		int p2 = qnt-1;
		int t1 = 1;
		int t2 = n;

		if(qnt == 0){
			printf("%d\n",exp(2,n-1));
			return 0;
			}

		long long ans = 1;

		while(p1 != p2){

			debug("%d ~ %d\n",t1,t2);

			int y = p1;
			if(val[p2] > val[p1])
				y = p2;

			ans = (ans * C(t2-t1+1-val[y], (y == p2) ? t2 - pos[y] : pos[y] - t1)) % mod;

			if(y == p1)
				t1 = 1 + pos[p1],
				t2 -= (t2-t1+1-val[y]-(pos[y]-t1)),
				p1++;
			else
				t2 = pos[p2] - 1,
				t1 += (t2-t1+1-val[y]-(t2-pos[y])),
				p2--;

			if(pos[p1] < t1 || pos[p2] > t2){
				debug("!");
				ans = 0;}

			}

		debug("%d ~ %d %I64d\n",t1,t2,ans);
		debug("t1=%d t2=%d vap1=%d\n",t1,t2,val[p1]);

		if(val[p1] == 1)
		
			ans = (ans * C(t2-t1,pos[p1]-t1)) % mod;

		else 

			ans = ans * (   (C(t2-t1+1-val[p1], pos[p1] - t1) * exp(2,val[p1]-2)  )%mod + (C(t2-t1+1-val[p1], t2 - pos[p1])*exp(2,val[p1]-2))%mod)%mod;
	
		printf("%I64d\n",ans);

	}