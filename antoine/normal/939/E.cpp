#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
#include <iomanip>
#include <functional>

using namespace std;

struct SubSet {
	int count = 0;
	long long sum = 0;

	void add(int x) {
		sum += x;
		++count;
	}

	void rem(int x) {
		sum -= x;
		--count;
	}

	double avg() {
		return cout ? ((double)sum / count) : 0;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	SubSet s;
	vector<int> S;
	
	int Q;
	cin >> Q;
	
	int i = 0;

	while (Q-- > 0) {
		int type;
		cin >> type;
		if (type == 1) {
			int x;
			cin >> x;
			if (!S.empty())
				s.rem(S.back());
			s.add(x);
			S.push_back(x);
			while (i < S.size() - 1 && S[i] <= s.avg()) {
				s.add(S[i++]);
			}
		}
		else {
			cout << setprecision(10) << S.back() - s.avg() << '\n';
		}
	}

	return 0;
}