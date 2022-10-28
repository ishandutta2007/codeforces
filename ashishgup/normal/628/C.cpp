#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int n, k;
string s;

int32_t main()
{
	IOS;
	cin>>n>>k>>s;
	for(int i=0;i<n;i++)
	{
		char ch=s[i];
		int maxadd=('z'-ch);
		int maxsub=(ch-'a');
		if(maxadd>=maxsub)
		{
			int add=min(k, maxadd);
			ch+=add;
			s[i]=ch;
			k-=add;
		}
		else
		{
			int sub=min(k, maxsub);
			ch-=sub;
			s[i]=ch;
			k-=sub;
		}
	}	
	if(k>0)
		cout<<"-1";
	else
		cout<<s;
	return 0;
}