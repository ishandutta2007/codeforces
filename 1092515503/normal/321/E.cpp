#include<bits/stdc++.h>
using namespace std;
void read(int &x){
	x=0;
	char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c^48),c=getchar();
}
int n,m,s[4010][4010],cost[4010][4010],tran[4010][4010],f[4010][4010];
int main(){
	read(n),read(m),memset(f,0x3f3f3f3f,sizeof(f));
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)read(s[i][j]),s[i][j]+=s[i-1][j]+s[i][j-1]-s[i-1][j-1];
	if(m>=n){puts("0");return 0;}
	for(int i=n;i;i--)for(int j=i;j;j--)cost[j][i]=s[i][i]-s[j-1][i]-s[i][j-1]+s[j-1][j-1];
	for(int i=1;i<=n;i++)f[i][1]=cost[1][i];
	for(int j=2;j<=m;j++){
		tran[n+1][j]=n;
		for(int i=n;i>=j;i--)for(int k=tran[i][j-1];k<=tran[i+1][j];k++)if(f[i][j]>f[k][j-1]+cost[k+1][i])f[i][j]=f[k][j-1]+cost[k+1][i],tran[i][j]=k;
	}
	printf("%d\n",f[n][m]>>1);
	return 0;
}