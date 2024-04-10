#include<bits/stdc++.h>
using namespace std;
int n,A,B,C,D;
typedef long long ll;
ll res;
ll a[1001000],b[1001000],f[1001000][2];//0:all before ones has finished; 1:only the previous one isn't finished
int main(){
	scanf("%d%d%d%d%d",&n,&A,&B,&C,&D);
	for(int i=1,x;i<=n;i++){
		scanf("%d",&x);
		a[i]=min(1ll*(x+1)*A,1ll*B)+A;
		b[i]=1ll*x*A+C;
		f[i][0]=min(f[i-1][0]+b[i],f[i-1][1]+min(a[i],b[i])+2*D);
		f[i][1]=f[i-1][0]+a[i];
	}
	res=min(f[n][0],f[n][1]+2*D);
	ll sum=b[n];
	for(int i=n-1;i;i--)sum+=a[i]+D,res=min(res,f[i-1][0]+sum);
	printf("%I64d\n",res+1ll*(n-1)*D);
	return 0;
}