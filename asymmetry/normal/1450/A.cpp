#include <bits/stdc++.h>

using namespace std;

char s[1000];

void solve()
{
	int n;
	scanf("%d", &n);
	scanf("%s", s);
	sort(s, s+n);
	//~ reverse(s, s+n);
	for(int i=0; i<n; ++i)
	{
		printf("%c", s[i]);
	}
	printf("\n");
}

int main()
{
	int q;
	scanf("%d", &q);
	while(q--)
	{
		solve();
	}
	return 0;
}