#include <cstdio>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

map<string, int> M;
int Q = 0;
int g[22][22];
int n,m;
int A,B,C;

int get(string a)
{
	if(M.find(a) != M.end()) return M[a];
	return M[a] = Q++;
}

int iter(int i)
{
	int res = 0;
	for(int p = 0; p < 7; p++) if(i&(1<<p)) for(int q = 0; q < 7; q++) if(i&(1<<q))
		res += g[p][q];
	return res;
}

char a[22], b[22];

int main()
{
	n = 7;
	scanf("%d", &m);
	for(int i = 0; i < m; i++)
	{
		scanf("%s %*s %s", a, b);
		g[get(a)][get(b)] = 1;
	}
	scanf("%d%d%d", &A, &B, &C);
	int best = 2e9, cnt = -1;
	int all = (1<<n)-1;
	for(int i = 1; i < (1<<n); i++) for(int j = all^i; j; j=(j-1)&(all^i))
	{
		int cur = 0;
		cur += iter(i);
		cur += iter(j);
		cur += iter(all^i^j);
		int ca = __builtin_popcount(i), cb = __builtin_popcount(j), cc = 7-ca-cb;
		if(ca == 0 || cb == 0 || cc == 0) continue;
		int ra = A / ca, rb = B / cb, rc = C / cc;
		int diff = max(abs(ra-rb), max(abs(ra-rc), abs(rb-rc)));
		if(diff < best)
		{
			best = diff;
			cnt = cur;
		}
		else if(diff == best)
		{
			cnt = max(cnt, cur);
		}
	}
	printf("%d %d\n", best, cnt);
}