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
void ADD(int&x,int y){if((x+=y)>=mod)x-=mod;}
int T_T,n,f[2010][2010][2][2],g[2010][2010][2][2],res;
char s[2010],t[2010];
void mina(){
	scanf("%d%s%s",&n,s+1,t+1);
	for(int i=1;i<=n;i+=2){
		if(s[i]!='?')s[i]^=1;
		if(t[i]!='?')t[i]^=1;
	}
	for(int i=1;i<=n+1;i++)for(int j=1;j<=n+1;j++)
		for(int I=0;I<2;I++)for(int J=0;J<2;J++)f[i][j][I][J]=g[i][j][I][J]=0;
	for(int i=0;i<2;i++)for(int j=0;j<2;j++)
		if(s[1]!='0'+!i&&t[1]!='0'+!j)
			f[1][1][i][j]=1,g[1][1][i][j]=0;
	s[n+1]=t[n+1]='0';
	// printf("%s %s\n",s+1,t+1);
	for(int i=1;i<=n+1;i++)for(int j=1;j<=n+1;j++){
		// printf("%d,%d:%d,%d,%d,%d\n",i,j,f[i][j][0][0],f[i][j][0][1],f[i][j][1][0],f[i][j][1][1]);
		if(i<=n&&j<=n)for(int I=0;I<2;I++)for(int J=0;J<2;J++){
			if(s[i+1]=='0'+!I||t[j+1]=='0'+!J)continue;
			// printf("IJ%d%d\n",I,J);
			ADD(f[i+1][j+1][I][J],f[i][j][0][0]);
			ADD(g[i+1][j+1][I][J],g[i][j][0][0]);
			ADD(f[i+1][j+1][I][J],f[i][j][1][1]);
			ADD(g[i+1][j+1][I][J],g[i][j][1][1]);
			if(!I||!J)continue;
			ADD(g[i+1][j+1][I][J],1ll*f[i][j][0][0]*abs(i-j)%mod);
			ADD(g[i+1][j+1][I][J],1ll*f[i][j][1][1]*abs(i-j)%mod);
		}
		if(i<=n)for(int I=0;I<2;I++)if(s[i+1]!='0'+!I){
			// printf("I%d\n",I);
			ADD(f[i+1][j][I][1],f[i][j][0][1]);
			ADD(g[i+1][j][I][1],g[i][j][0][1]);
			if(I)ADD(g[i+1][j][I][1],1ll*f[i][j][0][1]*abs(i+1-j)%mod);

			if(j==n+1)ADD(f[i+1][j][I][0],f[i][j][0][0]),ADD(g[i+1][j][I][0],g[i][j][0][0]);
		}
		if(j<=n)for(int J=0;J<2;J++)if(t[j+1]!='0'+!J){
			// printf("J%d\n",J);
			ADD(f[i][j+1][1][J],f[i][j][1][0]);
			ADD(g[i][j+1][1][J],g[i][j][1][0]);
			if(J)ADD(g[i][j+1][1][J],1ll*f[i][j][1][0]*abs(j+1-i)%mod);

			if(i==n+1)ADD(f[i][j+1][0][J],f[i][j+1][0][0]),ADD(g[i][j+1][0][J],g[i][j][0][0]);
		}
	}
	printf("%d\n",g[n+1][n+1][0][0]);
}
int main(){
	scanf("%d",&T_T);
	while(T_T--)mina();
	return 0;
}
/*
1
2
00
11
*/