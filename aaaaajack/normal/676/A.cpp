#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,M,x;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		if(x==1) m=i;
		else if(x==n) M=i;
	}
	printf("%d\n",max(max(m,M),max(n-1-m,n-1-M)));
	return 0;
}