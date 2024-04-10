#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <bitset>
#include <list>
#include <cmath>
#include <climits>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b)
{
	for (; b; a %= b, swap(a, b));
	return a;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int x;
	cin >> x;
	int pwr[4] = { 1,4,2,3 };
	char res[4] = { 'D','A','C','B' };
	x %= 4;
	int y = (x + 1) % 4;
	int z = (y + 1) % 4;
	
	int ans = pwr[x];
	ans = max(ans, pwr[y]);
	ans = max(ans, pwr[z]);

	if (ans == pwr[x]) cout << "0 " << res[x];
	else if (ans == pwr[y]) cout << "1 " << res[y];
	else cout << "2 " << res[z];
}