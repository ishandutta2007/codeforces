#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,x1,y1,x2,y2;
	scanf("%d",&n);
	puts("YES");
	for(int i=0;i<n;i++){
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		printf("%d\n",1+((x1&1)<<1|(y1&1)));
	}
	return 0;
}