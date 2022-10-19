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
const int mod=1e9+7;
int n,nex[5010][26],f[5010][5010],lim[5010],C[5010][5010],g[5010],res;
char s[5010];
void ADD(int&x,int y){if((x+=y)>=mod)x-=mod;}
int main(){
	scanf("%d%s",&n,s+1);
	for(int i=0;i<=n;i++)C[i][0]=1;
	for(int i=1;i<=n;i++)for(int j=1;j<=i;j++)C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	for(int i=0;i<26;i++)nex[n][i]=n+1;
	for(int i=n-1;i>=0;i--){
		for(int j=0;j<26;j++)nex[i][j]=nex[i+1][j];
		nex[i][s[i+1]-'a']=i+1;
		// for(int j=0;j<26;j++)printf("%d ",nex[i][j]);puts("");
	}
	for(int i=0;i<26;i++)f[nex[0][i]][1]++,lim[nex[0][i]]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<26;j++)if(nex[i][j]!=n+1&&j!=s[i]-'a'){
			for(int k=1;k<=lim[i];k++)ADD(f[nex[i][j]][k+1],f[i][k]);
			lim[nex[i][j]]=max(lim[nex[i][j]],lim[i]+1);
		}
		for(int j=1;j<=lim[i];j++)ADD(g[j],f[i][j]);
	}
	// for(int i=1;i<=n;i++)printf("%d ",g[i]);puts("");
	for(int i=1;i<=n;i++)res=(1ll*g[i]*C[n-1][i-1]+res)%mod;
	printf("%d\n",res);
	return 0;
}