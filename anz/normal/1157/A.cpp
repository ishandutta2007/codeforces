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
	int result = 0;
	int n;
	scanf("%d", &n);
	while (n)
	{
		if (n < 10)
		{
			result += 9;
			break;
		}
		result++;
		n++;
		if (n % 10 == 0)
		{
			while (n % 10 == 0)
				n /= 10;
		}
	}
	printf("%d", result);
}