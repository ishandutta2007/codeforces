#include<bits/stdc++.h>
using namespace std;
int n,x,c;
int main()
{
	cin>>n>>x;
	for(int i=1;i<=n;i++)
		if(x%i==0&&x/i<=n)c++;
	cout<<c;
	return 0;
}