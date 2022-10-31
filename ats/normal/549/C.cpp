#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <stdio.h>
using namespace std;
#define int long long
int MOD = 1000000007;
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, K;
	cin >> N >> K;
	int _N = N;
	int a;
	int e = 0;
	int o = 0;
	for (int i = 0; i < N; i++) {
		cin >> a;
		if (a % 2 == 0)e++;
		else o++;
	}
	int ee = e;
	int oo = o;
	int t = 1;
	int advantage = (N - K) % 2;
	int s = o % 2;
	while (N > K) {
		if (t == advantage) {
			if (e == 0) {
				o--;
				s++;
			}
			else if (o == 0) {
				e--;
			}
			else {
				if (N > K + 2 || (t == 0 && N >= K + 2)) {
					e--;
				}
				else if (N == K + 1) {
					if (t == s % 2) {
						e--;
					}
					else {
						o--;
						s++;
					}
				}
				else {
					if (e > o) {
						e--;
					}
					else {
						o--;
						s++;
					}
				}
			}
		}
		else {
			if (e == 0) {
				o--;
				s++;
			}
			else if (o == 0) {
				e--;
			}
			else {
				if (N > K + 2 || (t == 0 && N >= K + 2)) {
					o--; s++;
				}
				else {
					if (e < o) {
						e--;
					}
					else {
						o--;
						s++;
					}
				}
			}
		}
		t = 1 - t;
		N--;
	}
	cerr << s << endl;
	if (s % 2 == 0) {
		cout << "Daenerys" << endl;
	}
	else {
		cout << "Stannis" << endl;
	}
}