#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <map>
#include <deque>
#include <set>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main()
{
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	int p[101], s[101];
	for (int i = 0; i < n; i++)
		scanf("%d", &p[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &s[i]);

	int strongest[101] = { 0, };
	for (int i = 0; i < n; i++)
	{
		if (p[i] > strongest[s[i]])
		{
			strongest[s[i]] = p[i];
		}
	}

	int result = 0;
	for (int i = 0; i < k; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		if (p[tmp-1] < strongest[s[tmp-1]])
			result++;
	}
	printf("%d", result);
}