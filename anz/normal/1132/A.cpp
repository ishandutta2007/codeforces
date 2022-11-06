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

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main()
{
	int a, b, c, d;
	scanf("%d%d%d%d", &a, &b, &c, &d);

	bool flag = true;
	if (a != d) flag = false;
	if (flag)
	{
		if (c > 0)
		{
			if (a == 0)
				flag = false;
		}
	}
	if (flag) printf("1");
	else printf("0");
	
}