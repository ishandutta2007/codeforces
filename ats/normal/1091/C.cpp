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
	int N;
	cin >> N;
	set<int> st;
	for (int i = 1; i*i <= N; i++) {
		if (N%i == 0) {
			int a = i;
			for (int j = 0; j < 2; j++) {
				int z = N / a;


				st.insert(z + (a * z * (z - 1) / 2));



				if (i*i == N)break;
				a = N / i;
			}
		}
	}
	bool fi = true;
	for (auto s : st) {
		if (fi)fi = false;
		else cout << " ";
		cout << s;
	}
	cout << endl;
}