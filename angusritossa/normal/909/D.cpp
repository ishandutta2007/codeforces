#include <bits/stdc++.h>
using namespace std;
bool shouldberemd[1000010];
vector<int> rem;
map<int, char> m;
char is[1000010];
bool inq[1000010];
int n;
void checkifshouldbe(int a)
{
	if (a == -1 || inq[a]) return;
	char c = is[a];
	bool works = true;
	auto it = m.find(a);
	if (it != m.begin())
	{
		auto save = it--;
		if (it->second != c) works = false;
		it = save;
	}
	it++;
	if (it != m.end())
	{
		if (it->second != c) works = false;
	}
//	printf("%d %d %d\n", a, works, m.size);
//	if (!works && shouldberemd[a]) return;
	shouldberemd[a] = !works;
	if (shouldberemd[a]) rem.push_back(a);
}
int main()
{
	scanf(" %s", is);
	n = strlen(is);
	for (int i = 0; i < n; i++) m[i] = is[i];
	for (int i = 0; i < n; i++)
	{
		checkifshouldbe(i);
	}
	for (int i = 0; true; i++)
	{
		vector<int> newrem = rem;
		rem.clear();
		int did = 0;
		for (int a : newrem)
		{
			if (!shouldberemd[a] && !inq[a]) continue;
			inq[a] = true;
			m.erase(a);
		}
		for (int a : newrem)
		{
			if (!shouldberemd[a]) continue;
			inq[a] = false;
			did++;
			auto it = m.lower_bound(a);

			int pre, after;
			pre = after = -1;
			if (it != m.end())
			{
				pre = it->first;
			}
			if (it != m.begin())
			{
				it--;
				after = it->first;
			}
			checkifshouldbe(pre);
			checkifshouldbe(after);
			shouldberemd[a] = false;
		}
		if (!did)
		{
			printf("%d\n", i);
			return 0;
		}
	//	printf("\nsize %d\n", m.size());
	}
}