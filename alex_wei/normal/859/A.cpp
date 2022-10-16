#include<bits/stdc++.h>
using namespace std;
int k,m=25,a;
int main()
{
	cin>>k;
	for(int i=1;i<=k;i++)
		cin>>a,m=max(m,a);
	cout<<m-25;
	return 0;
}