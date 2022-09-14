#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <set>
#include <map>

#define ll long long

using namespace std;

const int maxn = (int)3e5 + 1;

int p[maxn];
int pr[maxn];

int cnt[maxn];

int d[maxn];

bool fl[maxn];
int numb[maxn];

int main() {
	for (int i = 2; i < maxn; i++) {
		if (p[i] == 0) {
			p[i] = i;
			
			if (i < maxn / i) {
				for (int j = i * i; j < maxn; j += i) {
					if (p[j] == 0) {
						p[j] = i;
					}
				}
			}
		}
	}
	
	pr[1] = 1;
	
	for (int i = 2; i < maxn; i++) {
		int y = i / p[i];
		
		if (p[y] == p[i]) {
			pr[i] = pr[y];
		} else {
			pr[i] = pr[y] * p[i];
		}
	}
	
	for (int i = 1; i < maxn; i++) {
		if (i != pr[i]) {
			continue;
		}
		
		numb[i] = 0;
		
		int x = i;
		
		while (x != 1) {
			numb[i]++;
			
			int y = x;
			
			while (p[x] == p[y]) {
				x /= p[x];
			}
		}
	}
	
	int n;
	
	cin >> n;
	
	for (int i = 1; i < maxn; i++) {
		d[i] = (int)1e9;
	}
	
	for (int i = 0; i < n; i++) {
		int x;
		
		scanf("%d", &x);
		
		x = pr[x];
		
		d[x] = 1;
		
		for (int j = 1; j * j <= x; j++) {
			if (x % j == 0) {
				cnt[j]++;
				
				if (j * j != x) {
					cnt[x / j]++;
				}
			}
		}
	}
	
	for (int i = maxn - 1; i >= 2; i--) {
		if (i != pr[i]) {
			continue;
		}
		
		int sum = 0;
		
		for (int j = 1; j * j <= i; j++) {
			if (i % j == 0) {
				if (numb[j] & 1) {
					sum -= cnt[j];
				} else {
					sum += cnt[j];
				}
				
				int x = i / j;
				
				if (numb[x] & 1) {
					sum -= cnt[x];
				} else {
					sum += cnt[x];
				}
			}
		}
		
		if (sum != 0) {
			fl[i] = true;
		}
	}
	
	for (int i = maxn - 1; i >= 2; i--) {
		if (d[i] != (int)1e9) {
			for (int j = 1; j * j <= i; j++) {
				if (i % j == 0) {
					int x = i / j;
					
					if (fl[j]) {
						d[x] = min(d[x], d[i] + 1);
					}
					
					if (fl[x]) {
						d[j] = min(d[j], d[i] + 1);
					}
				}
			}
		}
	}
	
	if (d[1] == (int)1e9) {
		cout << -1 << endl;
	} else {
		cout << d[1] << endl;
	}
	
	return 0;
}