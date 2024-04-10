#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 5555;
int n,a[N],b[N];
LL s;
int main()
{
	int T,i,j,x;
	scanf("%d",&T);
	while(T--){
		memset(b,0,sizeof(b));
		scanf("%d",&n);
		s=0;
		for(i=1;i<=n;i++){
			scanf("%d",a+i);
			for(j=i+2;j<=i+a[i]&&j<=n;j=j+1)
				b[j]++;
			if(b[i]>=a[i]-1)
				b[i+1]+=b[i]-(a[i]-1);
			else
				s+=a[i]-1-b[i];
		}
		printf("%lld\n",s);
	}
	return 0;
}