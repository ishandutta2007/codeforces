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
	int H, W;
	cin >> H >> W;
	vector<string> A(H);
	int res = 0;
	for (int i = 0; i < H; i++) {
		cin >> A[i];
	}
	string a;
	for (int i = 0; i < H - 1; i++) {
		for (int j = 0; j < W - 1; j++) {
			a.clear();
			for (int x = i; x <= i + 1; x++) {
				for (int y = j; y <= j + 1; y++) {
					a.push_back(A[x][y]);
				}
			}
			sort(a.begin(), a.end());
			if (a == "acef")res++;
		}
	}
	cout << res << endl;
}