#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
const int N=5e5;
int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while (T--)
	{
		ll s,n,k;
		cin>>s>>n>>k;
		bool tt=0;
		if (n>=k) 
		{ 
		    if ((n/k)*k+n<=s) tt=1; 
		}  else
		{
			if (s<k) tt=1;
			else if (s>k)
			{
				if (n>k-1) tt=0;
				else tt=1;
			}
		}
		if (!tt) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
    }
	return 0;
}