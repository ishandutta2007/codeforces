#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <set>

using namespace std;

set <int> s;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif
	set <int> *a, *b;
	a = new set <int> ();
	b = new set <int> ();
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int x;
		scanf("%d", &x);
		b->clear();
		for (set <int> :: iterator iter = a->begin(); iter != a->end(); ++iter)
		{
			b->insert((*iter) | x);
			s.insert((*iter) | x);
		}
		s.insert(x);
		b->insert(x);
		swap(a, b);
	}
	printf("%d\n", (int)s.size());
	
	return 0;
}