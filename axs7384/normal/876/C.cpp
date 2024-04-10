#include<bits/stdc++.h>
using namespace std;
inline int js(int x)
{
	int sum=x;
	while (x)
	{
		sum+=x%10;
		x/=10;
	}
	return sum;
}
int n;
vector<int> a;
int main()
{
	scanf("%d",&n);
	for (int i=max(0,n-1000);i<=n;++i)
		if (js(i)==n)
			a.push_back(i);
	int l=a.size();
	cout<<l<<'\n';
	for (int i=0;i<l;++i)
		cout<<a[i]<<' ';
}