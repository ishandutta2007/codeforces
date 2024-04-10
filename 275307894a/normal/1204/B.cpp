#include<cstdio>
#include<iostream>
using namespace std;
int n,l,r;
long long ans1,ans2,x;
int main(){
	scanf("%d%d%d",&n,&l,&r);
	x=1;
	ans1=1;
	for(int i=2;i<=l;i++) x*=2,ans1+=x;
	cout<<ans1+(n-l)<<" ";
	x=1;
	ans2=1;
	for(int i=2;i<=r;i++) x*=2,ans2+=x;
	cout<<ans2+(n-r)*x;
	return 0;
}