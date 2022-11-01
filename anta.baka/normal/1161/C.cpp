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

void alice() {
	cout << "Alice";
	exit(0);
}

void bob() {
	cout << "Bob";
	exit(0);
}

int n;
int a[50];
int lo = inf;
int clo;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//ifstream cin("in.txt");
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		lo = min(lo, a[i]);
	}
	for (int i = 0; i < n; i++) {
		clo += (a[i] == lo);
	}
	if (clo > n / 2) {
		bob();
	}
	alice();
}