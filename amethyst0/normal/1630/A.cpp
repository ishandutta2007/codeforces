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



void stup(int n) {
	vector <int> v;
	
	for (int i = 0; i < n; i++) {
		v.push_back(i);
	}
	
	set <int> was;
	
	while (true) {
		int s = 0;
		
		for (int i = 0; i < n; i += 2) {
			s += (v[i] & v[i + 1]);
		}
		
		if (!was.count(s) && s < n) {
			was.insert(s);
			cout << s << '\n';
		}
		
		if (!next_permutation(all(v))) {
			break;
		}
	}
}

const int maxn = (int)1e6;

int wh[maxn];
vector <int> res[maxn];

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		scanf("%d %d", &n, &k);
		
		if (n == 2 && k == 1) {
			printf("-1\n");
			continue;
		}
		
		if (n == 4 && k == 3) {
			printf("-1\n");
			continue;
		}
		
		for (int i = 0; i < n / 2; i++) {
			wh[i] = i;
			wh[(n - 1) ^ i] = i;
			res[i].clear();
		}
		
		if (k > 0) {
			if (k != n - 1) {
				swap(wh[k], wh[0]);
			} else {
				swap(wh[n - 2], wh[0]);
				swap(wh[3], wh[0]);
			}
		}
		
		for (int i = 0; i < n; i++) {
			res[wh[i]].push_back(i);
		}
		
		int ans = 0;
		
		for (int i = 0; i < n / 2; i++) {
			assert(res[i].size() == 2);
			ans += (res[i][0] & res[i][1]);
			printf("%d %d\n", res[i][0], res[i][1]);
		}
		
		assert(ans == k);
	}
	
	return 0;
}