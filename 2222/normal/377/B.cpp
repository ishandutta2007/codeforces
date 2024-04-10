#include <algorithm>
#include <iostream>
#include <assert.h>
#include <sstream>
#include <complex>
#include <numeric>
#include <cstring>
#include <vector>
#include <string>
#include <cstdio>
#include <queue>
#include <cmath>
#include <map>
#include <set>

using namespace std;

#define all(a)			(a).begin(), (a).end()
#define sz(a)			int((a).size())
#define FOR(i, a, b)	for (int i(a); i < b; ++i)
#define REP(i, n)		FOR(i, 0, n)
#define UN(v)			sort(all(v)), (v).erase(unique((v).begin(), (v).end()), (v).end())
#define CL(a, b)		memset(a, b, sizeof a)
#define pb				push_back
#define X				first
#define Y				second

typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> pii;

int n, m, s;
struct student { int exp, cost, i; } b[100500];

pii a[100500];
int match[100500];

bool can(int days)
{
	std::priority_queue<pii> Q;
	int j = 0, cost = 0;
	REP (i, n + 1)
	{
		while (i >= n || b[i].exp < a[j].X)
		{
			if (Q.empty())
				return false;
			int id = Q.top().Y;
			Q.pop();
			cost += b[id].cost;
			if (cost > s)
				return false;
			REP (k, days)
			{
				match[a[j++].Y] = b[id].i;
				if (j >= m) return true;
			}
		}
		if (i < n) Q.push({-b[i].cost, i});
	}
	return false;
}

int main() {
    #ifdef LocalHost
    freopen("x.in", "r", stdin);
    #endif
    cin >> n >> m >> s;
	REP (i, m) {
		cin >> a[i].X;
		a[i].Y = i;
	}
	REP (i, n) {
		cin >> b[i].exp;
		b[i].i = i;
	}
	REP (i, n) cin >> b[i].cost;
	sort(a, a + m, greater<pii>());
	sort(b, b + n, [](const student &p, const student &q) { return p.exp > q.exp; });
	int L = 0, R = m;
	for (; L <= R; )
	{
		int v = (L + R) / 2;
		can(v) ? R = v - 1 : L = v + 1;
	}
	if (can(L))
	{
		puts("YES");
		REP (i, m)
		{
			if (i) putchar(' ');
			cout << match[i] + 1;
		}
		cout << endl;
	}
	else puts("NO");
    return 0;
}