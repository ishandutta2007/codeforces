//#pragma comment(linker, "/STACK:1000000000")
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
#include <cassert>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long 
#define pii pair <int, int>
#define ld double

using namespace std;

const int maxn = (int)1e5 + 10;

int a[maxn], b[maxn];
int pos[maxn];

int main() {
	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	for (int i = 0; i < n; i++) {
		scanf("%d", &b[i]);
		pos[b[i]] = i;
	}

	set <int> s;
	int ans = 0;

	for (int i = 0; i < n; i++) {
		int p = pos[a[i]];

		auto it = s.lower_bound(p);

		if (it != s.end()) {
			ans++;
		}

		s.insert(p);
	}

	cout << ans << '\n';

	//system("pause");
	return 0;
}