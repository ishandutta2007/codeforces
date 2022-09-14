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
typedef long double ld;

const int maxn = 110;
int v[maxn];

int main() {
	int n;

	int s = 0;

	cin >> n;

	vector <int> g;

	int tot = 0;

	for (int i = 0; i < n; i++) {
		cin >> v[i];
		s += v[i];

		if (i == 0 || v[i] * 2 <= v[0]) {
			g.push_back(i);
			tot += v[i];
		}
	}

	if (tot * 2 <= s) {
		cout << 0 << endl;
	}
	else {
		cout << g.size() << endl;

		for (int i = 0; i < (int)g.size(); i++) {
			cout << g[i] + 1 << ' ';
		}

		cout << endl;
	}

	//system("pause");
}