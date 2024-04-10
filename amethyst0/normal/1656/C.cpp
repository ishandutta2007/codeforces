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

const int maxn = (int)1e5 + 10;
int a[maxn];

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		scanf("%d", &n);
		
		bool is0 = false;
		bool is1 = false;
		
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			
			if (a[i] == 0) {
				is0 = true;
			}
			
			if (a[i] == 1) {
				is1 = true;
			}
		}
		
		if (!is1) {
			printf("YES\n");
			continue;
		}
		
		if (is0) {
			printf("NO\n");
			continue;
		}
		
		sort(a, a + n);
		
		bool ok = true;
		
		for (int i = 0; i < n - 1; i++) {
			if (a[i + 1] == a[i] + 1) {
				 ok = false;
			 }
		 }
		 
		 if (ok) {
			 printf("YES\n");
		 } else {
			 printf("NO\n");
		 }
	}
}