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


const int N = 2e6 + 30;
int mod = 600;

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
ld dist(ld x1, ld y1, ld x2, ld y2)
{
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

string s;
int n, i1, qan;
int t1[4 * N], t2[4 * N];
int flag[4 * N];
void push(int nd)
{
	t1[nd] += flag[nd];
	t2[nd] += flag[nd];
	flag[2 * nd] += flag[nd];
	flag[2 * nd + 1] += flag[nd];
	flag[nd] = 0;
}
void upd(int val, int ql, int qr = n, int nl = 0, int nr = n, int nd = 1)
{
	push(nd);
	if (ql > nr || qr < nl) return;
	if (ql == nl && qr == nr)
	{
		flag[nd] += val;
		push(nd);
		return;
	}
	int mid = (nl + nr) / 2;
	upd(val, ql, min(mid, qr), nl, mid, nd * 2);
	upd(val, max(mid + 1, ql), qr, mid + 1, nr, nd * 2 + 1);
	t1[nd] = max(t1[nd * 2], t1[nd * 2 + 1]);
	t2[nd] = min(t2[nd * 2], t2[nd * 2 + 1]);
}
int main()
{
	fastio;
	cin >> n;
	for (int i = 0; i < 2 * n; i++) s += "#";
	for (int i = 0; i < n; i++)
	{
		char A;
		cin >> A;
		if (A == 'R') i1++;
		else if (A == 'L') i1 = max(0, i1 - 1);
		else
		{
			if (s[i1] == ')') upd(1, i1, n), qan++;
			else if (s[i1] == '(') upd(-1, i1, n), qan--;
			s[i1] = A;
			if (A == '(') upd(1, i1, n), qan++;
			else if (A == ')') upd(-1, i1, n), qan--;
		}
		push(1);
		if (t2[1] < 0 || qan != 0)
			cout << -1 << " ";
		else
			cout << t1[1] << " ";
	}
	return 0;
}