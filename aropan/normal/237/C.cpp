#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <queue>

using namespace std;

int a, b, k;
queue <int> q;

const int MAXF = 1000003;
bool f[MAXF];

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif
	f[1] = f[0] = true;
	for (int i = 2; i * i < MAXF; i++)
		if (!f[i])
			for (int j = i * i; j < MAXF; j += i)
				f[j] = true;
	scanf("%d %d %d\n", &a, &b, &k);
	int ans = -1;
	bool flg = false;
	q.push(a - 1);
	for (int i = a; i <= b; i++)
		if (!f[i])
		{
			q.push(i);
			if ((int)q.size() == k + 1)
			{
				ans = max(ans, i - q.front());
				flg = true;
				q.pop();
			}
		}
	if (!flg)
	{
		puts("-1");
		return 0;
	}
	ans = max(ans, b + 1 - q.front());
	printf("%d\n", ans);
	return 0;
}