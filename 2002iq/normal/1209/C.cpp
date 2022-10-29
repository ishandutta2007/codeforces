#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		string s,res="-";
		cin >> n >> s;
		for (int i=0;i<=10;i++)
		{
			int las=-1;
			string ans(n,'2'),test="";
			for (int k=0;k<n;k++)
			{
				if (s[k]-'0'<i)
				{
					ans[k]='1';
					las=k;
				}
			}
			for (int k=las+1;k<n;k++)
			{
				if (s[k]-'0'==i)
				ans[k]='1';
			}
			for (int k=0;k<n;k++)
			{
				if (ans[k]=='1')
				test+=s[k];
			}
			for (int k=0;k<n;k++)
			{
				if (ans[k]=='2')
				test+=s[k];
			}
			bool ok=1;
			for (int k=1;k<n;k++)
			ok&=(test[k]>=test[k-1]);
			if (ok)
			res=ans;
		}
		cout << res << endl;
	}
}