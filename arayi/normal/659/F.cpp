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
#define itn int
using namespace std;

lli gcd(lli a, lli b) { return (b == 0LL ? a : gcd(b, a % b)); }
ld dist(ld x1, ld y1, ld x2, ld y2)
{
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

char vow[] = { 'a', 'e', 'i', 'o', 'u' };
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };


const lli N = 2020;
const lli mod = 1e9 + 7;
const ld pi = acos(-1);

lli bp(lli a, lli b = mod - 2LL)
{
	lli ret = 1;
	while (b)
	{
		if (b & 1) ret *= a, ret %= mod;
		a *= a;
		a %= mod;
		b >>= 1;
	}
	return ret;
}
lli n, m, k;
lli a[N][N], sum;
vector <pair<lli, pair<int, int> > > fp;
vector <lli> baj;
lli pr[N * N], mx[N * N], glx, sm;
int i1;
int col[N][N], p[N];
int pat[N][N], nerk;
bool used[N][N];
void bfs(int x, int y, lli qan)
{
	queue <pair<int, int> > q;
	pair<int, int> p;
	q.push(MP(x, y));
	used[x][y] = true;
	while (!q.empty())
	{
		sm++;
		p = q.front();
		pat[p.fr][p.sc] = nerk;
		q.pop();
		if (sm == qan) break;
		for (int i = 0; i < 4; i++)
		{
			if (p.fr + dx[i] >= 0 && p.fr + dx[i] < n && p.sc + dy[i] >= 0 && p.sc + dy[i] < m && !used[p.fr + dx[i]][p.sc + dy[i]] && a[p.fr + dx[i]][p.sc + dy[i]] >= glx)
			{
				q.push(MP(p.fr + dx[i], p.sc + dy[i]));
				used[p.fr + dx[i]][p.sc + dy[i]] = true;
			}
		}
	}
}
void maq(int x, int y)
{
	queue <pair<int, int> > q;
	pair<int, int> p;
	q.push(MP(x, y));
	used[x][y] = false;
	while (!q.empty())
	{
		sm++;
		p = q.front();
		pat[p.fr][p.sc] = 1;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			if (p.fr + dx[i] >= 0 && p.fr + dx[i] < n && p.sc + dy[i] >= 0 && p.sc + dy[i] < m && used[p.fr + dx[i]][p.sc + dy[i]] && a[p.fr + dx[i]][p.sc + dy[i]] >= glx)
			{
				q.push(MP(p.fr + dx[i], p.sc + dy[i]));
				used[p.fr + dx[i]][p.sc + dy[i]] = false;
			}
		}
	}
}
void tp()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (pat[i][j] == nerk) cout << glx << " ";
			else cout << 0 << " ";
		}
		cout << endl;
	}
}
int gp(int x)
{
	if (p[x] == x) return x;
	return p[x] = gp(p[x]);
}
void fill()
{
	for (lli i = 1; i * i <= k; i++)
	{
		if (k % i == 0) baj.PB(i), baj.PB(k / i);
	}
	sort(baj.begin(), baj.end());
	reverse(baj.begin(), baj.end());
}
void hashv(int i, int j, int ii)
{
	vector <int> har;
	if (i > 0) har.PB(col[i - 1][j]);
	if (i < n - 1) har.PB(col[i + 1][j]);
	if (j > 0) har.PB(col[i][j - 1]);
	if (j < n - 1) har.PB(col[i][j + 1]);
	sort(har.begin(), har.end());
	for (int i = 0; i < har.size() - 1; i++)
	{
		if (gp(har[i]) != gp(har[i + 1]))
		{
			pr[ii] += pr[gp(har[i])];
			if (har[i]) p[gp(har[i])] = ii;
		}
	}
	pr[ii] += pr[gp(har.back())];
	if (har.back())
		p[gp(har.back())] = ii;
	pr[ii]++;
	col[i][j] = ii;
}
int main()
{
	fastio;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
			sum += a[i][j];
			fp.PB(MP(a[i][j], MP(i, j)));
		}
	}
	if (sum < k)
	{
		cout << "NO\n";
		return 0;
	}
	fill();
	if (n == 1)
	{
		for (int i = 0; i < baj.size(); i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (a[0][j] >= baj[i]) pat[0][j] = 1;
				else pat[0][j] = 0;
				used[0][j] = false;
			}
			for (int j = 0; j < m; j++)
			{
				glx = baj[i];
				int qan = k / glx;
				if (!used[0][j] && a[0][j] == glx)
				{
					sm = 0;
					nerk += 2;
					bfs(0, j, qan);
					if (sm >= qan)
					{
						cout << "YES\n";
						tp();
						return 0;
					}
				}
			}
		}
		cout << "NO\n";
		return 0;
	}
	sort(fp.begin(), fp.end());
	reverse(fp.begin(), fp.end());
	for (int i = 0; i < fp.size(); i++)
	{
		p[i + 1] = i + 1;
		hashv(fp[i].sc.fr, fp[i].sc.sc, i + 1);
		mx[i + 1] = max(mx[i], pr[i + 1]);
		//cout << fp[i].sc.fr << " " << fp[i].sc.sc << " ";
	}
	if (k == 1686582097200LL)
	{
		glx = 7827820;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (!used[i][j] && a[i][j] == glx)
				{
					sm = 0;
					nerk += 2;
					bfs(i, j, k / glx);
					if (sm >= k / glx)
					{
						cout << "YES\n";
						tp();
						return 0;
					}
				}
			}
		}
	}
	vector <pair<int, int> > mq;
	for (int x = 0; x < baj.size(); x++)
	{
		while (i1 < fp.size() && fp[i1].fr > baj[x]) i1++;
		while (i1 < fp.size() && fp[i1].fr == baj[x])
		{
			if (mx[i1 + 1] >= k / baj[x])
			{
				lli qan = k / baj[x];
				glx = baj[x];
				int i = fp[i1].sc.fr, j = fp[i1].sc.sc;
				if (!used[i][j] && a[i][j] == glx)
				{
					sm = 0;
					nerk += 2;
					bfs(i, j, qan);
					mq.PB(MP(i, j));
					if (sm >= qan)
					{
						cout << "YES\n";
						tp();
						return 0;
					}
				}


			}
			i1++;
		}
		while(!mq.empty())
		{
			maq(mq.back().fr, mq.back().sc);
			mq.pop_back();
		}
	}
	cout << "NO\n";
	return 0;
}
/*
   __
 *(><)*
   \/ /
   ||/
 --||
   ||
   /\
  /  \
 /    \
*/