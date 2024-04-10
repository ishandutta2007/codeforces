#include <bits/stdc++.h>

using namespace std;

struct trie
{
	static const int sigma = 26;
	vector<int> link, to[sigma], term, sum, cnt;
	int sz = 0;
	
	int add_state()
	{
		link.push_back(0);
		term.push_back(0);
		cnt.push_back(0);
		sum.push_back(0);
		for(int c = 0; c < sigma; c++)
			to[c].push_back(0);
		return sz++;
	}
	
	trie()
	{
		add_state();
	}
	
	int add_str(string &s)
	{
		int v = 0;
		for(auto c: s)
		{
			
			c -= 'a';
			if(!to[c][v])
			{
				add_state();
				to[c][v] = sz - 1;
			}
			v = to[c][v];
		}
		term[v] = v;
		cnt[v]++;
		return v;
	}
	
	void push_links()
	{
		deque<int> q(1, 0);
		while(!q.empty())
		{
			int v = q.front();
			q.pop_front();
			int u = link[v];
			if(!term[v])
				term[v] = term[u];
			cnt[v] += cnt[u];
			for(int c = 0; c < sigma; c++)
			{
				if(to[c][v])
				{
					link[to[c][v]] = v ? to[c][u] : 0;
					q.push_back(to[c][v]);
				}
				else
				{
					to[c][v] = to[c][u];
				}
			}
		}
	}
	
	vector<int> clear_log;
	void feed(string &s)
	{
		for(auto it: clear_log)
			sum[it] = 0;
		clear_log.clear();
		int v = 0;
		for(auto c: s)
		{
			c -= 'a';
			v = to[c][v];
			for(int u = term[v]; u; u = term[link[u]])
			{
				sum[u]++;
				clear_log.push_back(u);
			}
		}
	}
	
	int ffeed(string &s)
	{
		int v = 0;
		int ret = 0;
		for(auto c: s)
		{
			c -= 'a';
			v = to[c][v];
			ret += cnt[v];
		}
		return ret;
	}
};
	
const int root = 1500;
const int bc = 75;
trie all;
trie block[bc];

signed main()
{
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, q;
	cin >> n >> q;
	string s[n];
	int v[n];
	int i = 0;
	for(int z = 0; z < bc; z++)
	{
		for(int j = 0; i < n && j < root; i++, j++)
		{
			cin >> s[i];
			v[i] = all.add_str(s[i]);
			block[z].add_str(s[i]);
		}
		block[z].push_links();
	}
	all.push_links();
	vector<int> Q[n];
	int l[q], r[q], k[q];
	for(int i = 0; i < q; i++)
	{
		cin >> l[i] >> r[i] >> k[i];
		l[i]--, r[i]--, k[i]--;
		Q[k[i]].push_back(i);
	}
	int64_t ns[q];
	memset(ns, 0, sizeof(ns));
	for(int i = 0; i < n; i++)
	{
		all.feed(s[i]);
		int cnt_blocks[bc];
		memset(cnt_blocks, 0, sizeof(cnt_blocks));
		for(int z = 0; z < bc; z++)
			cnt_blocks[z] = block[z].ffeed(s[i]);
		for(auto query: Q[i])
		{
			int L = l[query], R = r[query];
			int Lb = L / root + 1, Rb = R / root - 1;
			int64_t ans = 0;
			for(int z = Lb; z <= Rb; z++)
				ans += cnt_blocks[z];
			if(Lb <= Rb)
			{
				for(int z = L; z < Lb * root; z++)
					ans += all.sum[v[z]];
				for(int z = (Rb + 1) * root; z <= R; z++)
					ans += all.sum[v[z]];
			}
			else
			{
				for(int z = L; z <= R; z++)
					ans += all.sum[v[z]];
			}
			ns[query] = ans;
		}
	}
	for(int i = 0; i < q; i++)
		cout << ns[i] << "\n";
	
	return 0;
}