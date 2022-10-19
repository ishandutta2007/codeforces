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

#define inf (999999999)
#define pii pair<int,int>
#define pip pair<int,pii>
#define pll pair<long long,long long>
#define pff pair<long double,long double>
#define eps 1e-6
 
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define pb push_back
#define mod 1000000007
#define maxn 100100

using namespace std;

map<int,int> mrk;

int v[100100];

main(){	

		int n,l,x,y;
		scanf("%d%d%d%d",&n,&l,&x,&y);

		for(int i=0;i<n;i++){
			scanf("%d",v+i);
			mrk[v[i]] = 1;
		}

		int ok1=0, ok2=0;

		for(int i=0;i<n;i++){
			if(mrk[v[i]+x])ok1=1;
			if(mrk[v[i]+y])ok2=1;
		}

		int t=0;
		int ans1,ans2;

		for(int i=0;i<n;i++){

			int novo = v[i] + x;
			if(novo <= l) if(mrk[novo+y] || mrk[novo-y])t=1, ans1 = novo, ans2 = (mrk[novo+y] ? (novo+y) : (novo-y));
			novo = v[i] - x;
			if(novo >= 0)if(mrk[novo+y] || mrk[novo-y])t=1, ans1 = novo, ans2 = (mrk[novo+y] ? (novo+y) : (novo-y));

		}

		if(ok1 && ok2){
			printf("0\n");
			return 0;
		}

		if(ok1){
			printf("1\n%d\n",y);
			return 0;
		}

		if(ok2){
			printf("1\n%d\n",x);
			return 0;
		}

		if(t){
			printf("1\n%d\n",ans1);
			return 0;
		}

		printf("2\n%d %d\n",x,y);

}