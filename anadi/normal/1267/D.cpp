#include <bits/stdc++.h>
using namespace std;

typedef bitset<3> bs;

const int N = 257, K = 8;
bs need[N];
bs test[N];
bool ct[N];
int r[K][K];
vector<int> from[K];

bs readbs()
{
	bs ans;
	for(int i: { 0, 1, 2 })
	{
		int k;
		scanf("%d", &k);
		ans[i] = k;
	}
	return ans;
}

bool operator<(bs a, bs b)
{
	return a.to_ulong() < b.to_ulong();
}

int ind(bs x)
{
	return x.to_ulong();
}

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		need[i] = readbs();
	for(int i = 1; i <= n; i++)
		test[i] = readbs() & need[i];
	ct[1] = true;
	for(int i = 2; i <= n; i++)
		if((need[i] & test[1]) != need[i])
		{
			ct[1] = false;
			test[1] = need[1];
		}
	for(int i = 1; i <= n; i++)
	{
		int a = ind(need[i]), b = ind(test[i]);
		if(r[a][b] == 0)
			r[a][b] = i;
	}
	queue<int> q;
	q.push(ind(test[1]));
	from[ind(test[1])] = {1};
	while(!q.empty())
	{
		auto k = q.front();
		q.pop();
		for(int i = 0; i < K; i++)
			if(from[i].empty() && r[k][i])
			{
				from[i] = { r[k][i] };
				q.push(i);
				ct[r[k][i]] = true;
			}
		for(int i = 0; i < K; i++)
			if(!from[i].empty())
				for(int a = 0; a < K; a++)
					for(int b = 0; b < K; b++)
						if(r[i][a] && r[k][b] && from[a|b].empty())
						{
							from[a|b] = { r[i][a], r[k][b] };
							q.push(a|b);
							ct[r[i][a]] = ct[r[k][b]] = true;
						}
	}
	vector<pair<int, int>> cd;
	for(int i = 2; i <= n; i++)
	{
		int k = ind(need[i]);
		if(from[k].empty())
		{
			puts("Impossible");
			return 0;
		}
		for(auto f: from[k])
			cd.emplace_back(f, i);
		if(!ct[i]) from[k] = { i };
	}	
	puts("Possible");
	for(int i = 1; i <= n; i++)
		printf("%d ", ct[i]);
	puts("");
	printf("%d\n", cd.size());
	for(auto p: cd)
		printf("%d %d\n", p.first, p.second);
}