#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 111;
int n,a[N],b[N];
int main()
{
	int T,i,x,y,o;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&x,&y);
		for(i=0;i<30;i=i+1){
			a[i]=(x>>i)&1;
			b[i]=(y>>i)&1;
		}
		if(x>y){
			printf("NO\n");
			continue;
		}
		for(i=1;i<30;i=i+1)
			a[i]+=a[i-1],b[i]+=b[i-1];
		o=1;
		for(i=0;i<30;i=i+1)
			if(a[i]<b[i])
				o=0;
		if(o)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}