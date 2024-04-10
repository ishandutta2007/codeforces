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
	int N, R;
	cin >> N >> R;
	vector<int> A(1 << N);
	int res = 0;
	int sum = 0;
	for (int i = 0; i < (1 << N); i++) {
		cin >> A[i];
		sum += A[i];
	}
	int a;
	int b;
	cout << fixed << setprecision(15);
	cout << (double)sum / (1 << N) << endl;
	for (int i = 0; i < R; i++){
		cin >> a >> b;
		sum += b - A[a];
		A[a] = b;
		cout << (double)sum / (1 << N) << endl;
	}
}