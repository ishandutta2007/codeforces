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
#define eps 1e-5

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define pb push_back
#define mod 1000000007
#define maxn 5050

using namespace std;

struct node {
	int id;
	int nxt[2];
}

T[maxn*maxn/2];

char s[maxn];

int lbl[maxn][maxn];
int cnt;

int mini[maxn][maxn];
int dp[maxn][maxn];

void dfs(int x){
	T[x].id = cnt++;
	if(T[x].nxt[0])
		dfs(T[x].nxt[0]);
	if(T[x].nxt[1])
		dfs(T[x].nxt[1]);
}


main(){

	scanf(" %s",s);
	int n = strlen(s);

	for(int i=0;i<n;i++)
		s[i] -= '0';

	int qnt = 1;

	for(int i=0;i<n;i++){
		int ptr = 0;
		for(int j=i;j<n;j++){
			if(T[ptr].nxt[s[j]] == 0){
				T[ptr].nxt[s[j]] = qnt;
				qnt++;
			}
			ptr = T[ptr].nxt[s[j]];
		}
	}

	dfs(0);

	for(int i=0;i<n;i++){
		int ptr = 0;
		for(int j=i;j<n;j++){
			ptr = T[ptr].nxt[s[j]];
			lbl[i][j] = T[ptr].id;
		}
	}

	for(int i=0;i<n;i++)
		mini[0][i] = 1, dp[0][i] = 1;

	for(int i=1;i<n;i++){

		int sum = 0, opt = inf;
		int cur = i;
		
		for(int j=i;j<n;j++){

			int a = i - (j-i);
			if(a < 0) a = 0;
			if(a > 0)
				if(lbl[a-1][i-1] <= lbl[i][j])
					a--;
	
			while(cur > a){
				cur--;
				sum = (sum+dp[cur][i-1]) % mod;
				opt = min(opt,mini[cur][i-1]);
			}

			if(s[i] == 0 || opt == inf)
				mini[i][j] = inf;
			else
				dp[i][j] = sum, mini[i][j] = 1+opt;

		}

	}

	int foi = 0;
	int ans = 0, best = mod;

	for(int i=0;i<n;i++)
		ans = (ans+dp[i][n-1])%mod;

	for(int i=n-1;i>=max(n-20,0);i--){
		if(mini[i][n-1] == inf)
			continue;
		int u = 0;
		for(int j=i;j<n;j++)
			u = 2*u+s[j];
		foi = 1;
		debug("i %d -> %d+%d\n",i,u,mini[i][n-1]);
		best = min(best,(u+mini[i][n-1])%mod);
	}

	for(int i=n-20;i>=0 && !foi;i--){
		if(mini[i][n-1] == inf)
			continue;
		int u = 0;
		for(int j=i;j<n;j++)
			u = (2*u+s[j]) % mod;
		foi = 1;
		best = (u+mini[i][n-1]) % mod;
	}

	printf("%d\n%d\n",ans,best);

}