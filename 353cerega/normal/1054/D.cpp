#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <memory.h>
#include <map>

using namespace std;

const int maxn = 4e5 + 5;
const long long mod = 1e9 + 7;

static long long a[maxn], b[maxn], c[maxn];
long long ans = 0;
static long long l[maxn];
static long long r[maxn];
static long long s[maxn];

void QSort(int ll, int rr)
{
	int ee = ll;
	int ff = rr;
	long long q = c[(ll + rr) / 2];
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
}

int main()
{
	//freopen("a1.in", "r", stdin);
	//freopen("a1.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	long long kek = (1ll << k) - 1;
	map <long long, long long> keks;
	b[0] = 0;
	keks[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (a[i] * 2 > kek)
		{
			a[i] ^= kek;
		}
		b[i] = a[i] ^ b[i-1];
		if (keks.count(b[i]) == 0)
		{
			keks[b[i]] = 1;
		}
		else 
		{
			keks[b[i]]++;
		}
	}
	for (auto& item : keks)
	{
		ans += (item.second*(n+1 - item.second));
		//cout << ans << endl;
		ans += 2*(item.second / 2)*((item.second + 1) / 2);
		//cout << ans << endl;
	}
	ans /= 2;
	cout << ans;
	return 0;
	
}