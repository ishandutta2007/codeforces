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
int n, p, sm;
int main()
{
	fastio;
	cin >> n >> p;
	int l = 1, r = 31, ans = -1;
	for(int mid = 0; mid < 31; mid++)
	{
		sm = n - p * mid;
		if (sm < 0) break;
		int mkqan = 0;
		for (int i = 0; i < 31; i++)
		{
			if ((1 << i) & sm) mkqan++;
		}
		if (mkqan <= mid && mid <= sm) { cout << mid; return 0; }
	}
	cout << ans;
	return 0;
}