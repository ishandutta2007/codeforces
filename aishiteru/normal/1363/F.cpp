#include<stdio.h>
#include<set>
#include<vector>
#include<algorithm>
#define it register int
#define ct const int
#define il inline
using namespace std;
const int N=2005;
char s[N],t[N];
int f[N][N],n,T,cns[N][N],cnt[N][N];
il int Min(ct p,ct q){return p<q?p:q;}
int main(){ 
	scanf("%d",&T);it i,j;
	while(T--){
		scanf("%d%s%s",&n,s+1,t+1);
		for(i=0;i<=n;++i)
			for(j=0;j<=n;++j)
				f[i][j]=0x3f3f3f3f;
		for(i=0;i<=n;++i) f[0][i]=0;
		for(i=1;i<=n;++i){
			t[i]-='a',s[i]-='a';
			for(j=0;j<26;++j) cns[i][j]=cns[i-1][j],cnt[i][j]=cnt[i-1][j];
			++cns[i][s[i]],++cnt[i][t[i]];
		}
		for(i=0;i<26;++i) 
			if(cns[n][i]!=cnt[n][i]) break;
		if(i<26){puts("-1");continue;}
		for(i=1;i<=n;++i)
			for(j=1;j<=n;++j){
				f[i][j]=f[i-1][j]+1;
				if(s[i]==t[j]) f[i][j]=Min(f[i][j],f[i-1][j-1]);
				if(cns[i][t[j]]<cnt[j][t[j]]) f[i][j]=Min(f[i][j],f[i][j-1]);//Sit[j]Tit[j]
			}
		printf("%d\n",f[n][n]<0x3f3f3f3f?f[n][n]:-1);
	}
	return 0;
}