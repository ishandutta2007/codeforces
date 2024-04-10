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
#define maxn 2505

#define count blergh

typedef long long ll;
using namespace std;

char M[maxn][maxn];

int next0[maxn][maxn];
int prev0[maxn][maxn];

int next[maxn];
int prev[maxn];
int inside[maxn];
int lefty[maxn];
int range[maxn];

int rsum[maxn];

ll contr[maxn];

pii lista[maxn*7];
pii lista2[maxn*7];

int rep[maxn];

int dpL[maxn];
int dpR[maxn];

ll count(int n,int m,int k){

	if(k == -1)
		return 0;

	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			prev0[i][j] = -1, next0[i][j] = m;

	ll ans = 0;

	int len2 = 0;

	for(int i=0;i<n;i++){

		debug("i = %d\n",i);

		int len = 0;

		for(int j=0;j<m;j++)
			rep[j] = 0;

		for(int j=0;j<m;j++)
			if(M[i][j] == '1')
				lista[len++] = pii(i,j), rep[j]++;

		for(int j=0;j<len2;j++){
			if(rep[lista2[j].second] == k+1)
				continue;
			rep[lista2[j].second]++;
			lista[len++] = lista2[j];
		}

		len2 = len;

		for(int j=0;j<len;j++)
			lista2[j] = lista[j];
		
		dpL[0] = -1;
		if(M[i][0] == '1')
			dpL[0] = 0;

		for(int j=1;j<m;j++){
			dpL[j] = dpL[j-1];
			if(M[i][j] == '1')
				dpL[j] = j;
		}

		dpR[m-1] = m;
		if(M[i][m-1] == '1')
			dpR[m-1] = m-1;

		for(int j=m-2;j>=0;j--){
			dpR[j] = dpR[j+1];
			if(M[i][j] == '1')
				dpR[j] = j;
		}

		ll sum = 0;
		int free = m;

		for(int j=0;j<=m;j++)
			inside[j] = contr[j] = 0;

		int p = i+1;
		if(len)
			p = i - lista[0].first;
		ans += (ll) p * (m*(m+1))/2;
		debug("++ %d\n",p * (m*(m+1))/2);

		for(int u=0;u<len;u++){

			int x = lista[u].first;
			int y = lista[u].second;

			debug("+ (%d;%d)\n",x,y);

			if(!inside[y]){

				int r = next0[x][y];
				if(x != i && y != m-1)
					r = min(r, dpR[y+1]);

				int l = prev0[x][y];
				if(x != i && y)
					l = max(l, dpL[y-1]);
				if(x == i && y != 0)
					l = dpL[y-1];

				debug("l %d r %d\n",l,r);

				next[y] = r;
				if(r != m)
					prev[r] = y;

				prev[y] = l;
				if(l != -1)
					next[l] = y;

				if(r == m){
					free = m-y-1;
					prev[m] = y;
				}

				next0[x][y] = r;
				prev0[x][y] = l;

			}

			inside[y]++;

			for(int j=(next[y]==m)?y:next[y], t=0; j != -1 && t <= k+1; t++){

				sum -= contr[j];

				if(next[j] == m){
				
					if(inside[j] == k+1)
						range[j] = j;
					else
						range[j] = m;
						
					rsum[j] = inside[j];
				}
				
				else {
				
					range[j] = range[next[j]];
					rsum[j] = rsum[next[j]] + inside[j];
					debug("-- j %d range %d rsum %d\n",j,range[j],rsum[j]);

					while(range[j] != j && rsum[j]-inside[range[j]] > k){
						rsum[j] -= inside[range[j]];
						range[j] = prev[range[j]];
					}

				}

				debug("range[%d] := %d\n",j,range[j]);
				debug("rsum[%d] = %d\n",j,rsum[j]);

				lefty[j] = j - prev[j] - 1;

				debug("lefty[%d] = %d\n",j,lefty[j]);

				contr[j] = (ll) (1+lefty[j]) * (range[j]-j) + (ll) (lefty[j]*(lefty[j]+1))/2;

				sum += contr[j];

				j = prev[j];

			}

			ll add;
			if(u == len-1)
				add = (sum + (free*(free+1))/2) * (x+1);
			else
				add = (sum + (free*(free+1))/2) * (x-lista[u+1].first);
			ans += add;
			debug("+%d\n",(int)add);
		}

	}

	return ans;

}

main(){

	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);

	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			scanf(" %c",&M[i][j]);

	cout << count(n,m,k) - count(n,m,k-1) << endl;

}