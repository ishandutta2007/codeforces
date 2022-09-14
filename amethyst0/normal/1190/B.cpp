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
int v[maxn];

void write(int x) {
	if (x == 2) {
		cout << "cslnb" << endl;
	}
	else {
		cout << "sjfnb" << endl;
	}

	//system("pause");
}

int main() {
	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}

	sort(v, v + n);

	int cnt = 0;

	for (int i = 0; i < n - 1; i++) {
		if (v[i] == v[i + 1]) {
			cnt++;
		}
	}

	if (cnt > 1) {
		write(2);
		return 0;
	}

	bool fl = false;

	for (int i = 0; i < n - 2; i++) {
		if (v[i] == v[i + 1] - 1 && v[i + 1] == v[i + 2]) {
			fl = true;
		}
	}

	if (n > 1 && v[0] == 0 && v[1] == 0) {
		write(2);
		return 0;
	}

	if (fl) {
		write(2);
		return 0;
	}

	ll f = 0;

	for (int i = 0; i < n; i++) {
		f += v[i] - i;
	}

	if (f % 2 == 0) {
		write(2);
	}
	else {
		write(1);
	}

	return 0;
}