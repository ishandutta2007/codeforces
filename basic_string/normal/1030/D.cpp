#include<bits/stdc++.h>
using namespace std;

int main(){
	int d,n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	if(2*1ll*n*m%k)puts("NO"),exit(0);
	puts("YES");
	d=__gcd(n,k),n/=d,k/=d;
	d=__gcd(m,k),m/=d,k/=d;
	if(k==1)d>1?(m*=2):(n*=2);
	cout<<n<<' '<<0<<'\n'<<0<<' '<<0<<'\n'<<0<<' '<<m;
	return 0;
}