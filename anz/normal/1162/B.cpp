#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <bitset>
#include <list>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

ll gcd(ll a, ll b)
{
	for (; b; a %= b, swap(a, b));
	return a;
}
int n, m;
int m1[51][51], m2[51][51];


int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
		scanf("%d", &m1[i][j]);
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
		scanf("%d", &m2[i][j]);

	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
	{
		if (m1[i][j] > m2[i][j]) swap(m1[i][j], m2[i][j]);
	}

	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
	{
		if (i != 0)
		{
			if (m1[i - 1][j] >= m1[i][j] || m2[i - 1][j] >= m2[i][j])
			{
				printf("Impossible");
				return 0;
			}
		}

		if (j != 0)
		{
			if (m1[i][j - 1] >= m1[i][j] || m2[i][j-1] >= m2[i][j])
			{
				printf("Impossible");
				return 0;
			}
		}
	}
	printf("Possible");
}