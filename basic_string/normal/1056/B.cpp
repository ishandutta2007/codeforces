#include<bits/stdc++.h>
using namespace std;
int a[1009];
int main(){
	int n,m,i;
	long long s=0;
	scanf("%d%d",&n,&m),a[0]=-1;
	for(i=0;i<m;++i)a[i*i%m]+=(n/m)+(n%m>=i);
	for(i=0;i<m;++i)s+=a[i]*1ll*a[(m-i)%m];
	cout<<s;
	return 0;
}