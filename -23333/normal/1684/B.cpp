#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
int T,n,m;
char s[100];
int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--)
	{
		int x,y,z;
		cin>>x>>y>>z;
		cout<<x+y+z<<" "<<y+z<<" "<<z<<endl;
	}
	return 0;
}