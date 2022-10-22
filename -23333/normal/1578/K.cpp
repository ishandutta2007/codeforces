#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
ll n,m;
int main()
{
	int T;
	cin>>T;
	while (T--)
	{
		cin>>n>>m;
		cout<<m/(n*n)<<endl;
	}
	return 0;
}