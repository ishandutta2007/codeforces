#include<bits/stdc++.h>
using namespace std;
int n,a,m,t[1020];
set <int> x;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a,t[a]++,m=max(m,t[a]),x.insert(a);
	cout<<m<<" "<<x.size();
	return 0;
}