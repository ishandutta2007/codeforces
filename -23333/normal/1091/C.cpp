#include<bits/stdc++.h>
using namespace std;
long long n,cnt,zl,cc;
long long p[200000],a[200000],az;
int main()
{	
	cin>>n;
	zl=sqrt(n);
	for(int i=1;i<=zl;i++)
	if(n%i==0)p[++cnt]=i;
	cc=2*cnt;
	if(zl*zl==n){a[cnt]=(((n/zl)*(zl-1)+2)*zl/2);cnt--;cc=2*cnt+1;}
	for(int i=1;i<=cnt;i++){
	zl=p[i];
	a[i]=az=(((n/zl)*(zl-1)+2)*zl/2);
	zl=n/p[i];
	a[cc-i+1]=(((n/zl)*(zl-1)+2)*zl/2);
	}
	for(int i=1;i<=cc;i++)cout<<a[i]<<' ';
	return 0;
}