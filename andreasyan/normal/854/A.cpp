#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdio>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <unordered_map>
#include <stack>
using namespace std;

int n,m;
int gcd(int x,int y)
{
	if(x==0)
		return y;
	if(y<x)
		return gcd(y,x);
	return gcd(y%x,x);
}
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		if(i<n-i && gcd(i,n-i)==1)
		{
			m=i;
		}
	}
	cout<<m<<' '<<n-m<<endl;
	return 0;
}