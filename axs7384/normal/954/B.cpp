#include<bits/stdc++.h>
using namespace std;
int n;
char c[1000];
inline bool work(int len)
{
	for (int i=1;i<=len;++i)
		if (c[i]!=c[i+len])
			return 0;
	return 1;
}
int main()
{
	cin>>n;
	scanf("%s",c+1);
	for (int i=n/2;i>=1;--i)
		if (work(i))
		{
			cout<<n-i+1;
			return 0;
		}
	cout<<n;
	return 0;
}