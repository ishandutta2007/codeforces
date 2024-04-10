#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int m,num[10],a[10],pov[10],all,dig,dd;
ll n,f[1<<18][110],ten[20];
void teg(int ip){
	dig=0;
	for(int i=9;i>=0;i--)a[i]=ip%num[i],ip/=num[i],dig+=a[i];
}
int main(){
	scanf("%lld%d",&n,&m);
	while(n)num[n%10]++,n/=10,dd++;
	ten[0]=1;
	for(int i=1;i<=dd;i++)ten[i]=ten[i-1]*10;
	for(int i=0;i<10;i++)num[i]++;
	pov[9]=1;
	for(int i=8;i>=0;i--)pov[i]=pov[i+1]*num[i+1];
//	for(int i=0;i<10;i++)printf("%d ",num[i]);puts("");
//	for(int i=0;i<10;i++)printf("%d ",pov[i]);puts("");
	all=pov[0]*num[0];
	for(int i=1;i<10;i++)if(num[i]>1)f[pov[i]][(ten[dd-1]*i)%m]=1;
	for(int i=1;i<all;i++){
		teg(i);
//		printf("QWQ:%d:::",i);for(int j=0;j<10;j++)printf("%d ",a[j]);puts("");
		for(int j=0;j<m;j++){
//			printf("%d:%d\n",j,f[i][j]);
			if(!f[i][j])continue;
			for(int k=0;k<10;k++)if(num[k]-a[k]>1)f[i+pov[k]][(ten[dd-dig-1]*k+j)%m]+=f[i][j];		
		}
	}
	printf("%lld\n",f[all-1][0]);
	return 0;
}