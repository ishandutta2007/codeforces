#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a, b;
int main()
{
	scanf("%I64d%I64d", &b, &a);
	ll c = 1;
	for (int i = 0; i < b && c <= a; i++)
	{
		c*=2;
	}
	printf("%I64d\n", a%c);
}