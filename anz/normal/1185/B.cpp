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

char a[1000001], b[1000001];

int main()
{
	int n;
	scanf("%d", &n);
	while (n--)
	{
		scanf("%s", a);
		scanf("%s", b);

		int lenA = strlen(a), lenB = strlen(b);

		int ptrA = 0, ptrB = 0;
		bool flag = true;

		while (true)
		{
			if (ptrA < lenA && ptrB < lenB)
			{
				if (a[ptrA] == b[ptrB])
					ptrA++, ptrB++;
				else if (ptrB > 0 && b[ptrB] == b[ptrB - 1])
					ptrB++;
				else
				{
					flag = false;
					break;
				}
			}
			else
			{
				if (ptrB < lenB)
				{
					if(ptrB > 0 && b[ptrB] == b[ptrB - 1])
						ptrB++;
					else
					{
						flag = false;
						break;
					}
				}
				else if (ptrA < lenA)
				{
					flag = false;
					break;
				}
				else break;
			}
		}

		if (flag) printf("YES\n");
		else printf("NO\n");
	}
}