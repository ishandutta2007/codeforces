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
 
using namespace std;

char a[110];
char b[110];
char c[110];
int na,nb,nc;

int pi[110];

struct tr {
	int a,b,c;
	tr(int a=0,int b=0,int c=0):a(a),b(b),c(c){}
};

int dp[110][110][110];
tr next[110][110][110];
char ans[110][110][110];

int get(int pa,int pb,int pc){

	if(dp[pa][pb][pc]+1)
		return dp[pa][pb][pc];

	if(pc == nc)
		return -999999;

	if(pa == na && pb == nb)
		return 0;

	if(pa > na || pb > nb)
		return -999999;

	ans[pa][pb][pc] = 0;

	if(get(pa+1,pb,pc) > get(pa,pb+1,pc))
			
		dp[pa][pb][pc] = get(pa+1,pb,pc),
		next[pa][pb][pc] = tr(pa+1,pb,pc),
		ans[pa][pb][pc] = 0;

	else 

		dp[pa][pb][pc] = get(pa,pb+1,pc),
		next[pa][pb][pc] = tr(pa,pb+1,pc),
		ans[pa][pb][pc] = 0;
				
	

	if(a[pa] == b[pb]){

			int k = pc - 1;
			
			while(k != -1 && c[k+1] != a[pa])
				k = pi[k];

			if(c[k+1] == a[pa])
				k++;

			if(1+get(pa+1,pb+1,k+1) > dp[pa][pb][pc])

				dp[pa][pb][pc] = 1 + get(pa+1,pb+1,k+1),
				next[pa][pb][pc] = tr(pa+1,pb+1,k+1),
				ans[pa][pb][pc] = a[pa];
			

		}

	return dp[pa][pb][pc] = max(dp[pa][pb][pc],0);

}


main(){

		scanf(" %s %s %s",a,b,c);

		na = strlen(a);
		nb = strlen(b);
		nc = strlen(c);

		pi[0] = -1;

		for(int i=1;i<nc;i++){

			int k = pi[i-1];

			while(k != -1 && c[k+1] != c[i])
				k = pi[k];

			if(c[k+1] == c[i])
				k++;

			pi[i] = k;
	
		}

		memset(dp,-1,sizeof(dp));

		get(0,0,0);

		for(tr i (0,0,0); get(i.a,i.b,i.c) > 0; i = next[i.a][i.b][i.c])
			if(ans[i.a][i.b][i.c])
				printf("%c",ans[i.a][i.b][i.c]);

		if(get(0,0,0) == 0)
			printf("0");

		printf("\n");

	}