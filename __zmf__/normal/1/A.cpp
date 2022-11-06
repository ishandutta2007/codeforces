#include<bits/stdc++.h>
using namespace std;
long long n,m,t,p,q;
int main()
{
	cin>>n>>m>>t;
	p=n/t,q=m/t;
	if(n%t!=0)p++;
	if(m%t!=0)q++;
	cout<<p*q<<endl;
	return 0;
}