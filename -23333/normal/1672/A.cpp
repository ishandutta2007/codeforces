#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
const int N=1e6;
int n,m;
int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while (T--)
	{
		cin>>n;
		int ans=0;
		rep(i,1,n)
		{
			int x;
			cin>>x;
			if (x>1)
			{ 
			  ans+=x-1;
			  ans%=2;
		    }
		}
		if (ans==1) cout<<"errorgorn"<<endl;
		else cout<<"maomao90"<<endl;
	}
	return 0;
}