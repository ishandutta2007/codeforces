#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <iomanip>
#include <string>
#include <string.h>
#include <cstdio>
#include <stdio.h>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <random>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back

const int nax = 1e5;
const int inf = 1e9;

struct num {
	static const int MA = 1e9 + 7, MB = 1e9 + 9;
	int a, b;
	num() : a(0), b(0) {}
	num(int x) : a((x%MA + MA) % MA), b((x%MB+MB)%MB) {}
	num(int a, int b) : a((a%MA + MA) % MA), b((b%MB + MB) % MB) {}
	num operator + (const num& other) const {
		return num(a + other.a, b + other.b);
	}
	num operator - (const num& other) const {
		return num(a - other.a, b - other.b);
	}
	num operator * (const num& other) const {
		return num(1LL * a * other.a % MA, 1LL * b * other.b % MB);
	}
	bool operator == (const num& other) const {
		return a == other.a && b == other.b;
	}
};

mt19937 rnd(228);
const int P = max(239, (int)rnd());

num pw[nax + 1];
num h[2 * nax];
int p[2 * nax];
num h1[2 * nax];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//ifstream cin("in.txt");
	pw[0] = 1;
	for (int i = 0; i < nax; i++) {
		pw[i + 1] = pw[i] * P;
	}
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		if (a > b) {
			swap(a, b);
		}
		int len = min(b - a, a + n - b);
		h[a] = h[a] + pw[len];
		h[b] = h[b] + pw[len];
	}
	for (int i = 0; i < n; i++) {
		h[i + n] = h[i];
	}
	p[0] = 0;
	for (int i = 1; i < 2 * n - 1; i++) {
		int k = p[i - 1];
		while (k > 0 && !(h[i] == h[k])) {
			k = p[k - 1];
		}
		if (h[i] == h[k]) {
			k++;
		}
		p[i] = k;
		if (k >= n) {
			cout << "Yes";
			return 0;
		}
	}
	cout << "No";
}