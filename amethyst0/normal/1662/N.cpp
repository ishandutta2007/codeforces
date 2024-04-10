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

const int maxn = 1510;

int x[maxn * maxn], y[maxn * maxn];
int sumx[maxn], sumy[maxn];

int main() {
	int n;
	cin >> n;
	
	ll total = 0;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int a;
			scanf("%d", &a);
			a--;
			x[a] = i;
			y[a] = j;
			total += i * j;
		}
	}
	
	ll ans = 0;
	
	for (int i = 0; i < n * n; i++) {
		int px = x[i];
		int py = y[i];
		
		sumx[px]++;
		sumy[py]++;
		
		ans += (n - sumx[px]) * (n - sumy[py]);
	}
	
	cout << total - (ans - total) << '\n';
}