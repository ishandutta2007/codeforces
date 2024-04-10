#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n,k,z=0,o=0;
		string s;
		cin >> n >> k >> s;
		bool ok=1;
		for (int i=0;i<n;i++)
		{
			if (s[i]!='?' && s[i%k]!='?' && s[i]!=s[i%k])
			ok=0;
			if (s[i]!='?')
			s[i%k]=s[i];
		}
		for (int i=0;i<k;i++)
		{
			z+=(s[i]=='0');
			o+=(s[i]=='1');
		}
		puts((ok && z<=k/2 && o<=k/2)? "YES":"NO");
	}
}