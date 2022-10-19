#include<bits/stdc++.h>
using namespace std;
int n,a[100100],sta[100100],suf[100100][2],pre[100100][2],res;
int main(){
	scanf("%d",&n),n++,scanf("%d",&a[n]);
	sta[0]=1;
	for(int i=1;i<n;i++)scanf("%d",&a[i]),sta[i]=sta[i-1]^1;
	for(int i=n-1;i>=0;i--)suf[i][sta[i]]=suf[i+1][sta[i]]+a[i+1]-a[i],suf[i][!sta[i]]=suf[i+1][!sta[i]];
	for(int i=1;i<=n;i++)pre[i][sta[i-1]]=pre[i-1][sta[i-1]]+a[i]-a[i-1],pre[i][!sta[i-1]]=pre[i-1][!sta[i-1]];
//	for(int i=0;i<=n;i++)printf("%d %d %d %d\n",pre[i][0],pre[i][1],suf[i][0],suf[i][1]);
	res=suf[0][1];
	for(int i=0;i<n;i++){
		if(a[i+1]-a[i]<=1)continue;
		res=max(res,pre[i][1]+a[i+1]-a[i]-1+suf[i+1][0]);
	}
	printf("%d\n",res);
	return 0;
}