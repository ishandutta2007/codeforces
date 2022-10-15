#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <cassert>
#include <queue>

using namespace std;

const int MAXN = 200;
const int MAXM = MAXN * MAXN * 2;

const int INF = (int)2e+9;

int n, m;
int last[MAXN];
int next[MAXM], src[MAXM], dst[MAXM], flow[MAXM], cost[MAXM], back[MAXM];
string s;
int cnt[26];
int S = 0, T;

priority_queue < pair <int, int> > h;
int prev[MAXN];
int dist[MAXN];
int FLOW, COST;


void add(int x, int y, int F, int C)
{
	assert(m + 2 < MAXM);
	flow[m + 1] = F;
	cost[m + 1] = C;
	back[m + 1] = m + 2;
	src[m + 1] = x;
	dst[m + 1] = y;
	next[m + 1] = last[x];
	last[x] = m + 1;
	
	flow[m + 2] = 0;
	cost[m + 2] = -C;
	back[m + 2] = m + 1;
	src[m + 2] = y;
	dst[m + 2] = x;
	next[m + 2] = last[y];
	last[y] = m + 2;
	
	m += 2;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif
	
	cin >> s;
	FLOW = s.size();
	for (int i = 0; i < (int)s.size(); i++)
		cnt[s[i] - 'a']++;

	for (int i = 0; i < 26; i++)
		add(S, i + 1, cnt[i], 0);
		
	cin >> n;
	T = 26 + n + 1;
	assert(T < MAXN);
	
	for (int i = 0; i < n; i++)
	{
		int l;
		cin >> s >> l;
		memset(cnt, 0, sizeof(cnt));
		for (int j = 0; j < (int)s.size(); j++)
			cnt[s[j] - 'a']++;
			
		int ofs = i + 26 + 1;
		for (int j = 0; j < 26; j++)
			add(j + 1, ofs, cnt[j], 0);
		add(ofs, T, l, i + 1);
	}
	
	do
	{
		for (int i = 0; i <= T; i++)
			dist[i] = INF;
		dist[S] = 0;
		h.push(make_pair(0, S));
		
		while (h.size())
		{
			int x = h.top().second;
			int l = -h.top().first;
			h.pop();
			if (dist[x] != l) continue;
			
			for (int i = last[x]; i; i = next[i])
			{
				int y = dst[i];
				if (flow[i] > 0 && cost[i] + l < dist[y])
				{
					dist[y] = cost[i] + l;
					prev[y] = i;
					h.push(make_pair(-dist[y], y)); 
				}
			}
		}
		
		if (dist[T] == INF)
			break;
		FLOW--;
		COST += dist[T];	
		int x = T;
		while (x)
		{
			/*
			if (x != T)
			{
				if (x <= 26)
					printf("%c\n", (x + 'A' - 1));
				else
					printf("%d %c\n", ((x - 26) - 1) / 27 + 1, ((x - 26) - 1) % 27 + 'a');
			}
			//*/
			
			int i = prev[x]; 
			flow[i] -= 1;
			flow[back[i]] += 1;
			x = src[i];
		}
	} while (true);
/*	
	for (int i = last[0]; i; i = next[i])
		printf("%c %d\n", char(dst[i] + 'a' - 1), flow[i]);
//*/
	if (FLOW)
		puts("-1");
	else
		printf("%d\n", COST);
	return 0;
}