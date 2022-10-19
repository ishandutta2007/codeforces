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



const int N = 4e5 + 20;
const lli mod = 1e9 + 7;

int	q;
int n;
int a[N];
int main()
{
	fastio;
	cin >> q;
	while (q--)
	{
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		int r = -1, g = -1, b = -1, i = 0, nax = 0;
		while (i < n / 2)
		{
			if (a[i] != a[i + 1])
			{
				r = i + 1;
				break;
			}
			i++;
		}
		nax = r;
		//cout << r << " ";
		while (i < n/2)
		{
			if (a[i] != a[i + 1] && i - nax + 1 > r)
			{
				g = i + 1 - r;
				break;
			}
			i++;
		}
		nax = i + 1;
		for (int i = n / 2 - 1; i >= nax; i--)
		{
			if (a[i] != a[i + 1] && i - nax + 1 > r)
			{
				b = i + 1 - nax;
				break;
			}
		}
		if (b == -1)
		{
			cout << "0 0 0\n";
			continue;
		}
		cout << r << " " << g << " " << b << endl;
	}
	return 0;
}