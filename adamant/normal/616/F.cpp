#include <bits/stdc++.h>

using namespace std;

#define int int64_t

const int maxn = 1e6 + 42;
map<char, int> to[maxn];
int len[maxn], link[maxn], cnt[maxn];
int last, sz = 1;

void add_letter(char c)
{
	int p = last;
	if(to[p][c])
    {
        if(len[p] + 1 == len[to[p][c]])
        {
            last = to[p][c];
            return;
        }
    }
	last = sz++;
	len[last] = len[p] + 1;
	for(; to[p][c] == 0; p = link[p])
		to[p][c] = last;
	if(to[p][c] == last)
		return;
	int q = to[p][c];
	if(len[q] == len[p] + 1)
	{
		link[last] = q;
		return;
	}
	int cl = sz++;
	to[cl] = to[q];
	link[cl] = link[q];
	len[cl] = len[p] + 1;
	link[last] = link[q] = cl;
	for(; to[p][c] == q; p = link[p])
		to[p][c] = cl;
}

signed main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	string s[n];
	for(int i = 0; i < n; i++)
		cin >> s[i];
	int c[n];
	for(int i = 0; i < n; i++)
	{
		cin >> c[i];
		for(auto it: s[i])
		{
			add_letter(it);
			cnt[last] += c[i];
		}
		last = 0;
	}
	vector<int> g[maxn];
	for(int i = 1; i < sz; i++)
		g[len[i]].push_back(i);
	int ans = 0;
	for(int i = maxn - 1; i >= 0; i--)
		for(auto v: g[i])
		{
			cnt[link[v]] += cnt[v];
			ans = max(ans, cnt[v] * len[v]);
		}

	cout << ans << "\n";

}