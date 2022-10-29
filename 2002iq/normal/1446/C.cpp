#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> v,int b)
{
	if (!b || v.empty())
	return 0;
	vector<int> v0,v1;
	for (int i:v)
	{
		if (i&(1<<b))
		v1.push_back(i);
		else
		v0.push_back(i);
	}
	return min(solve(v0,b-1)+max((int)v1.size()-1,0),solve(v1,b-1)+max((int)v0.size()-1,0));
}
int main()
{
	int n;
	scanf("%d",&n);
	vector<int> v;
	for (int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		v.push_back(a);
	}
	printf("%d",solve(v,30));
}