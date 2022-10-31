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
int MOD = 1000000007;
vector<vector<int> > X;
priority_queue<pair<int, int> > pq;
bool check(const vector<pair<int, int> > &p, vector<int> &rs) {
	int k = p.size();
	X.clear();
	X.resize(k);
	for (int i = 0; i < k; i++) {
		if (p[i].first > p[i].second)return false;
		X[p[i].first].push_back(i);
	}
	rs.clear();
	int a = 0;
	while (pq.size())pq.pop();
	for (int i = 0; i < k; i++) {
		for (auto x : X[i]) {
			pq.emplace(-p[x].second, x);
		}
		if (pq.size() == 0)return false;
		a = pq.top().second;
		//cerr << "a=" << a << " " << p[a].second <<  endl;
		pq.pop();
		if (p[a].second < i)return false;
		rs.push_back(a);
	}
	return true;
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	vector<int> S;
	vector<int> A;
	vector<int> B;
	string _S;
	string _A;
	string _B;
	while (t--) {
		int K;
		cin >> K;
		S.clear();
		A.clear();
		B.clear();
		int N;
		{
		
			cin >> _S;
			cin >> _A;
			cin >> _B;
			N = _S.size();
			S.resize(N);
			A.resize(N);
			B.resize(N);
			for (int i = 0; i < N; i++) {
				S[i] = _S[i] - 'a';
				A[i] = _A[i] - 'a';
				B[i] = _B[i] - 'a';
			}
		}
		vector<pair<int, int> > p(K);
		for (int i = 0; i < K; i++) {
			p[i].first = 0;
			p[i].second = K - 1;
		}
		int a = N;
		for (int i = 0; i < N; i++) {
			if (A[i] != B[i]) {
				a = i;
				break;
			}
			p[S[i]].first = max(p[S[i]].first, A[i]);
			p[S[i]].second = min(p[S[i]].second, A[i]);
		}
		vector<pair<int, int> > tp = p;
		vector<int> res;
		if (a < N) {
			int bf;
			int bs;
			p[S[a]].first = max(p[S[a]].first, A[a] + 1);
			p[S[a]].second = min(p[S[a]].second, B[a] - 1);
			if (check(p, res))goto OUT;

			p = tp;
			p[S[a]].first = max(p[S[a]].first, A[a]);
			p[S[a]].second = min(p[S[a]].second, A[a]);
			if (check(p, res)) {
				res.clear();

				for (int i = a + 1; i < N; i++) {
					//if (p[S[i]].first == A[i] && p[S[i]].second == A[i])continue;

					if (p[S[i]].first < A[i] + 1) {
						if (p[S[i]].first < p[S[i]].second) {
							bf = p[S[i]].first;
							p[S[i]].first = A[i] + 1;
							if (check(p, res))goto OUT;
							p[S[i]].first = bf;
						}
					}
					else {
						if (check(p, res))goto OUT;
						else break;
					}

					p[S[i]].first = max(p[S[i]].first, A[i]);
					p[S[i]].second = min(p[S[i]].second, A[i]);
					if (p[S[i]].first > p[S[i]].second)break;
				}
				if (check(p, res))goto OUT;
			}

			p = tp;
			p[S[a]].first = max(p[S[a]].first, B[a]);
			p[S[a]].second = min(p[S[a]].second, B[a]);
			if (check(p, res)) {
				res.clear();
				for (int i = a + 1; i < N; i++) {
					//if (p[S[i]].first == B[i] && p[S[i]].second == B[i])continue;
					if (p[S[i]].second > B[i] - 1) {
						if (p[S[i]].first < p[S[i]].second) {
							bs = p[S[i]].second;
							p[S[i]].second = B[i] - 1;
							if (check(p, res))goto OUT;
							p[S[i]].second = bs;
						}
					}
					else {
						if (check(p, res))goto OUT;
						else break;
					}
					p[S[i]].first = max(p[S[i]].first, B[i]);
					p[S[i]].second = min(p[S[i]].second, B[i]);
					if (p[S[i]].first > p[S[i]].second)break;

				}
				if (check(p, res))goto OUT;
			}
		}
		else {
			/*for (int i = 0; i < K; i++) {
				cerr << K << " " << p[i].first << " " << p[i].second << endl;
			}*/
			if (check(p, res))goto OUT;
		}
	OUT:
		if (res.size() == K) {
			cout << "YES" << "\n";
			string ans(K, 'a');

			for (int i = 0; i < K; i++) {
				ans[res[i]] = i + 'a';
			}

			cout << ans << "\n";
		}
		else {
			cout << "NO" << "\n";
		}

	}
}