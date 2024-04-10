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
	vector<int> A(N);
	int res = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		A[i] -= i;
	}

	vector<int> P;
	P.push_back(-1e9 - 5);
	vector<int> V;
	V.push_back(0);


	for (int i = 0; i < N; i++) {
		vector<int> nP;
		vector<int> nV;
		for (int j = 0; j < P.size(); j++) {
			nP.push_back(P[j]);
			nV.push_back(V[j] + abs(P[j] - A[i]));
			if (P[j] < A[i] && (j == (int)P.size() - 1 || A[i] < P[j + 1])) {
				nP.push_back(A[i]);
				if (j == (int)P.size() - 1) {
					nV.push_back(V[j]);
				}
				else {
					int s = (V[j + 1] - V[j]) / (P[j + 1] - P[j]);
					nV.push_back(V[j] + s * (A[i] - P[j]));
				}


			}
			

		}
		swap(P, nP);
		swap(V, nV);
		while ((int)V.size() >= 2 && V.back() >= V[(int)V.size() - 2]) {
			V.pop_back();
			P.pop_back();
		}
	/*	for (int j = 0; j < P.size(); j++) {
			cerr << P[j] << " ";
		}
		cerr << endl;
		for (int j = 0; j < P.size(); j++) {
			cerr << V[j] << " ";
		}
		cerr << endl;
		cerr << endl;*/
	}


	cout << V.back() << endl;
}