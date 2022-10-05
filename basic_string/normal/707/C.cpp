#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,w=1;
	cin>>n;
	if(n<3)puts("-1"),exit(0);
	if(n%4==0){
		long long a=n*1ll*n/4-1,b=a+2;
		cout<<a<<' '<<b;
		return 0;
	}
	while(n%2==0)n/=2,w*=2;
	long long a=n*1ll*n/2,b=a+1;
	cout<<a*w<<' '<<b*w;
	return 0;
}