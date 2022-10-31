#include<bits/stdc++.h>
#define N 100100
using namespace std;
int a[N];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		long long md=0,pre=-1023456789;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			int x;
			scanf("%d",&x);
			md=max(pre-x,md);
			pre=max(pre,(long long)x);
		}
		int c=0;
		while(md){
			c++;
			md>>=1;
		}
		printf("%d\n",c);
	}
	return 0;
}