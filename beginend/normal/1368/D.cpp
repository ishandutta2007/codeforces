#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
#include<map>
using namespace std;

typedef long long LL;

const int N  = 25;

int s[N], n, bin[N];

int main()
{
	bin[0] = 1;
	for (int i = 1; i <= 20; i++) bin[i] = bin[i - 1] * 2;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		int x; scanf("%d", &x);
		for (int j = 0; j < 20; j++)
			if (x & bin[j]) s[j]++;
	}
	LL ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int w = 0;
		for (int j = 0; j < 20; j++)
			if (s[j]) s[j]--, w += bin[j];
		ans += (LL)w * w;
	}
	printf("%lld\n", ans);
	return 0;
}