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
int n,a[2];
bool f[110][110][2][2];
void mina(){
	scanf("%d",&n),a[0]=a[1]=0;
	for(int i=1,x;i<=n;i++)scanf("%d",&x),a[x&1]++;
	puts(f[a[1]][a[0]][0][0]?"Alice":"Bob");
}
int T;
int main(){
	int N=100;
	f[0][0][0][0]=f[0][0][1][0]=true;
	f[0][0][0][1]=f[0][0][1][1]=false;
	for(int i=0;i<=N;i++)for(int j=0;j<=N;j++)if(i||j){
		if(i)f[i][j][0][0]|=f[i-1][j][1][1];
		if(j)f[i][j][0][0]|=f[i][j-1][1][0];
		if(i)f[i][j][0][1]|=f[i-1][j][1][0];
		if(j)f[i][j][0][1]|=f[i][j-1][1][1];
		f[i][j][1][0]=f[i][j][1][1]=true;
		if(i)f[i][j][1][0]&=f[i-1][j][0][0];
		if(j)f[i][j][1][0]&=f[i][j-1][0][0];
		if(i)f[i][j][1][1]&=f[i-1][j][0][1];
		if(j)f[i][j][1][1]&=f[i][j-1][0][1];
		// printf("<%d,%d:%d>\n",i,j,f[i][j][0][0]);
	}
	scanf("%d",&T);
	while(T--)mina();
	return 0;
}