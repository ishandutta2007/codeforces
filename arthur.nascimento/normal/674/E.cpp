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
#define maxn 500500
#define max3(a,b,c) max(max(a,b),c)
#define mod 1000000007

typedef long long ll;
using namespace std;

double p[101][maxn];
int pai[maxn];

main(){


	int n,q;
	scanf("%d",&q);
	n = 1;
	for(int i=0;i<100;i++)
		p[i][0] = 1;
	
	for(int i=0;i<q;i++){
		int t,a;
		scanf("%d%d",&t,&a), a--;
		if(t == 1){
			int u = n;
			for(int j=0;j<100;j++)
				p[j][u] = 1;
			pai[u] = a;
			double velha, nova;
			int cur = a;

			velha = p[0][a];
			p[0][a] /= 2;
			nova = velha / 2;

		//	printf("cur %d\n",cur);
	//		for(int k=0;k<6;k++) printf(" %d:%.2lf ",k,k?(p[k][cur]):p[k][cur]);
			
			for(int j=1;j<100 && cur != 0;j++){
				cur = pai[cur];
				//velha = p[j][cur];
				double aux = p[j][cur];
				p[j][cur] /= (0.5+velha/2);
				p[j][cur] *= (0.5+nova/2);
				//if(cur == 2 && i == 6)
				//	printf("j %d /= %lf *= %lf ficou %lf\n",j,0.5+velha/2,0.5+nova/2,p[j][cur]);
			//	printf("cur %d ",cur);
				//for(int k=0;k<6;k++) printf(" %d:%.2lf ",k,k?(p[k][cur]):p[k][cur]);
				debug("\n");
				velha = aux;
				nova = p[j][cur];
			}
			n++;
		}
		if(t == 2){
			double E = 0;
			for(int j=1;j<100;j++)
				E += (p[j][a]-p[j-1][a]) * j;
			printf("%.8lf\n",E);
		}

	}

}