#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <set>

using namespace std;

set <int> s;
int main() {
	int n;
	int t;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &t), s.insert(t);
	if (s.size() > 3)
		printf("-1");
	else
	{
		if (s.size() <= 1)
			printf("0");
		else if (s.size() == 2)
		{
			set <int>::iterator i = s.begin();
			int first = *i;
			i++;
			int second = *i;

			if ((second - first) & 1)
				printf("%d", second - first);
			else
				printf("%d", (second - first) / 2);
		}
		else
		{
			int lastNum = *(s.begin());
			set <int>::iterator i;
			bool flag = true;
			int diff = 0;
			for (i = s.begin(); i != s.end(); i++)
			{
				if (i == s.begin()) continue;
				int cdiff = (*i) - lastNum;
				if (diff != 0 && diff != cdiff)
					flag = false;
				diff = cdiff;
				lastNum = (*i);
			}

			if (flag)
				printf("%d", diff);
			else
				printf("-1");
		}
	}
}