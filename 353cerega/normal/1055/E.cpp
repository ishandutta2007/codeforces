#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <memory.h>
#include <map>
#include <string>
#include <ctime>
#include <cstring>
#include <cmath>
using namespace std;
const long long maxn = 2e3 + 5;
//const long long mod = 1000000007;
//static long long obrf[maxn], f[maxn];
//static int parent[maxn], siz[maxn], Rank[maxn];
static long long a[maxn];
static long long mas[maxn][maxn], dp[maxn][maxn];
/*long long pew(long long a, long long step)
{
	if (step == 0)
	{
		return 1;
	}
	long long b = pew((a*a) % mod, step / 2);
	if (step % 2 == 0)
	{
		return b;
	}
	else
	{
		return (b*a) % mod;
	}
}

void precal(int cnt)
{
	long long tmp = 1;
	f[0] = 1;
	obrf[0] = 1;
	for (int i = 1; i <= cnt; i++)
	{
		tmp *= i;
		tmp %= mod;
		f[i] = tmp;
		obrf[i] = pew(tmp, mod - 2);
	}
}*/

/*void make_set(int v) {
	parent[v] = v;
	Rank[v] = 0;
	siz[v] = 1;
}

int find_set(int v) {
	if (v == parent[v])
		return v;
	return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
	a = find_set(a);
	b = find_set(b);
	if (a != b) {
		if (Rank[a] < Rank[b])
			swap(a, b);
		parent[b] = a;
		siz[a] += siz[b];
		if (Rank[a] == Rank[b])
			++Rank[a];
	}
}
long long gcd(long long ll, long long rr)
{
	if (ll < rr)
		return gcd(rr, ll);
	if (rr == 0)
		return ll;
	return gcd(ll%rr, rr);
}
*/
/*void QSort(int ll, int rr)
{
int ee = ll;
int ff = rr;

long long q = rand();
q = c[ll+q%(rr-ll+1)];
while (ee <= ff)
{
while (c[ee] < q) ee++;
while (c[ff] > q) ff--;
if (ee <= ff)
{
swap(c[ee], c[ff]);
swap(s[ee], s[ff]);
ee++;
ff--;
}
}
if (ff > ll) QSort(ll, ff);
if (ee < rr) QSort(ee, rr);
}*/

int main()
{
	ios_base::sync_with_stdio(false);
//	freopen("a1.in", "r", stdin);
//	freopen("a1.out", "w", stdout);
	int n, s, m, k;
	cin >> n >> s >> m >> k;
	set<long long> keks;
	map<long long, long long> kek, kek1;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		keks.insert(a[i]);
	}
	long long cnt = 0;
	int q = keks.size();
	while (q)
	{
		q--;
		kek[*(keks.lower_bound(-1))] = cnt;
		kek1[cnt] = *(keks.lower_bound(-1));
		long long del = *(keks.lower_bound(-1));
		cnt++;
		keks.erase(del);
	}
	long long l, r;
	vector <pair<long long, long long>> otr;
	for (int i = 0; i < s; i++)
	{
		cin >> l >> r;
		otr.push_back({ l,r });
	}
	sort(otr.begin(), otr.end());
	/*for (int i = 0; i < s; i++)
	{
		for (int j = 0; j < 2000; j++)
		{
			tmp[j] = 0;
		}
		for (int j = l; j <= r; j++)
		{
			tmp[kek[a[j]]]++;
		}
		mas[i][0] = tmp[0];
		for (int j = 0; j < 2000; j++)
		{
			mas[i][j] = mas[i][j - 1] + tmp[j];
		}
	}*/
	for (int i = kek[a[0]]; i <= 2000; i++)
	{
		mas[1][i] = 1;
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < kek[a[i]]; j++)
		{
			mas[i+1][j] = mas[i][j];
		}
		for (int j = kek[a[i]]; j <= 2000; j++)
		{
			mas[i+1][j] = mas[i][j]+1;
		}
	}
	l = -1;
	r = 2000;
	while (r - l > 1)
	{
		long long med = (r + l+1) / 2;
		long long cnt = 0;
		for (int i = 0; i <= 2000; i++)
		{
			for (int j = 0; j <= 2000; j++)
			{
				dp[i][j] = 0;
			}
		}
		long long cur = 0;
		long long mp = 0;
		for (int i = 1; i <= n; i++)
		{
			while (cur < s and otr[cur].first == i)
			{
				mp = max(mp, otr[cur].second);
				cur++;
			}
			for (int j = 0; j <= m; j++)
			{
				dp[j][i] = max(dp[j][i], dp[j][i-1]);
				if (mp>=i)
					dp[j+1][mp] = max(dp[j + 1][mp], dp[j][i-1]+mas[mp][med]-mas[i-1][med]);
			}
		}
		if (dp[m][n] < k)
		{
			l = med;
		}
		else
		{
			r = med;
		}
	}
	if (l > 1600)
	{
		cout << -1;
	}
	else
	{
		//cout << l << endl;
		cout << kek1[r] << endl;
		//	cout << l << " " << kek1[l] << " " << r << " " << kek[101714318];
	}
}