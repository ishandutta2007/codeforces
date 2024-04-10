//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,tune=native")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <array>
#include <string>
#include <set>
#include <map>
#include <assert.h>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <deque>

#define X first
#define Y second
#define int long long
using ll = long long;
using ld = long double;

using namespace std;

/*namespace fast_in {
char buff[30000000];
int pos = 0;

void init() {
fread(buff, 1, sizeof buff, stdin);
}

int get_int() {
int val = 0, flag = 1;
while (!isdigit(buff[pos]) and buff[pos] != '-') ++pos;
if (buff[pos] == '-')
{
flag = -1;
++pos;
}
while (isdigit(buff[pos])) val = val * 10 + buff[pos++] - '0';
return val * flag;
}
}*/

ll mod = 998244353;

/*ll gcd(ll a, ll b)
{
if (a < b)
{
return gcd(b, a);
}
if (b == 0)
{
return a;
}
return gcd(b, a%b);
}*/

/*
ll mul(ll a, ll b)
{
	return a * b%mod;
}

ll sum(ll a, ll b)
{
	return (a + b) % mod;
}

ll sub(ll a, ll b)
{
	return (a - b + mod) % mod;
}

ll pew(ll a, ll b)
{
	if (b == 0) return 1;
	ll c = pew(a, b / 2);
	c = mul(c, c);
	if (b % 2 == 0) return c;
	c = mul(c, a);
	return c;
}
*/
/*
ll t[3000001];

void build()
{
	for (int i = 0; i < 2000000; i++)
	{
		t[i] = 0;
	}
}

void add(int v, int pos, ll val, int L, int R)
{
	if (L == R)
	{
		t[v] += val;
		return;
	}
	int m = (L + R) / 2;
	if (pos <= m)
	{
		add(2 * v, pos, val, L, m);
	}
	else
	{
		add(2 * v + 1, pos, val, m + 1, R);
	}
}

ll sum(int v, int l, int r, int L, int R)
{
	if (L == l and r == R) return t[v];
	int m = (L + R) / 2;
	if (r <= m) return sum(2 * v, l, r, L, m);
	if (l > m) return sum(2 * v + 1, l, r, m + 1, R);
	//return sum(2*v,)
}*/

int rnk[100001];
int parent[100001];
void make_set(int v) {
	parent[v] = v;
	rnk[v] = 0;
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
		if (rnk[a] < rnk[b])
			swap(a, b);
		parent[b] = a;
		if (rnk[a] == rnk[b])
			++rnk[a];
	}
}

ll q[5001];
ll pr[5001];
ll prv[5001];
ll cntprv[5001];
vector<int> keks(5001);
vector<vector<int>> mas(5001);
ll ans = 0;
int n;

void rec(int l, int r, int maxlast)
{
	int cnt = 0;
	int ok = 1;
	int last = 5000;
	int L = 0;
	for (int pos = l; pos >= r - 1 and ok == 1; pos--)
	{
		for (int j = maxlast; j >= 0; j--)
		{
			if (mas[pos][j] != 0 or pos==r-1)
			{
				if (last == j and pos!=r-1)
				{
					cnt += keks[pos];
					break;
				}
				else
				{

					if (cnt * 2 > n)
					{
						ans -= mas[pos + 1][last] * (cnt * 2 - n);
						int R = pos + 1;
						int tmp = mas[R][last];
						for (int i = R; i <= L; i++)
						{
							mas[i][last] -= tmp;
						}
						rec(L, R, last);
						ok = 0;
						break;
					}
					cnt = keks[pos];
					L = pos;
					last = j;
					break;
				}
			}
			else
			{
				if (j==0)
				last = -1;
			}
		}
	}
}

signed main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n;
	vector<int> a(n);
	vector<vector<int>> kek(n);
	q[0] = 0;
	q[1] = 0;
	int lp = 0;
	mas[0].resize(5001);
	mas[1].resize(5001);
	for (int i = 2; i <= 5000; i++)
	{
		q[i] = q[i - 1];
		mas[i] = mas[i - 1];
		int N = i;
		for (int j = 2; j*j <= N; j++)
		{
			while (N%j == 0)
			{
				N /= j;
				mas[i][j]++;
				q[i]++;
			}
		}
		if (N != 1)
		{
			mas[i][N]++;
			q[i]++;
		}
		if (N == i)
		{
			pr[i] = 1;
			lp = i;
		}
		prv[i] = lp;
		cntprv[i] = i - lp + 1;
	}
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (a[i] == 0) a[i] = 1;
		ans += q[a[i]];
		keks[a[i]]++;
	}

	int last = 0;
	int ok = 1;
	ll cnt = 0;
	int l = 5000;
	for (int pos = 5000; pos > 0 and ok==1; pos--)
	{
		for (int j = 5000; j >= 0; j--)
		{
			if (mas[pos][j] != 0 or (j==1 and pos==1))
			{
				if (last == j)
				{
					cnt += keks[pos];
					break;
				}
				else
				{
					
					if (cnt * 2 > n)
					{
						ans -= mas[pos+1][last] * (cnt * 2 - n);
						int r = pos+1;
						for (int i = r; i <= l; i++)
						{
							mas[i][last] = 0;
						}
						rec(l, r, last);
						ok = 0;
						break;
					}
					cnt = keks[pos];
					l = pos;
					last = j;
					break;
				}
			}
		}
	}
	cout << ans << endl;
}