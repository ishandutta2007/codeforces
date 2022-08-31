#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 111;
int n,a[N];
int main()
{
	int T,i,x,y,o,u;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&x,&y);
		o=1;
		u=0;
		for(i=1;i<=n;i++){
			scanf("%d",a+i);
			if(a[i]!=a[1])
				o=0;
			if(i>1&&abs(a[i]-a[i-1])>1)
				u=1;
		}
		if(u)
			printf("0\n");
		else{
			if(o)
				printf("%d\n",y+min(x,y));
			else
				printf("%d\n",min(x,y));
		}
	}
	return 0;
}