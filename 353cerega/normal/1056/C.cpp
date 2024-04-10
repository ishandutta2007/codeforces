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

const long long maxn = 4e5 + 100;
static long long w[maxn], c[maxn], a[maxn], b[maxn], p[maxn], N[20], r[maxn], flag[maxn];
const long long INF = 1e18;
int main()
{
	ios_base::sync_with_stdio(false);
	//freopen("a1.in", "r", stdin);
	//freopen("a1.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= 2 * n; i++)
	{
		cin >> p[i];
	}
	for (int i = 0; i < m; i++)
	{
		cin >> a[i] >> b[i];
		if (p[a[i]] < p[b[i]])
		{
			swap(a[i], b[i]);
		}
	}
	int t;
	cin >> t;
	int x;
	long long cnt = 2 * n;
	if (t == 1)
	{
		for (int i = 0; i < m; i++)
		{
			cout << a[i] << endl;
			flag[a[i]] = 1;
			cin >> x;
			flag[x] = 1;
			cnt--;
			cnt--;
		}
		while (cnt)
		{
			int ind = 0;
			int s = -1;
			for (int i = 1; i <= 2 * n; i++)
			{
				if (flag[i] == 0 and s < p[i])
				{
					ind = i;
					s = p[i];
				}
			}
			cout << ind << endl;
			flag[ind] = 1;
			cin >> x;
			flag[x] = 1;
			cnt--;
			cnt--;
		}
		
	}
	else
	{
		while (cnt > 0)
		{
			long long f = 0;
			cin >> x;
			cnt--;
			flag[x] = 1;
			for (int i = 0; i < n; i++)
			{
				if (x == a[i])
				{
					cout << b[i] << endl;
					flag[b[i]] = 1;
					cnt--;
					f = 1;
				}
				if (x == b[i])
				{
					cout << a[i] << endl;
					flag[a[i]] = 1;
					cnt--;
					f = 1;
				}
			}
			if (f)
			{
				continue;
			}
			else
			{
				for (int i = 0; i < m; i++)
				{
					if (flag[a[i]] == 0)
					{
						cout << a[i] << endl;
						flag[a[i]] = 1;
						cin >> x;
						flag[x] = 1;
						cnt--;
						cnt--;
					}
				}
				m = 0;
				int ind = 0;
				int s = -1;
				for (int i = 1; i <= 2 * n; i++)
				{
					if (flag[i] == 0 and s < p[i])
					{
						ind = i;
						s = p[i];
					}
				}
				cout << ind << endl;
				cnt--;
				flag[ind] = 1;

			}
		}

	}
}