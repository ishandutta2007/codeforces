#include <bits/stdc++.h>

using namespace std;
	
const int maxn = 1e5 + 42, sigma = 26;

int cnt[4 * maxn][26];
int to_push[4 * maxn];

void push(int v, int l, int r)
{
	if(to_push[v] == -1)
		return;
	int c = to_push[v];
	memset(cnt[v], 0, sizeof(cnt[v]));
	cnt[v][c] = r - l;
	to_push[v] = -1;
	if(r - l == 1)
		return;
	to_push[2 * v + 1] = to_push[2 * v + 2] = c;
}

void upd(int a, int b, int c, int v = 0, int l = 0, int r = maxn)
{
	if(r <= a || b <= l)
		return;
	push(v, l, r);
	if(a <= l && r <= b)
	{
		to_push[v] = c;
		return;
	}
	int m = (l + r) / 2;
	upd(a, b, c, 2 * v + 1, l, m);
	upd(a, b, c, 2 * v + 2, m, r);
}

void rebuild(int a, int b, int v = 0, int l = 0, int r = maxn)
{
	if(to_push[v] != -1)
	{
		push(v, l, r);
		return;
	}
	if(r <= a || b <= l)
		return;
	int m = (l + r) / 2;
	rebuild(a, b, 2 * v + 1, l, m);
	rebuild(a, b, 2 * v + 2, m, r);
	for(int c = 0; c < sigma; c++)
		cnt[v][c] = cnt[2 * v + 1][c] + cnt[2 * v + 2][c];
}

void get(int a, int b, int *c, int v = 0, int l = 0, int r = maxn)
{
	push(v, l, r);
	if(a <= l && r <= b)
	{
		for(int ch = 0; ch < sigma; ch++)
			c[ch] += cnt[v][ch];
		return;
	}
	if(r <= a || b <= l)
		return;
	int m = (l + r) / 2;
	get(a, b, c, 2 * v + 1, l, m);
	get(a, b, c, 2 * v + 2, m, r);
}
	
signed main() 
{
	memset(to_push, -1, sizeof(to_push));
	memset(cnt, 0, sizeof(cnt));
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	for(int i = 0; i < n; i++)
		upd(i, i + 1, s[i] - 'a');
	rebuild(0, n);
	while(m--)
	{
		int l, r;
		cin >> l >> r;
		l--;
		int cnt[sigma];
		memset(cnt, 0, sizeof(cnt));
		get(l, r, cnt);
		vector<int> chars[2];
		for(int c = 0; c < sigma; c++)
		{
			chars[0].push_back(c);
			if(cnt[c] % 2 == 1)
				chars[1].push_back(c);
		}
		if(chars[1].size() > 1)
			continue;
		int cl = l;
		int cr = r;
		for(auto it: chars[0])
		{
			upd(cl, cl + cnt[it] / 2, it);
			upd(cr - cnt[it] / 2, cr, it);
			cl += cnt[it] / 2;
			cr -= cnt[it] / 2;
		}
		for(auto it: chars[1])
			upd(cl, cr, it);
		rebuild(l, r);
	}
	for(int i = 0; i < n; i++)
	{
		int it[sigma];
		memset(it, 0, sizeof(it));
		get(i, i + 1, it);
		cout << char('a' + (max_element(it, it + sigma) - it));
	}
}