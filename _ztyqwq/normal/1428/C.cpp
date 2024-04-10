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
		int ans = 0, i = 1, j = 1;
		while(i <= n && j <= n)
		{
			while(s[i] != 'A' && i <= n)
				i++;
			while(j <= i && j <= n)
			{
				if(s[j] == 'B')
					ans++;
				j++;
			}
			if(j > n)
				break;
			while(s[j] != 'B' && j <= n)
				j++;
			if(j > n)
				break;
			ans += 2;
			i++, j++;
		}
		if(ans & 1)
			ans--;
		printf("%d\n", n - ans);
	}
	return 0;
}