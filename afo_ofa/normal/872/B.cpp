#include<bits/stdc++.h>
using namespace std;
int mi=1e9,ma=-1e9,a[100010],b[100010],c[100010];
int main(){
	int n,k; scanf("%d%d",&n,&k);
	for (int i=1;i<=n;++i) scanf("%d",&a[i]),mi=min(a[i],mi),ma=max(ma,a[i]);
	memset(b,0x3f3f,sizeof(b));
	memset(c,0x3f3f,sizeof(c));
	if (k==1){
		printf("%d",mi); return 0;
	}
	if (k>=3){
		printf("%d",ma); return 0;
	}
	int ans=-1e9;
	for (int i=1;i<=n;++i) b[i]=min(b[i-1],a[i]); 
	for (int i=n;i>=1;--i) c[i]=min(c[i+1],a[i]);
	for (int i=1;i<n;++i) ans=max(ans,max(b[i],c[i+1]));
	printf("%d",ans);
}