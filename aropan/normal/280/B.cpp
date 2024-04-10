#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <stack>

using namespace std;

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }

const int MAXN = 100007;

int n;
int a[MAXN];

int main()
{
	#ifdef MJUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	
	
	int ans = 0;
	
	for (int iter = 0; iter < 2; ++iter)
	{
		stack <int> s;
		for (int i = 0; i < n; i++)
		{
			while (s.size() && s.top() < a[i])
			{
				ans = max(ans, s.top() ^ a[i]);
				s.pop();
			}
			if (s.size())
				ans = max(ans, s.top() ^ a[i]);
			s.push(a[i]);
		}
		reverse(a, a + n);
	}
	printf("%d\n", ans);
	return 0;
}