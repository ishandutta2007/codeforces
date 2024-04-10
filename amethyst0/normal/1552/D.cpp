//#pragma comment(linker, "/STACK:1000000000")
#pragma GCC optimize("Ofast,no-stack-protector")
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
#include <cstdio>
#include <cassert>
#include <cstring>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long 
#define pii pair <int, int>
#define pll pair <ll, ll>
#define ld double

using namespace std;

const int maxn = 11;
int v[maxn];
int n;

vector <int> a;
vector <int> res;

void go(int pos, int sum) {
	if (pos == n) {
		if (sum == 0)
			res = a;
		return;
	}

	go(pos + 1, sum);
	a.push_back(v[pos]);
	sum += v[pos];
	go(pos + 1, sum);
	sum -= 2 * v[pos];
	a.back() *= -1;
	go(pos + 1, sum);
	a.pop_back();
	sum += v[pos];
}

int main() {
	int tt;
	cin >> tt;
	while (tt--) {
		res.clear();
		scanf("%d", &n);
		
		for (int i = 0; i < n; i++) {
			scanf("%d", &v[i]);
		}

		go(0, 0);
		if (res.empty()) {
			printf("NO\n");
		}
		else {
			printf("YES\n");
		}
	}
}