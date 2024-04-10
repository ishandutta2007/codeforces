#include<bits/stdc++.h>
using namespace std;
const int N = 222;
int n,a[N];
int main(){
	int T,i,s,f;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		s=0;
		for(i=1;i<=n;i++)
			scanf("%d",a+i),s+=a[i];
		f=0;
		for(i=2;i*i<=s;i++)
			if(s%i==0)
				f=1;
		if(!f){
			for(i=1;i<=n;i++)
				if(a[i]&1)
					f=i;
			printf("%d\n",n-1);
			for(i=1;i<=n;i++)
				if(i!=f)
					printf("%d ",i);
			printf("\n");
		}
		else{
			printf("%d\n",n);
			for(i=1;i<=n;i++)
				printf("%d ",i);
			printf("\n");
		}
	}
	return 0;
}