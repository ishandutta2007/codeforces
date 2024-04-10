//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,tune=native")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <array>
#include <cstring>
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

using ll = long long;
using ld = long double;

using namespace std;
/*
namespace fast_in {
	char buff[50000000];
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

//ll mod = 998244353;

ll gcd(ll a, ll b)
{
	if (b == 0)
	{
		return a;
	}
	return gcd(b, a%b);
}

/*
ll mul(ll a, ll b)
{
	return a * b%mod;
}

ll sum(ll a, ll b)
{
	a += b;
	if (a >= mod) a -= mod;
	return a;
}

ll sub(ll a, ll b)
{
	a -= b;
	if (a < 0) a += mod;
	return a;
}

ll pew(ll a, ll b)
{
	ll res(1);
	while (b)
	{
		if (b & 1) res = mul(res, a);
		a = mul(a, a);
		b >>= 1;
	}
	return res;
}*/


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
t[v] += val;
if (L == R)
{
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
if (l > r) return 0;
if (L == l and r == R) return t[v];
int m = (L + R) / 2;
if (r <= m) return sum(2 * v, l, r, L, m);
if (l > m) return sum(2 * v + 1, l, r, m + 1, R);
return sum(2*v,l,m,L,m)+sum(2*v+1,m+1,r,m+1,R);
}*/

/*int rnk[100001];
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
*/

void solve()
{
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> keks(n), kek;
	int sum = 0;
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> keks[i].Y >> keks[i].X;
		sum += keks[i].Y;
		keks[i].X++;
		keks[i].X %= m;
	}
	if (sum%m == 0) ans++;
	for (int i = 0; i < n; i++)
	{
		keks.push_back({ (keks[i].X + m - 1) % m,-keks[i].Y });
	}
	n *= 2;
	sort(keks.begin(), keks.end());
	for (int i = 0; i < n; i++)
	{
		if (kek.size() == 0 or keks[i].X != kek.back().X)
		{
			if (kek.size()!=0 and kek.back().Y == 0) kek.pop_back();
			kek.push_back(keks[i]);
		}
		else
		{
			kek.back().Y += keks[i].Y;
		}
	}
	if (kek.size() == 1 and kek[0].Y == 0) kek.pop_back();
	if (kek.size() == 0)
	{
		cout << -1 << endl;
		return;
	}
	int F = kek.size();
	int q = -1;
	for (int i = 0; i < F; i++)
	{
		int nxt = (i + 1) % F;
		if (kek[nxt].X - kek[i].X > 20 and q == -1)
		if (kek[nxt].X - kek[i].X > 20 and q == -1) q = i;
	}
	
	for (int k = 2; k <= n + 1; k++)
	{
		int lft = 0;
		int deg = 0;
		int flag = 0;
		for (int pos = 0; pos < kek.size() and flag == 0; pos++)
		{

		}
	}
	cout << ans << endl;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, k;
	cin >> n >> k;
	vector<int> a(k);
	int k2 = (1 << n);
	for (int i = 0; i < k; i++)
	{
		cin >> a[i];
		a[i]--;
	}
	vector<vector<ll>> dp(k2*2);
	for (int i = 0; i < k2*2; i++)
	{
		dp[i].resize(4);
		for (int j = 0; j < 4; j++)
		{
			dp[i][j] = -100000;
		}
	}
	for (int i = 0; i < k; i++)
	{
		dp[a[i]+k2][1] = 0;
	}
	for (int i = 0; i < k2; i++)
	{
		if (dp[i + k2][1] != 0) dp[i + k2][0] = 0;
	}
	for (int j = k2 - 1; j >= k2 / 2; j--)
	{
		dp[j][0] = dp[j * 2][0] + dp[j * 2 + 1][0];
		dp[j][1] = max(dp[j * 2][1] + dp[j * 2 + 1][0], dp[j * 2][0] + dp[j * 2 + 1][1]) + 1;
		dp[j][2] = max(dp[j * 2][1] + dp[j * 2 + 1][0], dp[j * 2][0] + dp[j * 2 + 1][1]) + 1;
		dp[j][2] = max(dp[j][2], max(dp[j * 2][2] + dp[j * 2 + 1][0], dp[j * 2][0] + dp[j * 2 + 1][2]) + 1);
		dp[j][2] = max(dp[j][2], dp[j * 2][2] + dp[j * 2 + 1][2] + 1);
		dp[j][3] = max(dp[j * 2][3] + dp[j * 2 + 1][0], dp[j * 2][0] + dp[j * 2 + 1][3]) + 1;
		dp[j][3] = max(dp[j][3], max(dp[j * 2][1] + dp[j * 2 + 1][2], dp[j * 2][2] + dp[j * 2 + 1][1]) + 1);
		dp[j][3] = max(dp[j][3], dp[j * 2][1] + dp[j * 2 + 1][1] + 1);
		dp[j][3] = max(dp[j][3], max(dp[j * 2][1] + dp[j * 2 + 1][3], dp[j * 2][3] + dp[j * 2 + 1][1]) + 1);
		dp[j][3] = max(dp[j][3], max(dp[j * 2][2] + dp[j * 2 + 1][3], dp[j * 2][3] + dp[j * 2 + 1][2]) + 1);
		dp[j][3] = max(dp[j][3], dp[j * 2][3] + dp[j * 2 + 1][3] + 1);
	}
	for (int j = k2/2 - 1; j >= 1; j--)
	{
		
		dp[j][0] = dp[j * 2][0] + dp[j * 2 + 1][0];
		dp[j][1] = max(dp[j * 2][1] + dp[j * 2 + 1][0], dp[j * 2][0] + dp[j * 2 + 1][1])+1;
		dp[j][2] = max(dp[j * 2][1] + dp[j * 2 + 1][0], dp[j * 2][0] + dp[j * 2 + 1][1])+2;
		dp[j][2] = max(dp[j][2], max(dp[j * 2][2] + dp[j * 2 + 1][0], dp[j * 2][0] + dp[j * 2 + 1][2]) + 2);
		dp[j][2] = max(dp[j][2], dp[j * 2][2] + dp[j * 2 + 1][2] + 2);
		dp[j][3] = max(dp[j * 2][3] + dp[j * 2 + 1][0], dp[j * 2][0] + dp[j * 2 + 1][3]) + 3;
		dp[j][3] = max(dp[j][3],max(dp[j * 2][1] + dp[j * 2 + 1][2], dp[j * 2][2] + dp[j * 2 + 1][1]) + 3);
		dp[j][3] = max(dp[j][3], dp[j * 2][1] + dp[j * 2 + 1][1] + 2);
		dp[j][3] = max(dp[j][3], max(dp[j * 2][1] + dp[j * 2 + 1][3], dp[j * 2][3] + dp[j * 2 + 1][1]) + 3);
		dp[j][3] = max(dp[j][3], max(dp[j * 2][2] + dp[j * 2 + 1][3], dp[j * 2][3] + dp[j * 2 + 1][2]) + 3);
		dp[j][3] = max(dp[j][3], dp[j * 2][3] + dp[j * 2 + 1][3] + 3);
		//cout << j << " " << dp[j][0] << " " << dp[j][1] << " " << dp[j][2] << " " << dp[j][3] << endl;
	}
	ll ans = -100000;
	for (int i = 0; i < 4; i++)
	{
		ans = max(dp[1][i], ans);
	}
	if (k > 0) ans++;
	cout << ans << endl;
}