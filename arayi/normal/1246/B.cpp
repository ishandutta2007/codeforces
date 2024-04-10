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
 
lli gcd(lli a, lli b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}
 
 
char vow[] = { 'a', 'e', 'i', 'o', 'u' };
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
 
 
 
const int N = 1e6 + 30;
const lli mod = 9982443530000;
lli col[N];
lli n, k, pat;
int main()
{
	fastio;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		lli a;
		cin >> a;
		vector <pair<lli, lli> > fp;
		for (int j = 2; j * j <= a; j++)
		{
			if (a % j == 0)
			{
				lli sm = 0;
				while (a % j == 0) sm++, a /= j;
				sm %= k;
				if (sm) fp.PB(MP(j, sm));
			}
		}
		if (a > 1) fp.PB(MP(a, 1));
		lli sm1 = 1, sm2 = 1;
		for (auto p : fp)
		{
			//cout << p.fr << " " << p.sc << endl;;
			for (int i = 0; i < p.sc; i++) sm1 *= p.fr;
			for (int i = 0; i < k - p.sc; i++)
			{
				sm2 *= p.fr;
				if (sm2 > N) sm2 = 0;
			}
		}
		//cout << sm1 << " " << sm2 << endl;
		pat += col[sm2];
		col[sm1]++;
	}
	cout << pat;
	return 0;
}