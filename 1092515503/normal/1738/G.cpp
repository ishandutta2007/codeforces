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
int n,m;
char s[1010][1010];
char t[1010][1010];
int mnp[1010];
void mina(){
	scanf("%d%d",&n,&m),m--;
	for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
	for(int i=1;i<=n;i++){for(int j=1;j<=n;j++)t[i][j]='0';t[i][n+1]='\0';}
	for(int i=1;i<=m;i++)for(int j=n-(m-i);j<=n;j++)
		s[i][j]=s[j][i]=t[i][j]=t[j][i]='1';
	for(int j=1;j<=n;j++)for(mnp[j]=1;mnp[j]<=n;mnp[j]++)
		if(s[mnp[j]][j]=='0')break;
	for(int i=1;i<=m;i++){
		int y=i,x=n-(m-i);
		while(true){
			while(x>mnp[y])x--,s[x][y]=t[x][y]='1';
			for(;mnp[y]<=n;mnp[y]++)if(s[mnp[y]][y]=='0')break;
			if(y==n-m+i){
				while(x>i)--x,s[x][y]=t[x][y]='1';
				break;
			}
			++y,s[x][y]=t[x][y]='1';
		}
	}
	for(int i=1;i<=n;i++)if(mnp[i]<=n){puts("NO");return;}
	puts("YES");
	for(int i=1;i<=n;i++)printf("%s\n",t[i]+1);
}
int T;
int main(){
	scanf("%d",&T);
	while(T--)mina();
	return 0;
}