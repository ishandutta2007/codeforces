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
int gcd(int a, int b) {
	while (b > 0) {
		int t = a % b;
		a = b;
		b = t;
	}
	return a;
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<int> A(N);
	int res = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	map<int, vector<int> > mp;
	
	map<int, int> ptr;
	map<int, int> sum; 
	vector<int> mx;
	for (int len = N - 1; len >= 1; len--) {
		int g = gcd(N, len);
		if (mp.find(g) == mp.end()) {
			mx.clear();
			mx.resize(g, 0);
			for (int i = 0; i < N; i++) {
				mx[i % g] = max(mx[i % g], A[i]);
			}
			int b = 0;
			auto &vec = mp[g];
			for (int i = 0; i < N; i++) {
				if (mx[i % g] == A[i]) {
					
					if (b == 0) {
						vec.push_back(1);
					}
					else {
						vec.back()++;
					}
					b = 1;
				}
				else {
					b = 0;
				}
			}
			/*if (len == 2) {
				cerr << mx[0] << " " << mx[1] << endl;
			}*/
			if (mx[0] == A[0] && mx[(N - 1)%g] == A[N - 1]) {
				
				vec[0] += vec.back();
				vec.pop_back();
			}
			sort(vec.rbegin(), vec.rend());
			ptr[g] = 0;

		}

		{		

			//cerr <<"len = " <<  len << endl;
			vector<int> &vec = mp[g];
			/*for (auto v : vec) {
				cerr << v << " ";
			}
			cerr << endl;*/
			if (vec[0] == 2 * N) {
				res += N;
			}
			else {
				int p = ptr[g];
				int sm = sum[g];
				while (p < (int)vec.size() && vec[p] >= len) {
					sm += vec[p];
					p++;
				}

				res += p + sm - p * len;


				ptr[g] = p;
				sum[g] = sm;
			}
			
		}
	}
	cout << res << endl;
}