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
#include <ctime>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }


int main()
{
	int T; cin >> T;
	while (T--)
	{
		int arr[101];
		int n, k; cin >> n >> k;
		for (int i = 0; i < n; i++) cin >> arr[i];
		sort(arr, arr + n);
		if (arr[n - 1] - arr[0] > 2 * k) cout << "-1\n";
		else cout << arr[0] + k << "\n";
	}
}