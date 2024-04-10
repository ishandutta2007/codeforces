#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <math.h>
#include <vector>
#include <cstring>
#include <ctime>
#include <set>
#include <bitset>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <ctime>
#include <cassert>
#define fr first
#define sc second
#define MP make_pair
#define PB push_back
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
#define lli long long int
#define y1 arayikhalatyan
#define j1 jiglypuff
#define ld long double
using namespace std;

lli gcd(lli a, lli b) { return (b == 0 ? a : gcd(b, a % b)); }

char vow[] = { 'a', 'e', 'i', 'o', 'u' };
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };



const int N = 1e5 + 30;
const lli mod = 1e9 + 7;

int n, m;
vector <int> g[N];
bool col[N];
int pat;
vector <int> sm;
void bfs(int v)
{
	queue <int> q;
	q.push(v);
	col[v] = true;
	while (!q.empty())
	{
		//cout << v;
		v = q.front();
		q.pop();
		for (int i = 0; i < sm.size(); i++)
		{
			//cout << g[v].size() << " " << g[v].back();
			if (g[v].size() && (g[v].back() >= sm[i]))
			{
				//cout << v << " " << sm[i] << " ";
				//cout << *upper_bound(g[v].begin(), g[v].end(), sm[i] - 1) << endl;
				if(*upper_bound(g[v].begin(), g[v].end(), sm[i] - 1) == sm[i]) continue;
			}
			col[sm[i]] = true;
			q.push(sm[i]);
			swap(sm[i], sm.back());
			sm.pop_back();
			--i;
			//cout << "!";
			
		}
	}
}
int main()
{
	fastio;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		g[a].PB(b);
		g[b].PB(a);
	}
	for (int i = 1; i <= n; i++)
	{
		sort(g[i].begin(), g[i].end());
		sm.PB(i);
	}
	//cout << "!";
	for (int i = 0; i < sm.size(); i++)
	{
		pat++;
		//cout << sm[i];
		int ss = sm[i];
		swap(sm[i], sm.back());
		sm.pop_back();
		bfs(ss);
		i--;
	}
	cout << pat - 1;
	return 0;
}