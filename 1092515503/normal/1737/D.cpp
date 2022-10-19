/*
Criteria:
1.read the problem carefully; WRITE DOWN SPECIAL CONSTRAINTS when the problem is long;
2.consider special situations/constraints to get observations;
3.think of everything throughout before coding;
4.return to the initial list of notifications after coding.

CONSTRAINTS:

OBSERVATIONS:

OTHER NOTIFICATIONS:

THINK CAREFULLY AND CODE DETERMINEDLY!
*/
#include<bits/stdc++.h>
using namespace std;
int n,m,dis[510][510],X[250100],Y[250100],Z[250010];
long long res;
void mina(){
	scanf("%d%d",&n,&m),res=0x3f3f3f3f3f3f3f3f;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dis[i][j]=0x3f3f3f3f;
	for(int i=1;i<=n;i++)dis[i][i]=0;
	for(int i=1;i<=m;i++)scanf("%d%d%d",&X[i],&Y[i],&Z[i]),dis[X[i]][Y[i]]=dis[Y[i]][X[i]]=1;
	for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	for(int i=1;i<=m;i++){
		int len=min(dis[X[i]][1]+dis[Y[i]][n],dis[X[i]][n]+dis[Y[i]][1]);
		for(int j=1;j<=n;j++)len=min(len,min(dis[X[i]][j],dis[Y[i]][j])+1+dis[j][1]+dis[j][n]);
		// printf("<%d,%d:%d,%d>\n",X[i],Y[i],Z[i],len);
		res=min(res,1ll*(len+1)*Z[i]);
	}
	printf("%lld\n",res);
}
int T;
int main(){scanf("%d",&T);while(T--)mina();return 0;}