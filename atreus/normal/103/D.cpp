#include <iostream>
#include <queue>
#include <bitset>
#include <stack>
#include <vector>
#include <cstring>
#include <cmath>
#include <unordered_map>
#include <map>
#include <set>
#include <algorithm>
#include <iomanip>
#define F first
#define S second
#define PB push_back
#define PF push_front
#define MP make_pair

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef unsigned long long ull;

const int maxn = 3e5 + 10;

int Sqrt = 500;

ll dp[maxn], p[maxn];

vector <int> v[505];

ll ans[maxn];
pair <ll, ll> Q[maxn];

int main () {
	ios_base::sync_with_stdio (false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> p[i];
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> Q[i].F >> Q[i].S;
		Q[i].F --;
		if (Q[i].S <= Sqrt) {
			v[Q[i].S].PB (i);
			continue;
		}

		while (Q[i].F < n) {
			ans[i] += p[Q[i].F];
			Q[i].F += Q[i].S;
		}
	}
	for (int i = 1; i <= Sqrt; i++) {
		for (int j = n - 1; j >= 0; j--) {
			if (i + j >= n)
				dp[j] = p[j];
			else
				dp[j] = p[j] + dp[j + i];
		}
		for (auto w : v[i]) 
			ans[w] = dp[Q[w].F];
		
	}
	for (int i = 0; i < q; i++)
		cout << ans[i] << '\n';
}