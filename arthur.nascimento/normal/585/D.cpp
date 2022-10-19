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

#define inf 99999999999.
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
#define mod 1000000007
#define maxn 100100

using namespace std;

map <pii,int> mp;

int n;

int x[30];
int y[30];
int z[30];

int ig[30];

int cur[30];

int ans = -999999999;
int ans2 = -999999999;

int A=0, B=0, C=0;

void go(int pos,int a,int b,int c,int k){

	if(k == 0 && pos == n/2){
		if(mp.find(pii(b-a,c-a)) == mp.end())
			mp[pii(b-a,c-a)] = a;
		mp[pii(b-a,c-a)] = max(mp[pii(b-a,c-a)],a);
		return;
	}
	if(k == 1 && pos == n){
		if(mp.find(pii(a-b,a-c)) == mp.end()) return;
		if(a + mp[pii(a-b,a-c)] > ans){
			ans = a + mp[pii(a-b,a-c)];
			debug("put %d (%d %d) eh %d || %d %d %d\n",ans,a-b,a-c,mp[pii(a-b,a-c)],a,b,c);
			for(int i=n/2;i<n;i++)
				cur[i] = ig[i];
		}
		return;
	}
	if(k == 2 && pos == n/2){
		if(a+A == b+B && a+A == c+C && a+A > ans2){
			ans2 = a+A;
			debug("faz %d\n",ans2);
			for(int i=0;i<n/2;i++)
				cur[i] = ig[i];
		}
		return;
	}
	ig[pos] = 2;
	go(pos+1,a+x[pos],b+y[pos],c,k);
	ig[pos] = 0;
	go(pos+1,a,b+y[pos],c+z[pos],k);
	ig[pos] = 1;
	go(pos+1,a+x[pos],b,c+z[pos],k);
}

main(){

		scanf("%d",&n);

		for(int i=0;i<n;i++)
			scanf("%d%d%d",x+i,y+i,z+i);

		go(0,0,0,0,0);
		go(n/2,0,0,0,1);

		debug("ans %d\n",ans);

		if(ans == -999999999){
			printf("Impossible\n");
			return 0;
		}
		A=B=C=0;
		for(int i=n/2;i<n;i++){
			debug("cur[%d] = %d\n",i,cur[i]);
			if(cur[i] == 0) B += y[i], C += z[i];
			if(cur[i] == 1) A += x[i], C += z[i];
			if(cur[i] == 2) A += x[i], B += y[i];
		}

		debug("ABC %d %d %d\n",A,B,C);
		go(0,0,0,0,2);

		for(int i=0;i<n;i++){
			if(cur[i] == 0) printf("MW\n");
			if(cur[i] == 1) printf("LW\n");
			if(cur[i] == 2) printf("LM\n");
		}
}