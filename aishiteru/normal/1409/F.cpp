#include<stdio.h>
#include<string.h>
#define it register int
#define ct const int
#define il inline
const int N=205;
int n,K,ans,f[N][N][N];
char s[N],t[N];
il void ckMax(int &p,ct q){p=(p>q?p:q);}
int main(){
	scanf("%d%d%s%s",&n,&K,s+1,t+1);it i,j,k,x;t[1]-='a',t[2]-='a';
	for(i=1;i<=n;++i) s[i]-='a';
	memset(f,-1,sizeof(f)),f[1][0][0]=0;
	for(i=1;i<=n;++i)
		for(j=0;j<=K;++j)
			for(k=0;k<n;++k)
				if(f[i][j][k]!=-1)
				for(x=0;x<26;++x)
					ckMax(f[i+1][j+(s[i]!=x)][k+(t[1]==x)],f[i][j][k]+(t[2]==x?k:0));
	for(i=0;i<=K;++i) for(j=0;j<=n;++j) ckMax(ans,f[n+1][i][j]);
	printf("%d",ans);
	return 0;
}