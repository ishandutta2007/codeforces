#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <cmath>
#include <algorithm>
#include <assert.h>
#include <vector>
#include <cstring>
#include <bitset>
#include <random>
#include <ctime>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned int ui;
//typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;
#define mp make_pair

const int maxn = (1 << 18) + 10;
int v[maxn];

int main() {
	int n, k;

	ll ans = 0;

	cin >> n >> k;

	for (int i = 0; i < (1 << n); i++) {
		scanf("%d", &v[i]);
		ans += v[i];
	}

	printf("%.10lf\n", (ld)ans / (1 << n));

	while (k--) {
		int x, y;

		scanf("%d %d", &x, &y);

		ans -= v[x];
		ans += y;
		v[x] = y;

		printf("%.10lf\n", (ld)ans / (1 << n));
	}

	//system("pause");
}