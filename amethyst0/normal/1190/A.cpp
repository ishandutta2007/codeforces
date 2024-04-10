#pragma comment(linker, "/STACK:1000000000")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <ctime>
#include <random>
#include <bitset>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;

const int maxn = (int)1e5 + 10;
ll v[maxn];

int main() {
	ll n, k;
	int m;

	cin >> n >> m >> k;

	for (int i = 0; i < m; i++) {
		scanf("%lld", &v[i]);
		v[i]--;
	}

	int ans = 0;

	int l = 0;
	
	while (l < m) {
		int cnt = l;

		int r = l;

		while (r < m && (v[l] - cnt) / k == (v[r] - cnt) / k) {
			r++;
		}

		ans++;
		l = r;
	}

	cout << ans << endl;

	//system("pause");

	return 0;
}