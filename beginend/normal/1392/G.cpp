#include<bits/stdc++.h>
using namespace std;

const int N = 1000005;
const int M = 1048580;
const int K = 25;

int n, m, k, bin[K], to[K], a[N], b[N], lef[M], rig[M], cnt[M];
char str[K];

void MIN(int & x, int y) {x = min(x, y);}
void MAX(int & x, int y) {x = max(x, y);}

int main()
{
	scanf("%d%d%d", &n, &m, &k);
	bin[0] = 1;
	for (int i = 1; i <= k; i++) bin[i] = bin[i - 1] * 2;
	int con = k, s = 0, t = 0;
	scanf("%s", str);
	for (int i = 0; i < k; i++) s += (str[i] - '0') * bin[i], con -= str[i] == '1';
	scanf("%s", str);
	for (int i = 0; i < k; i++) t += (str[i] - '0') * bin[i], con -= str[i] == '1';
	for (int i = 0; i < k; i++) to[i] = i;
	a[0] = s; b[0] = t;
	for (int i = 1; i <= n; i++)
	{
		int x, y; scanf("%d%d", &x, &y);
		swap(to[x - 1], to[y - 1]);
		for (int j = 0; j < k; j++)
		{
			if (s & bin[j]) a[i] += bin[to[j]];
			if (t & bin[j]) b[i] += bin[to[j]];
		}
	}
	for (int i = 0; i < bin[k]; i++) lef[i] = n + 1, rig[i] = 0, cnt[i] = cnt[i >> 1] + (i & 1);
	for (int i = 0; i <= n; i++) lef[a[i]] = min(lef[a[i]], i), rig[b[i]] = max(rig[b[i]], i);
	for (int i = bin[k] - 1; i; i--)
		for (int j = 0; j < k; j++)
			if (i & bin[j]) MIN(lef[i ^ bin[j]], lef[i]), MAX(rig[i ^ bin[j]], rig[i]);
	int mx = 0;
	for (int i = 0; i < bin[k]; i++)
		if (rig[i] - lef[i] >= m && cnt[i] > cnt[mx]) mx = i;
	printf("%d\n", cnt[mx] * 2 + con);
	printf("%d %d\n", lef[mx] + 1, rig[mx]);
	return 0;
}