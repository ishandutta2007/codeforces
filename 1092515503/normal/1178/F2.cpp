#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,num[1000100],f[1010][1010],mn[1010],mx[1010];
int main(){
	scanf("%d%d",&n,&m);
	memset(mn,0x3f3f3f3f,sizeof(mn));
	for(int i=1;i<=m;i++){
		scanf("%d",&num[i]);
		if(num[i]==num[i-1])i--,m--;
	}
	if(m>2*n){puts("0");return 0;}
//	for(int i=1;i<=m;i++)printf("%d ",num[i]);puts("");
	for(int i=1;i<=m;i++)mx[num[i]]=max(mx[num[i]],i),mn[num[i]]=min(mn[num[i]],i);
//	for(int i=1;i<=n;i++)printf("%d %d\n",mx[i],mn[i]);
	for(int i=1;i<=m+1;i++)for(int j=0;j<i;j++)f[i][j]=1;
	for(int l=1;l<=m;l++)for(int i=1,j=i+l-1;j<=m;i++,j++){
		int mp=0x3f3f3f3f;
		for(int k=i;k<=j;k++)mp=min(mp,num[k]);
		if(mn[mp]<i||mx[mp]>j)continue;
		int A=0,B=0;
		for(int k=mn[mp];k>=i;k--)(A+=(1ll*f[i][k-1]*f[k][mn[mp]-1]%mod))%=mod;
		for(int l=mx[mp];l<=j;l++)(B+=(1ll*f[mx[mp]+1][l]*f[l+1][j]%mod))%=mod;
		f[i][j]=1ll*A*B%mod;
//		printf("(%d,%d):\n",i,j);
		for(int p=mn[mp]+1,q=mn[mp];p<mx[mp];){
			while(q<j&&num[q+1]!=mp)q++;
//			printf("(%d,%d)\n",p,q);
			f[i][j]=1ll*f[i][j]*f[p][q]%mod;
			q++,p=q+1;
		}
//		printf("%d\n",f[i][j]);
	}
	printf("%d\n",f[1][m]);
	return 0;
}