#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, a[200010], m, am;
int main()
{	
	scanf("%lld%lld", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &a[i]);
		am += a[i];
		printf("%lld ", am / m);
		am %= m;
	}
	printf("\n");
}