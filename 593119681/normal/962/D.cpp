#include <map>
#include <set>
#include <queue>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 150000 + 5

int n, tot, cnt;
LL A[N];
bool Flag[N];
map <LL, int> Map;
set <int> s[N << 1];
set <int> :: iterator it, _it;
priority_queue <LL> Q;

inline int Get(LL x)
{
	if (Map.find(x) != Map.end())
		return Map[x];
	Map[x] = ++ tot;
	Q.push(-x);
	return tot;
}

int main()
{
	scanf("%d", &n);
	cnt = n;
	for (int i = 1; i <= n; i ++)
	{
		scanf("%lld", A + i);
		s[Get(A[i])].insert(i);
	}
	while (!Q.empty())
	{
		LL x = -Q.top();
		Q.pop();
		int t = Get(x);
		for (it = s[t].begin(); it != s[t].end(); it = _it, it ++)
		{
			_it = it, _it ++;
			if (_it == s[t].end()) break ;
			int u = *it, v = *_it;
			Flag[u] = 1, cnt --;
			A[v] += A[u];
			s[Get(A[v])].insert(v);
		}
	}
	printf("%d\n", cnt);
	for (int i = 1, t = 1; i <= n; i ++)
		if (!Flag[i])
			printf("%lld%c", A[i], t == cnt ? '\n' : ' '), t ++;
	return 0;
}