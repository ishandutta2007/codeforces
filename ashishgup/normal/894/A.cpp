#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

int n, q=0, qa=0, qaq=0;
string s;

int32_t main()
{
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++)
	{
		if(s[i]=='Q')
		{
			q++;
			qaq+=qa;
		}
		else if(s[i]=='A')
		{
			qa+=q;
		}
	}
	cout<<qaq;
}