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
typedef long long ll;
int n,m,num[200100][5];
ll sum[200100][5],res;
vector<int>v[200100];
void dfs(int x,int fa){
	num[x][0]=1,sum[x][0]=0;
	for(auto y:v[x])if(y!=fa){
		dfs(y,x);
		for(int i=0;i<m;i++)for(int j=0;j<m;j++){
			res+=sum[x][i]*num[y][j]+sum[y][j]*num[x][i];
			res+=1ll*((i+j)/m+1)*num[x][i]*num[y][j];
		}
		for(int i=0;i<m;i++)num[x][(i+1)%m]+=num[y][i],sum[x][(i+1)%m]+=sum[y][i];
		sum[x][0]+=num[y][m-1];
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,x,y;i<n;i++)scanf("%d%d",&x,&y),v[x].push_back(y),v[y].push_back(x);
	dfs(1,0);
	printf("%lld\n",res);
	return 0;
}