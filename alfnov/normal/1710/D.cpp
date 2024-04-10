#include<bits/stdc++.h>
using namespace std;
char s[2005][2005];
int a[2005][2005];
int L[2005],R[2005];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i){
			scanf("%s",s[i]);
			for(int j=i+1;j<=n;++j)a[i][j]=s[i][j-i]-'0';
		}
		for(int i=1;i<=n;++i)L[i]=R[i]=i;
		for(int l=2;l<=n;++l)for(int i=1;i<=n-l+1;++i){
			int j=i+l-1;
			if(!a[i][j])continue;
			if(L[i]==L[j])continue;
			printf("%d %d\n",i,j);
			int zj=i,yj=j;
			int x=R[i]+1;
			int gs=1;
			while(x<L[j]){
				if(gs){
					printf("%d %d\n",yj,x);
					yj=x;
				}else{
					printf("%d %d\n",x,zj);
					zj=x;
				}
				gs^=1;
				x=R[x]+1;
			}
			int ll=L[i],rr=R[j];
			for(int k=ll;k<=rr;++k)L[k]=ll,R[k]=rr;
		}
	}
	return 0;
}