#include<bits/stdc++.h>
using namespace std;
int T,n,m,a[20],f[16][15][1<<15],s[(1<<15)+1],las[16][15][1<<15],pos[16],pc[1<<15];
void chmn(int&x,int y){if(x>y)x=y;}
int main(){
	scanf("%d",&T);
	for(int i=0;i<(1<<15);i++)pc[i]=__builtin_popcount(i);
	while(T--){
		scanf("%d",&n),m=1<<n;
		for(int i=0;i<n;i++)scanf("%d",&a[i]);
		for(int i=0;i<m;i++){s[i]=0;for(int j=0;j<n;j++)if(i&(1<<j))s[i]+=a[j];}
		s[m]=0x3f3f3f3f;
		for(int i=0;i<=n;i++)for(int j=0;j<n;j++)for(int k=0;k<m;k++)f[i][j][k]=m;
		f[0][0][0]=0;
		for(int i=0;i<n;i++)for(int j=0;j<n;j++)for(int k=0;k+1<m;k++)
			if(f[i][j][k]!=m&&s[f[i][j][k]]<s[(m-1)^f[i][j][k]])
				for(int K=(~k)&(m-1),p=K;p;p=(p-1)&K)
					if(s[f[i][j][k]]<s[p]){
						int t=((1<<n)-(1<<i))&p;
						if(!t)continue;
						t=__builtin_ctz(t);
						int&x=f[t+1][j+pc[p]-1][k|p];
						if(s[x]>s[p])x=p,las[t+1][j+pc[p]-1][k|p]=i;
					}
		int I,J=0x3f3f3f3f,K=m-1;
		for(int i=0;i<=n;i++)for(int j=0;j<n;j++)if(f[i][j][m-1]!=m&&J>j)J=j,I=i;
		printf("%d\n",J);
		while(I){
			for(int t=0;t<n;t++)if(f[I][J][K]&(1<<t))pos[t]=I-1;
			int i=las[I][J][K],j=J-pc[f[I][J][K]]+1,k=K^f[I][J][K];
			I=i,J=j,K=k;
		}
		for(int i=n-1;i>=0;i--)if(pos[i]!=i){
			int t=pos[i];
			for(int j=i+1;j<n;j++)if(pos[j]!=j&&j<pos[i])t--;
			printf("%d %d\n",i+1,t+1);
		}
	}
	return 0;
}
/*
1
15
16384 8192 4096 2048 1024 512 256 128 64 32 16 8 4 2 1
*/