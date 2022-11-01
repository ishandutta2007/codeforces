#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#define fe first
#define se second

using namespace std;

const int maxn = 25;
const int g[2] = {23,37};

typedef long long ll;

char s[maxn][maxn];
ll pw[maxn];

int n;

bool equal(ll a,ll b)
{
	for(int i = 0;i < n;i ++,a /= 10,b /= 10) 
		if (s[i][a % 10] != s[i][b % 10]) return 0;
	return 1;
}

ll calc(int bit,ll a,ll b)
{
	if (a > b) swap(a,b);
	ll ans = pw[n] - b;
	if (!equal(a,b)) return 0;
	for(int i = bit;i < n;i ++)
	{
		ll cur = b / (pw[i]) * pw[i];
		ll jump = pw[i];
		for(int j = 1;j < 10;j ++)
		{
			cur += jump;
			ll step = cur - b;
			if (step >= ans) break;
			ll ano = a + step;
			if (!equal(ano,cur)) 
			{
				ans = min(ans,step);
				break;
			}
		}
	}
	return ans;
}

void work()
{
	static char st[maxn];
	scanf("%d", &n);
	scanf("%s", st);
	reverse(st,st + n);
	ll v = 0;
	pw[0] = 1;
	for(int i = 1;i <= n;i ++) pw[i] = pw[i - 1] * 10;
	for(int i = 0;i < n;i ++) v = v + (st[i] - 48) * pw[i];
	ll ans = 0;
	for(int i = n - 1;i >= 0;i --)
		scanf("%s", s[i]);
	for(int i = 0;i < n;i ++)
		for(int j = 0;j < 10;j ++)
			if (j != st[i] - 48) 
				ans = max(ans,calc(i,v,v - (st[i] - 48) * pw[i] + j * pw[i]));
	printf("%I64d\n", ans);
}

int main()
{
	int t;
	scanf("%d", &t);
	for(;t;t --) work();
	return 0;
}