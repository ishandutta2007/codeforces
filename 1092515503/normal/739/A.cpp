#include<bits/stdc++.h>
using namespace std;
int n,m,t1,t2,mn=0x3f3f3f3f;
int main(){
	scanf("%d%d",&n,&m);
	while(m--)scanf("%d%d",&t1,&t2),mn=min(mn,t2-t1+1);
	printf("%d\n",mn);
	for(int i=0;i<n;i++)printf("%d ",i%mn);
	return 0;
}