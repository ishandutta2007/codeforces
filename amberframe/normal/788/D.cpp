#include <bits/stdc++.h>

#define pb push_back
#define rep(i, n) for (int i = 1 ; i <= (n) ; i++)
#define per(i, n) for (int i = (n) ; i >= 1 ; i--)
#define repi(n) for (int i = 1; i <= (n) ; i++)
#define mabs(n) ((n) > 0 ? (n) : (-n))
#define print(V) for (auto v: V) printf("%d ",v)
using namespace std;
typedef long long LL ;
const int maxn = 1e5 + 5;
const int mod = 1e8;

vector<int> ver, hor;

int f(int x, int y)
{
	printf("0 %d %d\n", x, y);
	fflush(stdout);
	int d; scanf("%d", &d); return d;
}
int main()
{
	#ifdef FILE_TESTn
		freopen("lines.in", "r", stdin);
	#endif
	
	int t = rand() % mod;
	while (f(t, t) == 0) t = rand() % mod;
	int cur = -mod;
	while (cur <= mod)
	{
		int res;
		while (cur <= mod && (res = f(cur, cur)) != 0)
			cur += res;
		if (cur > mod) break;
		if (f(cur, t) == 0) ver.pb(cur);
		if (f(t, cur) == 0) hor.pb(cur);
		if (cur + 1000 <= mod && f(cur + 1000, cur + 1000) >= 1000) cur += 1000; else ++cur;
	}
	printf("1 %d %d\n", ver.size(), hor.size());
	print(ver); printf("\n");
	print(hor); printf("\n");
	fflush(stdout);
	return 0;
}