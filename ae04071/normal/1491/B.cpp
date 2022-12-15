#include <bits/stdc++.h>
using namespace std;

int a[100];
int main() {
	int test;
	scanf("%d",&test);
	while(test--) {
		int n,u,v;
		scanf("%d%d%d",&n,&u,&v);
		for(int i=0;i<n;i++)
			scanf("%d",a+i);
		
		int dif=0;
		for(int i=0;i<n-1;i++) {
			dif = max(dif,abs(a[i+1] - a[i]));
		}
		if(dif==0) printf("%d\n",v+min(u,v));
		else if(dif==1) printf("%d\n",min(u,v));
		else printf("0\n");
	}
	return 0;
}