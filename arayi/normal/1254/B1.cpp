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



const int N = 2e5 + 30;
const lli mod = 1e9 + 7;
int n, a[N], sum;
lli qan1, qan2, sm1, sm2, pat = LLONG_MAX, ss;
int main()
{
	fastio;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		sum += a[i];
	}
	if (sum <= 1)
	{
		cout << -1;
		return 0;
	}
	//cout << pat << endl;
	//if (n == 1e5 && (a[0] & a[1] & a[2]) && !a[3]) cout << sum << endl;
	for (int x = 2; x * x <= sum; x++)
	{
		if (sum % x == 0)
		{
			ss = x;
			while (sum % x == 0) sum /= x;
			lli pat1 = 0;
			for (int i = 0; i < n; i++)
			{
				if (a[i])
				{
					qan1++;
					sm1 += i;
				}
				if (qan1 == ss)
				{
					lli mn = LLONG_MAX;
					int i1 = i;
					while (qan1)
					{
						mn = min(mn, sm2 - qan2 * i1 + qan1 * i1 - sm1);
						if (a[i1]) qan1--, qan2++, sm1 -= i1, sm2 += i1;
						i1--;
					}
					pat1 += mn;
					qan1 = 0;
					qan2 = 0;
					sm1 = 0;
					sm2 = 0;
				}
			}
			pat = min(pat, pat1);
		}
	}
	if (sum > 1)
	{
		ss = sum;
		lli pat1 = 0;
		for (int i = 0; i < n; i++)
		{
			if (a[i])
			{
				qan1++;
				sm1 += i;
			}
			if (qan1 == ss)
			{
				lli mn = LLONG_MAX;
				int i1 = i;
				while (qan1)
				{
					mn = min(mn, sm2 - qan2 * i1 + qan1 * i1 - sm1);
					if (a[i1]) qan1--, qan2++, sm1 -= i1, sm2 += i1;
					i1--;
				}
				pat1 += mn;
				qan1 = 0;
				qan2 = 0;
				sm1 = 0;
				sm2 = 0;
			}
		}
		pat = min(pat, pat1);
	}
	cout << pat;
	return 0;
}