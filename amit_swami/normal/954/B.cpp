#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
const int N=100+10;

int n,ans;string s;

int main()
{
	cin>>n>>s;
	ans=n;
	int i;
	for(i=1;i+i<=n;++i)
	{
		if(s.substr(0,i)==s.substr(i,i))
		{
			ans=min(ans,n-i+1);
		}
	}
	cout<<ans;
	return 0;
}