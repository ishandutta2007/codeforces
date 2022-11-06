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
#include <list>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <climits>
#include <cmath>
#include <functional>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

ll gcd(ll a, ll b)
{
	for (; b; a %= b, swap(a, b));
	return a;
}

int n;
char s[200001];
int depth[200001];
int main()
{
	scanf("%d", &n);
	scanf("%s", s);
	
	int d = 0;
	int md = 0;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == '(') depth[i] = ++d, md = max(md, d);
		else depth[i] = d--;
	}

	for (int i = 0; i < n; i++)
	{
		if (depth[i] > md / 2) printf("1");
		else printf("0");
	}
}