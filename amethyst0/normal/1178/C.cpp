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
#include <cstring>
#include <memory.h>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

const int mod = 998244353;

int my_pow(int x, int y) {
	int ans = 1;

	while (y) {
		if (y & 1) {
			ans = (ll)ans * x % mod;
		}

		y >>= 1;
		x = (ll)x * x % mod;
	}

	return ans;
}

int main() {
	int a, b;

	cin >> a >> b;

	cout << my_pow(2, a + b) << endl;

	//system("pause");
}