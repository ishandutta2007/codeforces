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

int main()
{
	int n, M;
	scanf("%d%d", &n, &M);
	int sum = 0;
	priority_queue <int> q;
	for (int i = 0; i < n; i++)
	{
		priority_queue <int> tq = q;
		int t, fails = 0;
		scanf("%d", &t);
		sum += t;

		int curSum = sum;
		while (curSum > M)
		{
			curSum -= tq.top(); tq.pop();
			fails++;
		}
		q.push(t);
		printf("%d ", fails);
	}
}