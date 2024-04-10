#include<bits/stdc++.h>
using namespace std;

int main(){
	int a,b,d,s=0;
	cin>>a>>b,d=__gcd(a,b);
	while(a>d){
		if(a%2==0&&(a/2)%d==0)a/=2,++s;
		else if(a%3==0&&(a/3)%d==0)a/=3,++s;
		else if(a%5==0&&(a/5)%d==0)a/=5,++s;
		else puts("-1"),exit(0);
	}
	while(b>d){
		if(b%2==0&&(b/2)%d==0)b/=2,++s;
		else if(b%3==0&&(b/3)%d==0)b/=3,++s;
		else if(b%5==0&&(b/5)%d==0)b/=5,++s;
		else puts("-1"),exit(0);
	}
	cout<<s;
	return 0;
}