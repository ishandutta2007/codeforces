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
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef unsigned long long ull;

const int maxn = 1e5 + 100;

int dp[maxn], a[maxn], p[maxn];

int main (){
	ios_base::sync_with_stdio (false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		p[a[i]] = i;
	}
	for (int i = n; i >= 1; i--) {
		int x = p[i];
		for (int k = 1; k * i <= n; k++) {
			int j = k * i;
			if (x + j <= n and a[x + j] > i and dp[x + j] == 0)
				dp[x] = 1;
			if (x - j > 0 and a[x - j] > i and dp[x - j] == 0)
				dp[x] = 1;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (dp[i] == 1)
			cout << 'A';
		else
			cout << 'B';
	}
	cout << endl;
}