#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[4];
ll res;
int main(){
	scanf("%d",&n);
	for(int i=1,x,y;i<=n;i++)scanf("%d%d",&x,&y),x>>=1,y>>=1,a[((x&1)<<1)+(y&1)]++;
//	printf("%d %d %d %d\n",a[0][0],a[1][0],a[0][1],a[1][1]);
	for(int i=0;i<4;i++)res+=1ll*a[i]*(a[i]-1)*(a[i]-2)/6;
	for(int i=0;i<4;i++)for(int j=0;j<4;j++)if(i!=j)res+=1ll*a[i]*(a[i]-1)/2*a[j];
	printf("%lld\n",res);
	return 0;
}