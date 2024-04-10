#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
 
const int N = 3005;
 
int n, k, ans;
int prob[N];
int suf100[N], sufHave[N];
bool vis[N][N];
int dist[N][N];
queue<pair<int, int> > q;
 
void add(int x, int y, int d)
{
	if(vis[x][y])
		return;
	if(dist[x][y] >= d)
		return;
	ans++;
	q.push({x, y});
	vis[x][y] = 1;
	dist[x][y] = d;
}
 
int work()
{
	ans = 1;
	vis[1][2] = 1;
	dist[1][2] = 0;
	q.push({1, 2});
	while(!q.empty())
	{
		pair<int, int> p = q.front();
		q.pop();
		int x = p.first, y = p.second;
		int d = dist[x][y];
		if(x >= n + 1)
			continue;
		if(y >= n + 1)
			continue;
		if(d == k)
			break;
		if(suf100[y])
		{
			if(prob[x] == 100)
				add(y + 1, y + 2, d + 1);
			else if(prob[x] > 0)
			{
				add(y + 1, y + 2, d + 1);
				add(y, y + 1, d + 1);
			}
			else
				add(y, y + 1, d + 1);
		}
		else if(sufHave[y])
		{
			if(prob[x] == 100)
			{
				add(x, y + 1, d + 1);
				add(y + 1, y + 2, d + 1);
			}
			else if(prob[x] > 0)
			{
				add(x, y + 1, d + 1);
				add(y + 1, y + 2, d + 1);
				add(y, y + 1, d + 1);
			}
			else
			{
				add(y, y + 1, d + 1);
			}
		}
		else
		{
			if(prob[x] > 0)
				add(x, y + 1, d + 1);
		}
	}
	return ans;
}
 
int32_t main()
{
	IOS;
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
		cin >> prob[i];
	for(int i = n; i >= 1; i--)
	{
		suf100[i] = suf100[i + 1] | (prob[i] == 100);
		sufHave[i] = sufHave[i + 1] | (prob[i] > 0);
	}
	cout << work();
	return 0;
}