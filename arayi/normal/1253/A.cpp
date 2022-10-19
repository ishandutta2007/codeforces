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
int n, a[N], b[N], q;
int main()
{
	fastio;
	cin >> q;
	while(q--)
	{
		int sm = -1;
		bool fl = false, ff = false;;
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < n; i++) cin >> b[i], b[i] -= a[i];
		for (int i = 0; i < n; i++)
		{
			if (b[i] < 0)
			{
				cout << "no\n";
				ff = true;
				break;
			}
			if (b[i] == 0) continue;
			if (b[i] > 0 && fl)
			{
				cout << "no\n";
				ff = true;
				break;
			}
			if (b[i] > 0)
			{
				fl = true;
				while (i < n - 1 && b[i] == b[i + 1])
				{
					i++;
				}
			}
		}
		if(!ff) cout << "yes\n";
	}
	return 0;
}