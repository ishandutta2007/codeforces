#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const LL N=10005;
LL n,k; 
LL a[N];
LL ask (LL x,LL y)
{
	LL sum=0,t;
	cout<<"and "<<x<<" "<<y<<endl;
	cin>>t;sum+=t;
	cout<<"or "<<x<<" "<<y<<endl;
	cin>>t;sum+=t;
	return sum;
}
int main()
{
	cin>>n>>k;
	LL A=ask(1,2),B=ask(1,3),C=ask(2,3);
	a[1]=(A+B-C)/2;a[2]=A-a[1];a[3]=B-a[1];
	for (LL u=4;u<=n;u++)
	{
		LL t=ask(1,u);
		a[u]=t-a[1];
	}
	sort(a+1,a+1+n);
	cout<<"finish "<<a[k];
	return 0;
}