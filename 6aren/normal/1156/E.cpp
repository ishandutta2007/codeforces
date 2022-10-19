#include<bits/stdc++.h>

using namespace std;

const int N = 200005;

int n, p[N], pos[N], l[N], r[N];
long long ans = 0;
stack<int> s;

void calc(int id, int ll, int rr) {
	if (id - ll <= rr - id) {
		for (int i = ll; i < id; i++) {
			int t = pos[p[id] - p[i]];
			if ((t > id) && (t <= rr)) ans++;
		}
	} else {
		for (int i = rr; i > id; i--) {
			int t = pos[p[id] - p[i]];
			if ((t >= ll) && (t < id)) ans++;
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("in", "r", stdin);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
		pos[p[i]] = i;
	}
	p[0] = 200001;
	s.push(0);
	for (int i = 1; i <= n; i++) {
		while (p[s.top()] < p[i]) {
			s.pop();
		}
		l[i] = s.top() + 1;
		s.push(i);
	}
	while (!s.empty()) s.pop();
	s.push(n + 1);
	p[n + 1] = 200001;
	for (int i = n; i >= 1; i--) {
		while(p[s.top()] < p[i]) {
			s.pop();
		}
		r[i] = s.top() - 1;
		s.push(i);
	}
	for (int i = 1; i <= n; i++) {
		calc(i, l[i], r[i]);
	}
	cout << ans;
	return 0;
}