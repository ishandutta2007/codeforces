#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 5555;
const LL inf = 1e18;
int n,a[N];
LL b[N],ans,s;
int main(){
	int i,j;
	LL x;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",a+i);
	ans=inf;
	for(i=1;i<=n;i++){
		b[i]=0;
		s=0;
		for(j=i-1;j>=1;j--){
			x=b[j+1]/a[j]+1;
			s+=x;
			b[j]=x*a[j];
		}
		for(j=i+1;j<=n;j++){
			x=b[j-1]/a[j]+1;
			s+=x;
			b[j]=x*a[j];
		}
		ans=min(ans,s);
	}
	printf("%lld\n",ans);
	return 0;
}