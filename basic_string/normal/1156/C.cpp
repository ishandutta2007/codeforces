#include<bits/stdc++.h>
using namespace std;
int a[200009];
int main(){
	int n,z,i,j,s=0;
	scanf("%d%d",&n,&z);
	for(i=1;i<=n;++i)scanf("%d",a+i);
	sort(a+1,a+n+1),j=1;
	for(i=(n+1)/2+1;i<=n;++i)if(a[i]-a[j]>=z)++s,++j;
	printf("%d",s);
	return 0;
}