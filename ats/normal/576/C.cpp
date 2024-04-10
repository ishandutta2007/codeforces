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
struct P {
	int x;
	int y;
	int idx;
	bool operator<(const P &right)const {
		return x < right.x;
	}
};
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<P> A(N);
	vector<int> res;
	int a, b;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		A[i] = P{ a,b,i };
	}
	sort(A.begin(), A.end());

	int z = -1;
	int l;
	int c = 1;
	vector<P> B;
	
	for (int i = 0; i <= N; i++) {
		if (z == -1) {
			l = A[i].x;
			c = 1 - c;
			B.push_back(A[i]);
			z = 0;
		}
		else {
		
			if (i == N || A[i].x - l >= 1000 || c == 1000) {
				for (int j = 0; j < B.size(); j++) {
					swap(B[j].x, B[j].y);
				}
				if (c == 0) {
					sort(B.begin(), B.end());
				}
				else {
					sort(B.rbegin(), B.rend());
				}
				for (int j = 0; j < B.size(); j++) {
					res.push_back(B[j].idx);
				}
				B.clear();
				l = A[i].x;
				c = 1 - c;
			}
			if(i < N)B.push_back(A[i]);
		}
	}
	for (int i = 0; i < res.size(); i++) {
		if (i > 0)cout << " ";
		cout << res[i] + 1;
	}
	cout << endl;
}