#include<bits/stdc++.h>
using namespace std;
int n,m,a[1010],b[1010],res;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)scanf("%d",&b[i]);
	for(int i=1,j=1;i<=n&&j<=m;i++)if(a[i]<=b[j])j++,res++;
	printf("%d\n",res);
	return 0;
}