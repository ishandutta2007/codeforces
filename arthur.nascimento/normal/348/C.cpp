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

vector<int> V[100100];

int tipo[100100];
long long val[100100];
long long sz[100100];
int idx[100100];

int inter[100100][350];

int last[100100];

int h[350];
long long hl[350];

long long ll[100100];

long long v[100100];

main(){

		int n,m,q,H=0,cur=0;
		scanf("%d%d%d",&n,&m,&q);

		for(int i=0;i<n;i++)
			scanf("%I64d",v+i);

		for(int i=0;i<m;i++){

			scanf("%I64d",sz+i);
			if(sz[i] >= sqrt(n))
				tipo[i] = 1,
				idx[i] = H,
				h[H++] = i;

			for(int j=0;j<sz[i];j++){
				int k;
				scanf("%d",&k);
				k--;
				val[i] += v[k];
				V[i].push_back(k);
				}
			}

		for(int i=0;i<H;i++){

			cur++;
			for(int j=0;j<V[h[i]].size();j++)
				last[V[h[i]][j]] = cur;

			for(int j=0;j<m;j++)
				for(int k=0;k<V[j].size();k++)
					if(last[V[j][k]] == cur)
						inter[j][i]++;

			}


		for(int i=0;i<q;i++){

			char ch;
			scanf(" %c",&ch);

			if(ch == '?'){

				int s;
				scanf("%d",&s);
				s--;

				if(tipo[s] == 1)
					printf("%I64d\n",val[s]);
					
				else {

					long long ans = val[s];
					
					for(int j=0;j<V[s].size();j++)
						ans += ll[V[s][j]];

 					debug("ans = %I64d\n",ans);
					for(int j=0;j<H;j++)
						ans += hl[j] * inter[s][j];

					printf("%I64d\n",ans);

					}

				}

			if(ch == '+'){

				long long s,x;
				scanf("%I64d%I64d",&s,&x);
				s--;

				if(tipo[s] == 0){

					debug("!");
					for(int j=0;j<V[s].size();j++)
						ll[V[s][j]] += x;

					for(int j=0;j<H;j++)
						val[h[j]] += x * inter[s][j];

					}

				else {

					hl[idx[s]] += x;

					for(int j=0;j<H;j++)
						val[h[j]] += x * inter[s][j];
						

					}


				}

			}



}