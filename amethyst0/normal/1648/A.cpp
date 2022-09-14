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
#include <limits.h>
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
#define pll pair <ll, ll>

using namespace std;

map<int, int> col;

const int maxn = (int)1e5 + 10;

vector <int> xx[maxn], yy[maxn];

int main() {
	int n, m;
	cin >> n >> m;
	
	int cl = 0;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int c;
			scanf("%d", &c);
			
			if (!col.count(c)) {
				col[c] = cl;
				cl++;
			}
			
			xx[col[c]].push_back(i);
			yy[col[c]].push_back(j);
		}
	}
	
	ll ans = 0;
	
	for (int c = 0; c < maxn; c++) {
		for (vector<int> a : {xx[c], yy[c]}) {
			sort(a.begin(), a.end());
			
			ll sum = 0;
			
			for (int i = 0; i < (int)a.size(); i++) {
				ans -= sum;
				ans += (ll)a[i] * i;
				sum += a[i];
			}
		}
	}
	
	cout << ans << '\n';
}