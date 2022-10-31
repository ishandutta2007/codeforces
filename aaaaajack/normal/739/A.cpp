#include<bits/stdc++.h>
#define N 100100
using namespace std;
int main(){
	int n,m,l,r,mn;
	scanf("%d%d",&n,&m);
	mn=n;
	for(int i=0;i<m;i++){
		scanf("%d%d",&l,&r);
		mn=min(mn,r-l+1);
	}
	printf("%d\n",mn);
	for(int i=0;i<n;i++){
		printf("%d ",i%mn);
	}
	return 0;
}