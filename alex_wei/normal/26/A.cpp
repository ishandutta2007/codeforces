#include<bits/stdc++.h>
using namespace std;
int p[3003],n,c;
int main()
{
	cin>>n;
	for(int i=2;i<=n;i++)
		if(!p[i])
			for(int j=i+i;j<=n;j+=i)
				p[j]++;
	for(int i=1;i<=n;i++)
		c+=p[i]==2;
	cout<<c;
	return 0;
}