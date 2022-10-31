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
//#define int long long
int MOD = 1000000007;
struct Node {
	int ch[2];
	int p;
	char type;
	int val = 1;
	Node() {
		ch[0] = ch[1] = -1;
	}
};
vector<Node> ns;
int add(int &a, int &b) {
	a = a + b;
	if (a >= MOD)a -= MOD;
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}


	ns.resize(1);
	ns[0].val = 1;
	ns[0].p = -1;
	ns[0].type = 0;


	vector<int> cur;

	vector<int> res(N, 0);
	Node n;
	for (int i = 0; i < N; i++) {
		cur.push_back(0);
		if (i > 0)res[i] = res[i - 1];
		for (int x = 0; x < cur.size(); x++) {
			if (ns[cur[x]].ch[A[i]] == -1) {
				int idx = ns.size();
				ns[cur[x]].ch[A[i]] = idx;
				ns.push_back(n);

				ns.back().type = A[i];
				ns.back().p = cur[x];

				cur[x] = idx;



				ns.back().val = 0;
				
				int t = 0;
				int ii = idx;
				for (int k = 0; k < 4; k++) {
					t *= 2;
					t += ns[ii].type;
					ii = ns[ii].p;
					if (ii == -1)break;
					if (k < 3) {
						add(ns.back().val, ns[ii].val);
					}
					else {
						if (t != 12 && t != 10 && t != 7 && t != 15) {
							add(ns.back().val, ns[ii].val);
						}
					}
				}
				//cerr << ns.back().val << endl;
				add(res[i], ns.back().val);
			}
			else {
				cur[x] = ns[cur[x]].ch[A[i]];
			}
		}



	}

	for (int i = 0; i < N; i++) {
		cout << res[i] << endl;
	}
}