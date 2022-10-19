/*
Better Complexity:
we can only transfer in one zero place(j) during each step.Even if the dp values during the transfer isn't correct, the final value if correct.
Comlexity O(m2^n).
A better understanding:<--- previous programme with complexity O(nm2^n)
*/
#include<bits/stdc++.h>
using namespace std;
int n,m,a[20][20],b[20][20],same[20][20],f[1<<20],MAXN;
char s[20][20];
int main(){
	scanf("%d%d",&n,&m),MAXN=1<<n,memset(f,0x3f3f3f3f,sizeof(f)),f[0]=0;
	for(int i=0;i<n;i++)scanf("%s",s[i]);
	for(int i=0;i<n;i++)for(int j=0;j<m;j++)scanf("%d",&a[i][j]);
	for(int i=0;i<n;i++)for(int j=0;j<m;j++){
		int mx=0;
		for(int k=0;k<n;k++)if(s[i][j]==s[k][j])same[i][j]|=(1<<k),b[i][j]+=a[k][j],mx=max(mx,a[k][j]);
		b[i][j]-=mx;
	}
	for(int i=0,j;i<MAXN-1;i++){
		for(j=0;j<n;j++)if(!(i&(1<<j)))break;
		for(int k=0;k<m;k++)f[i|(1<<j)]=min(f[i|(1<<j)],f[i]+a[j][k]),f[i|same[j][k]]=min(f[i|same[j][k]],f[i]+b[j][k]);
	}
	printf("%d\n",f[MAXN-1]);
	return 0;
}