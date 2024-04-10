#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, q;
int x[N], y[N], z[N];
string s;

int32_t main()
{
	IOS;
	cin>>s;
	n=s.size();
	s='*'+s;
	for(int i=1;i<=n;i++)
	{
		x[i]=x[i-1] + (s[i]=='x');
		y[i]=y[i-1] + (s[i]=='y');
		z[i]=z[i-1] + (s[i]=='z');
	}
	cin>>q;
	for(int i=1;i<=q;i++)
	{
		int l, r;
		cin>>l>>r;
		if(r-l+1<=2)
		{
			cout<<"YES"<<endl;
			continue;
		}
		int numx=x[r]-x[l-1];
		int numy=y[r]-y[l-1];
		int numz=z[r]-z[l-1];
		int min1=min({numx, numy, numz});
		int max1=max({numx, numy, numz});
		if(max1-min1<=1)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}