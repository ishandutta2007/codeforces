#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 100005;

int n;
LL a[N];

void exgcd(LL a,LL b,LL &x,LL &y)
{
    if (!b)
    {
        x=1;y=0;
        return;
    }
    exgcd(b,a%b,x,y);
    LL tmp=x;
    x=y;
    y=tmp-(a/b)*y;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	if (n == 1)
	{
		printf("%d %d\n%d\n", 1, 1, -a[1]);
		for (int i = 0; i < 2; i++) printf("%d %d\n%d\n", 1, 1, 0);
		return 0;
	}
	LL x, y;
	exgcd((LL)n, (LL)n - 1, x, y);
	printf("%d %d\n", 1, n);
	for (int i = 1; i <= n; i++) printf("%lld ", -a[i] * x * n);
	puts("");
	printf("%d %d\n", 1, n - 1);
	for (int i = 1; i < n; i++) printf("%lld ", -a[i] * y * (n - 1));
	puts("");
	printf("%d %d\n", 2, n);
	for (int i = 1; i < n - 1; i++) printf("%d ", 0);
	printf("%lld\n", -a[n] * y * (n - 1));
	return 0;
}