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
#define mod 1000000007
#define maxn 2020

using namespace std;

int dp[2][maxn][maxn];
int M[maxn][maxn];

int T[4*maxn];
vector<int> S[maxn];

int n,m;

int idx[2][maxn];
int val[2][maxn];

void update(int init,int fim,int p,int pos){

	if(pos != -1)
		if(init > pos || fim < pos)
			return;

	if(init == fim){
		int ok = 0;
		for(int i=0;i<n;i++)
			if(M[i][init] == '.')
				ok = 1;
		T[p] = ok;
		debug("%d~%d -> %d\n",init,fim,T[p]);
		return;
	}

	int mid = (init+fim)/2;
	
	update(init,mid,2*p,pos);
	update(mid+1,fim,2*p+1,pos);

	int u = max(T[2*p],T[2*p+1]);

	int a = 0, b = -1;

	int a1 = 0, b1 = -1, a2 = 0, b2 = -1;
	int t = 0;

	for(int i=0;i<n;i++){

		int r = dp[1][i][mid+1];
		int l = dp[0][i][mid];

		vector<int> :: iterator it = lower_bound(S[i].begin(),S[i].end(),mid+1);
		if(it != S[i].end())
			r = min(r,*it-1);
		if(it != S[i].begin()){
			it--;
			l = max(l,*it+1);
		}

		l = max(l,init);
		r = min(r,fim);

		while(b1 >= a1 && val[0][b1] <= l)
			b1--;
		b1++;
		val[0][b1] = l;
		idx[0][b1] = i;

		while(b2 >= a2 && val[1][b2] >= r)
			b2--;
		b2++;
		val[1][b2] = r;
		idx[1][b2] = i;

		t++;
		b++;

		int A = val[0][a1], B = val[1][a2];
		while(B-A+1 < t && t > 0){
			if(idx[0][a1] == a)
				a1++;
			if(idx[1][a2] == a)
				a2++;
			A = val[0][a1];
			B = val[1][a2];
			a++;
			t--;
		}

		u = max(u,t);

	}

	T[p] = u;

}

main(){

	int k;
	scanf("%d%d%d",&n,&m,&k);
	getchar();

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)
			M[i][j] = getchar();
		getchar();
	}

	for(int i=0;i<n;i++){

		dp[0][i][0] = (M[i][0] == '.') ? 0 : 1;

		for(int j=1;j<m;j++)
			dp[0][i][j] = (M[i][j] == '.') ? dp[0][i][j-1] : j+1;

		dp[1][i][m-1] = (M[i][m-1] == '.') ? m-1 : m-2;

		for(int j=m-2;j>=0;j--)
			dp[1][i][j] = (M[i][j] == '.') ? dp[1][i][j+1] : j-1;

	}

	update(0,m-1,1,-1);

	while(k--){

		int x,y;
		scanf("%d%d",&x,&y), x--, y--;

		S[x].pb(y);
		int u = S[x].size() - 1;
		while(u > 0 && S[x][u-1] > S[x][u])
			swap(S[x][u],S[x][u-1]), u--;
		M[x][y] = 'X';

		update(0,m-1,1,y);

		printf("%d\n",T[1]);

	}

}