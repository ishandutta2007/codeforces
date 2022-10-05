#include<bits/stdc++.h>
using namespace std;
bitset<1250001>f[51][26];
int a[51];
bool b[51];
int main(){
	int n,m,i,j,k,s=0;
	for(i=1,scanf("%d",&n),m=n*2;i<=m;++i)scanf("%d",a+i),f[i][0][0]=1;
	for(sort(a+1,a+m+1),i=3;i<=m;++i)for(j=1,s+=a[i];j<n;++j)if(j+m-i>n-2)f[i][j]=f[i-1][j-1]<<a[i]|f[i-1][j];
	for(i=s/2,k=n-1;~i;--i)if(f[m][k][i]){j=i;break;}
	for(i=m;i>2;--i)if(j>=a[i]&&f[i-1][k-1][j-a[i]])b[i]=1,j-=a[i],--k;
	for(printf("%d ",a[1]),i=3;i<=m;++i)if(b[i])printf("%d ",a[i]);
	for(puts(""),i=m;i>2;--i)if(!b[i])printf("%d ",a[i]);
	printf("%d",a[2]);
	return 0;
}