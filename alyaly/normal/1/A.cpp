#include<bits/stdc++.h>
#include<cmath>
using namespace std;
unsigned long long a,m,n;
int main(){
//	cin>>n;
//	if(n%2==0&&n!=2) printf("YES\n");
//	else printf("NO\n");
	cin>>n>>m>>a;
	unsigned long long ans=(unsigned long long)(ceil(m*1.0/a))*(ceil(n*1.0/a));
	printf("%lld\n",ans);
	return 0;
}