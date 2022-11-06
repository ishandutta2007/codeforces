#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <cmath>
#include <deque>
#include <stack>
#include <list>
#include <unordered_map>
#include <queue>

using namespace std;

struct Prob {
	int idx;
	int a, t;
	bool operator<(const Prob &other) const {
		return t < other.t;
	}
};

int n, T;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> T;

	vector<Prob> probs(n);
	for (int i = 0; i < n; ++i) {
		probs[i].idx = i + 1;
		cin >> probs[i].a >> probs[i].t;
	}

	sort(probs.begin(), probs.end(), [](const Prob &lhs, const Prob &rhs) {
		return lhs.a < rhs.a;
	});

	priority_queue<Prob> pq;
	long long sumInQ = 0;
	for (int pbCnt = n; pbCnt >= 1; --pbCnt) {
		while (!probs.empty() && probs.back().a >= pbCnt) {
			pq.push(probs.back());
			sumInQ += probs.back().t;
			probs.pop_back();
		}
		while (pq.size() > pbCnt) {
			sumInQ -= pq.top().t;
			pq.pop();
		}
		if (pq.size() == pbCnt && sumInQ <= T) {
			cout << pbCnt << '\n' << pbCnt << '\n';
			cout << pq.top().idx;
			pq.pop();
			while (!pq.empty()) {
				cout << ' ' << pq.top().idx;
				pq.pop();
			}
			return 0;
		}
	}
	cout << "0\n0\n";
	return 0;
}