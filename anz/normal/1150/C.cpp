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
#include <bitset>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

ll gcd(ll a, ll b)
{
	while (b)
	{
		for (; b; a %= b, swap(a, b));
		return a;
	}
	return a;
}

int main()
{
	int n, t;
	int cnt1 = 0, cnt2 = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &t);
		if (t == 1) cnt1++;
		else cnt2++;
	}

	if (cnt2 > 0) printf("2 "), cnt2--;
	if (cnt1 > 0) printf("1 "), cnt1--;

	int tmp = cnt1;
	if (cnt1 % 2 == 0)
	{
		for (int i = 0; i < tmp; i++) printf("1 "), cnt1--;
	}
	else
	{
		for (int i = 0; i < tmp - 1; i++) printf("1 "), cnt1--;
	}

	tmp = cnt2;
	for (int i = 0; i < tmp; i++) printf("2 "), cnt2--;
	if (cnt1 > 0) printf("1 "), cnt1--;
}