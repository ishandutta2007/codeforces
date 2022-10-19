#include<bits/stdc++.h>
using namespace std;
long long n,m,k,a[100001],nowdel,tot;
int main(){
	scanf("%I64d%I64d%I64d",&n,&m,&k);
	for(long long i=1;i<=m;i++)scanf("%I64d",&a[i]);
	long long i=1;
	while(i<=m){
		nowdel=i;
//		printf("%d\n",i);
		while(i<=m&&(a[i]-nowdel)/k==(a[i+1]-nowdel)/k)i++;
		i++;
		tot++;
	}
	printf("%I64d",tot);
	return 0;
}