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
	int a;
	int res = 0;
	set<int> st;
	for (int i = 0; i < N; i++) {
		cin >> a;
		st.insert(a);
	}
	int k = 0;
	int b = 0;
	for (auto s : st) {
		cout << s - b << endl;
		b = s;
		k++;
		if (k == K)break;
	}
	while (k < K) {
		cout << 0 << endl;
		k++;
	}
}