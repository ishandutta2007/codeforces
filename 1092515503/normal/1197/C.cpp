#include<bits/stdc++.h>
using namespace std;
int n,k,a[300001],s;
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<n;i++)a[i]=a[i+1]-a[i],s+=a[i];
	sort(a+1,a+n);
	for(int i=1;i<k;i++)s-=a[n-i];
	printf("%d\n",s);
	return 0;
}