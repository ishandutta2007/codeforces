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
#include <unordered_map>
using namespace std;

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

const long long maxn = 4e2 + 100;
static long long w[maxn], c[maxn], a[maxn][maxn], x[maxn], N[20], b[maxn], r[maxn], flag[maxn], mas[maxn][maxn], u[maxn], v[maxn], s[maxn];
const long long INF = 1e18;
int main()
{
	ios_base::sync_with_stdio(false);
//	freopen("a1.in", "r", stdin);
//	freopen("a1.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int n1, n2;
	n1 = n / m;
	n2 = n % m;
	long long ans = 0;
	long long tmp = 0, tmp1 = 0, tmp2 = 0;
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if ((i*i + j * j) % m == 0)
			{
				tmp++;
				if (j <= n2)
				{
					tmp1++;
				}
				if (i <= n2 and j <= n2)
				{
					tmp2++;
				}
			}
		}
	}
	ans = tmp * n1*n1 + 2*tmp1*n1 + tmp2;
	cout << ans;
}