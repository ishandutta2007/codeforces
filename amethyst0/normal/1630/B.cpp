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

const int maxn = (int)2e5 + 10;
int v[maxn];
int cnt[maxn];

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		scanf("%d %d", &n, &k);
		for (int i = 0; i < n; i++) {
			cnt[i] = 0;
		}
		
		for (int i = 0; i < n; i++) {
			scanf("%d", &v[i]);
			v[i]--;
			cnt[v[i]]++;
		}
		
		int sum = 0;
		
		int al = -1;
		int ar = n + 1;
		
		int r = 0;
		
		for (int i = 0; i < n; i++) {
			while (r < n && sum - (n - sum) < k) {
				sum += cnt[r];
				r++;
			}
			
			if (r - i < ar - al && sum - (n - sum) >= k) {
				al = i;
				ar = r;
			}
			sum -= cnt[i];
		}
		
		printf("%d %d\n", al + 1, ar);
		
		int pos = 0;
		
		while (k > 1) {
			k--;
			int bal = 0;
			int r = pos;
			
			for (int i = pos; i < n && bal <= 0; i++) {
				if (al <= v[i] && v[i] < ar) {
					bal++;
				} else {
					bal--;
				}
				r = i;
			}
			
			printf("%d %d\n", pos + 1, r + 1);
			pos = r + 1;
		}
		
		printf("%d %d\n", pos + 1, n);
	}
}