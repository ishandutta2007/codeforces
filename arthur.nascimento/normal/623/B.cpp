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
#define eps 1e-9


#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define pb push_back
#define mod 1000000007
#define maxn 1001000
using namespace std;
typedef long long ll;

int v[maxn];

long long t1[maxn];
long long t2[maxn];

set<int> P;

int fact(int a){

	for(long long i=2;i*i<=a;i++){
		if(a%i == 0){
			P.insert(i);
			while(a%i == 0)
				a /= i;
		}
	}

	if(a != 1)
		P.insert(a);

}

main(){

	int n,a,b;
	scanf("%d%d%d",&n,&a,&b);

	for(int i=0;i<n;i++)
		scanf("%d",v+i);

	fact(v[0]);
	fact(v[0]-1);
	fact(v[0]+1);
	fact(v[n-1]);
	fact(v[n-1]+1);
	fact(v[n-1]-1);

	long long ans = 100000000000000000LL;

	for(set<int> :: iterator it = P.begin(); it != P.end(); it++){

		int p = *it;
		debug("p %d\n",p);

		int qnt = 0;
		int has = 0;
		if(v[0]%p == 0)
			t1[0] = 0;
		else
			t1[0] = min(a,b), qnt++;
		if(v[0]%p != 0 && v[0]%p != 1 && v[0]%p != p-1)
			has = 1, t1[0] = a;
		debug("t1[0] %d\n",t1[0]);
		for(int i=1;i<n;i++){
			int u = v[i]%p;
			if(u != 0 && u != 1 && u != p-1)
				has = 1;
			if(u)
				qnt++;
			if(has)
				t1[i] = a + t1[i-1];
			else {
				t1[i] = a + t1[i-1];
				t1[i] = min(t1[i], (long long)b * qnt);
			}
			debug("t1[%d] %d\n",i,t1[i]);
		}

		qnt = has = 0;
		if(v[n-1]%p == 0)
			t2[n-1] = 0;
		else
			t2[n-1] = min(a,b), qnt++;
		if(v[n-1]%p != 0 && v[n-1]%p != 1 && v[n-1]%p != p-1)
			has = 1, t2[n-1] = a;
		debug("t2[%d] %d\n",n-1,t2[n-1]);
		for(int i=n-2;i>=0;i--){
			int u = v[i]%p;
			if(u != 0 && u != 1 && u != p-1)
				has = 1;
			if(u)
				qnt++;
			if(has)
				t2[i] = a + t2[i+1];
			else {
				t2[i] = a + t2[i+1];
				t2[i] = min(t2[i], (long long)b * qnt);
			}
			debug("t2[%d] %d\n",i,t2[i]);
		}

		for(int i=0;i<n-1;i++)
			ans = min(ans, t1[i]+t2[i+1]);

	}
	if(n == 1)
		ans = 0;
	cout << ans << endl;

}