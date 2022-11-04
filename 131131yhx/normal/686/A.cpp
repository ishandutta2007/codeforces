#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, ssf = 0;

ll x;

int main()
{
	scanf("%d%lld", &n, &x);
	for(int i = 1; i <= n; i++)
	{
		char ch[11];
		ll s;
		scanf("%s%lld", ch, &s);
		if(ch[0] == '+') x += s;
		else if(x < s) ssf++; else x -= s;
	}
	printf("%lld %d\n", x, ssf);
	return 0;
}