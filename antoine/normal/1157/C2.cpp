#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int cntL(deque<int> dq) {
	const int n = (int) dq.size();
	int i = 0;
	while (i + 1 < n && dq[i] < dq[i + 1])
		++i;
	return i + 1;
}
int cntR(deque<int> dq) {
	reverse(dq.begin(), dq.end());
	return cntL(dq);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	deque<int> dq;

	{
		int n;
		cin >> n;
		while (n--) {
			int x;
			cin >> x;
			dq.push_back(x);
		}
	}

	string res;

	int last = -1;

	auto left = [&]() {
		res += 'L';
		last = dq.front();
		dq.pop_front();
	};
	auto right = [&]() {
		last = dq.back();
		res += 'R';
		dq.pop_back();
	};

	while (!dq.empty()) {
		if (last >= dq.front() && last >= dq.back())
			break;
		if (last >= dq.front())
			right();
		else if (last >= dq.back())
			left();
		else if (dq.front() < dq.back())
			left();
		else if (dq.back() < dq.front())
			right();
		else {
			const int cl = cntL(dq);
			const int cr = cntR(dq);

			if (cl > cr)
				res += string(cl, 'L');
			else
				res += string(cr, 'R');
			break;
		}
	}

	cout << res.size() << endl << res;
	return 0;
}