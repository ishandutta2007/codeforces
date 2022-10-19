#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,half,ord[20],L[20][1000],R[20][1000],num[20],res[1<<20],kn[20][20];
char g[20][20];
signed main(){
	scanf("%lld",&n);
	for(int i=0;i<n;i++)scanf("%s",g[i]);
	half=(n>>1);
	for(int p=0;p<(1<<n);p++){
		if(__builtin_popcount(p)!=half)continue;
		int qwq=0;
		for(int i=0;i<n;i++)if(p&(1<<i))ord[qwq++]=i;
		for(int i=0;i<n;i++)if(!(p&(1<<i)))ord[qwq++]=i;
//		for(int i=0;i<n;i++)printf("%d ",ord[i]);puts(""); 
		for(int i=0;i<n;i++)for(int j=0;j<n;j++)kn[i][j]=g[ord[i]][ord[j]]-'0';
		for(int i=0;i<n;i++)for(int j=0;j<(1<<(n-half));j++)L[i][j]=R[i][j]=0;
		for(int i=0;i<half;i++)num[i]=i;
		do{
			int mask=0;
			for(int i=0;i<half-1;i++)mask|=(kn[num[i]][num[i+1]]<<i);
			L[num[half-1]][mask]++;
//			printf("L:%d,%d\n",num[half-1],mask);
		}while(next_permutation(num,num+half));
		for(int i=0;i<n-half;i++)num[i]=i+half;
		do{
			int mask=0;
			for(int i=0;i<n-half-1;i++)mask|=(kn[num[i]][num[i+1]]<<i);
			R[num[0]][mask]++;
//			printf("R:%d,%d\n",num[0],mask);
		}while(next_permutation(num,num+n-half));
		for(int i=half;i<n;i++)for(int j=0;j<(1<<(n-half-1));j++){
			if(!R[i][j])continue;
			for(int k=0;k<half;k++){
				int mask=(j<<half)|(kn[k][i]<<(half-1));
				for(int l=0;l<(1<<(half-1));l++)res[mask+l]+=R[i][j]*L[k][l];
			}	
		}
	}
	for(int i=0;i<(1<<(n-1));i++)printf("%lld ",res[i]);
	return 0;
}