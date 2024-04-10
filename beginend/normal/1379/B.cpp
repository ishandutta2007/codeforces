#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

LL l, r, m;

bool check(LL a)
{
	int L = l - r, R = r - l;
	if (m % a == 0 || a - m % a <= R || m > a && m % a <= R)
	{
		LL b, c, d;
		if (m % a == 0) d = 0;
		else if (a - m % a <= R) d = a - m % a;
		else d = -(m % a);
		if (d >= 0) b = l, c = l + d;
		else b = r, c = b + d;
		printf("%lld %lld %lld\n", a, b, c);
		return 1;
	}
	else return 0;
}

int main()
{
	int T; scanf("%d", &T);
	while (T--)
	{
		scanf("%lld%lld%lld", &l, &r, &m);
		for (LL a = l; a <= r; a++)
			if (check(a)) break;
	}
}