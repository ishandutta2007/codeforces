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

int x;
int cache[1000001];

int main()
{
	scanf("%d", &x);

	int resNum = 0;
	vector <int> result;

	while (x & (x + 1))
	{
		if (resNum % 2 == 0)
		{
			int two = 2;
			int cnt = 1;
			while (true)
			{
				if (two > x) break;
				two *= 2;
				cnt++;
			}

			two /= 2;

			while (two)
			{
				if ((x & two) == 0)
					break;
				else
					two /= 2, cnt--;
			}

			two *= 2;
			two--;

			x ^= two;

			result.push_back(cnt);
		}
		else
		{
			x++;
		}
		resNum++;	
	}

	printf("%d\n", resNum);
	for (int i = 0; i < result.size(); i++)
		printf("%d ", result[i]);
}