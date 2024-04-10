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
int isprime(int N) {
	for (int i = 2; i*i <= N; i++) {
		if (N%i == 0)return false;
	}
	return true;
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;

	vector<pair<int, int> > res;
	for (int i = 0; i < N; i++) {
		res.emplace_back(i, (i + 1) % N);
	}
	int h = (N / 2);
	for (int i = 0; i + h < N; i++) {
		if (isprime(N + i))break;
		res.emplace_back(i, i + h);
	}

	cout << res.size() << endl;
	for (int i = 0; i < res.size(); i++) {
		cout << res[i].first + 1 << " " << res[i].second + 1 << endl;
	}

}