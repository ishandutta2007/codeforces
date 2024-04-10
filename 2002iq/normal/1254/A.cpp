#include <bits/stdc++.h>
using namespace std;
string s[105],ans[105];
char get(int x)
{
	if (x<26)
	return x+'a';
	else if (x<52)
	return x-26+'A';
	else
	return x-52+'0';
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n,m,c,r=0;
		cin >> n >> m >> c;
		for (int i=0;i<n;i++)
		{
			cin >> s[i];
			for (int j=0;j<m;j++)
			r+=(s[i][j]=='R');
			ans[i].resize(m);
		}
		int cur=r/c+(r%c>0),done=0;
		for (int i=0;i<n;i++)
		{
			int st=0,dir=1;
			if (i%2)
			{
				st=m-1;
				dir=-1;
			}
			for (int j=st;j<m && j>=0;j+=dir)
			{
				if (!cur)
				{
					done++;
					cur=r/c;
					if (done<r%c)
					cur++;
				}
				ans[i][j]=get(min(done,c-1));
				if (s[i][j]=='R')
				cur--;
			}
		}
		for (int i=0;i<n;i++)
		cout << ans[i] << endl;
	}
}