#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
string s;
int nxt[500010], pre[500010];
stack<int> stk;
int cnt = 0;
int ans[500010], tot[500010];
int R;
inline int work(int u, int l, int r)
{
	if(l == r)
	{
		ans[u] = 1;
		return 1;
	}
	l++, r--;
	vector< pair<int, int> > vec;
	char c = '#';
	for(int i = l; i <= r;)
	{
		if(s[i] == '(')
		{
			int p = ++cnt;
			vec.push_back({work(p, i, nxt[i]), p});
			if(c == '#')
				c = s[nxt[i] + 1];
			i = nxt[i] + 2;
		}
		else
		{
			int p = ++cnt;
			vec.push_back({work(p, i, i), p});
			if(c == '#')
				c = s[i + 1];
			i += 2;
		}
	}
	if(c == 'S')
	{
		pair<int, int> p = {LONG_LONG_MAX, 0};
		for(auto x: vec)
			if(x < p)
				p = x;
		int res = 0;
		for(auto x: vec)
			if(x == p)
			{
				ans[x.second] = 1;
				res = x.first;
			}
			else
				ans[x.second] = 0;
		return res;
	}
	else
	{
		tot[u] = 0;
		for(auto x: vec)
		{
			int v = x.second, val = x.first;
			val = sqrt(val);
			ans[v] = -val;
			tot[u] += val;
		}
		return tot[u] * tot[u];
	}
}
const signed mod = 998244353;
inline int fastpow(int a, int n)
{
	int ans = 1;
	while(n)
	{
		if(n & 1)
			ans = ans * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return ans;
}
inline int inv(int x)
{
	return fastpow(x, mod - 2);
}
inline void Print(int u, int l, int r, int num)
{
	if(l == r)
	{
		printf(" %lld", num * R);
		return;
	}
	l++, r--;
	for(int i = l; i <= r;)
	{
		if(s[i] == '(')
		{
			int p = ++cnt;
			if(ans[p] >= 0)
				Print(p, i, nxt[i], num * ans[p] % mod);
			else
				Print(p, i, nxt[i], num * tot[u] % mod * inv(-ans[p]) % mod);
			i = nxt[i] + 2;
		}
		else
		{
			int p = ++cnt;
			if(ans[p] >= 0)
				Print(p, i, i, num * ans[p] % mod);
			else
				Print(p, i, i, num * tot[u] % mod * inv(-ans[p]) % mod);
			i += 2;
		}
	}
}
signed main()
{
	int t;
	scanf("%lld", &t);
	while(t--)
	{
		int n = 0;
		scanf("%lld", &R);
		s = "#";
		char c;
		while((c = getchar()) != '\n')
		{
			if(c != ' ')
				s += c;
			if(c == '*')
				n++;
		}
		int len = s.size() - 1;
		for(int i = 1; i <= len; i++)
			if(s[i] == '(')
				stk.push(i);
			else if(s[i] == ')')
			{
				int u = stk.top();
				stk.pop();
				nxt[u] = i, pre[i] = u;
			}
		work(cnt = 1, 1, len);
		printf("REVOLTING");
		Print(cnt = 1, 1, len, 1);
		putchar('\n');
	}
	return 0;
}