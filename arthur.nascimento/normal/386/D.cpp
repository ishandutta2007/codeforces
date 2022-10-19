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

vector<int> edge[80][30];

int dist[80][80][80];

int cor[80][80];

pii last[80][80][80];


struct tr {
	int a[3];
	tr(int A=0,int B=0,int C=0){
		a[0] = A;
		a[1] = B;
		a[2] = C;
	}
}

hh[80][80][80];

main(){

		int n,a,b,c;
		scanf("%d%d%d%d",&n,&a,&b,&c);
		a--,b--,c--;

		for(int i=0;i<n;i++){

			cor[i][i] = 27;
			char ch;

			for(int j=0;j<n;j++){
				scanf(" %c",&ch);
				
				if(ch=='*')
					continue;
				cor[i][j] = ch-'a';
				
				edge[i][ch-'a'].push_back(j);

				}

			}

		queue<tr> Q;
		Q.push(tr(0,1,2));

		dist[0][1][2] = dist[0][2][1] = dist[1][0][2] = dist[1][2][0] = dist[2][1][0] = dist[2][0][1] = 1;

		while(!Q.empty()){

			
			tr k = Q.front();
			Q.pop();
			debug("%d %d %d d=%d\n",k.a[0], k.a[1], k.a[2], dist[k.a[0]][k.a[1]][k.a[2]]);
				
			for(int i=0;i<3;i++){

				int A = i?0:1;
				int B = (i==1)?2:(i==2)?1:2;

				int u = cor[k.a[A]][k.a[B]];
				

				A = k.a[A];
				B = k.a[B];

				for(vector<int> :: iterator it = edge[k.a[i]][u].begin(); it < edge[k.a[i]][u].end(); it++){
					if(!dist[*it][A][B]){
						if(*it == A || *it == B)
							continue;
						Q.push(tr(*it,A,B));
						debug("\t%d %d %d\n",*it,A,B);
						dist[*it][A][B]=dist[*it][B][A]=dist[A][*it][B]=dist[A][B][*it]=dist[B][*it][A]=dist[B][A][*it] = 1 + dist[k.a[0]][k.a[1]][k.a[2]];
						last[*it][A][B]=last[*it][B][A]=last[A][*it][B]=last[A][B][*it]=last[B][*it][A]=last[B][A][*it] = pii(k.a[i], *it);
						hh[*it][A][B]=hh[*it][B][A]=hh[A][*it][B]=hh[A][B][*it]=hh[B][*it][A]=hh[B][A][*it] = tr(k.a[0],k.a[1],k.a[2]);
						}
					}


				}}
			
			if(dist[a][b][c] == 0)
				printf("-1\n");
			else {
				printf("%d\n",dist[a][b][c]-1);
				int A=a, B=b, C=c;
				while(dist[A][B][C] != 1){
					printf("%d %d\n",last[A][B][C].second+1, last[A][B][C].first+1);
					int A_ = hh[A][B][C].a[0];
					int B_ = hh[A][B][C].a[1];
					int C_ = hh[A][B][C].a[2];
					A=A_;
					B=B_;
					C=C_;
					}
			}

			}