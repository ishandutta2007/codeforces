#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

const int MAXN = 1000;

string a[MAXN];
string s;
int n;
int ans;

int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	while (getline(cin, s))
	{
		if (s[0] == '+')
		{
			a[n++] = s.substr(1);
		}
		else
		if (s[0] == '-')
		{
			s = s.substr(1);
			for (int i = 0; i < n; i++)
				if (a[i] == s)
				{
					a[i] = a[--n];
					break;
				}
		}
		else
			ans += n * ((int)s.size() - s.find(':') - 1);
	}
	printf("%d\n", ans);
	return 0;
}