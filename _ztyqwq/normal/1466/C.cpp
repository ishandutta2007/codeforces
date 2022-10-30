#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		string s;
		cin >> s;
		int n = s.size();
		s = " " + s;
		int ans = 0;
		for(int i = 2; i <= n; i++)
			if(s[i] == s[i - 1] || s[i] == s[i - 2])
				ans++, s[i] = '#';
		printf("%d\n", ans);
	}
	return 0;
}