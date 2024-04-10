#include <stdio.h>

int n,vis[100010];

int main() {
	scanf("%d",&n);
	int val,cnt=0,max=0;
	for(int i=0;i<2*n;i++) {
		scanf("%d",&val);
		if(!vis[val]) {
			cnt++;
			vis[val]=true;
		}
		else {
			cnt--;
			vis[val]=false;
		}
		if(max<cnt) max=cnt;
	}
	printf("%d\n",max);
	return 0;
}