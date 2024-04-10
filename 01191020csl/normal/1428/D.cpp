#include<bits/stdc++.h>
using namespace std;
int x[200001], y[200001], a[100001];
deque<int> dq;
queue<pair<int, int> > q1, q2;
void noanswer() {
	puts("-1");
	exit(0);
}
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) dq.push_front(i);
	int tot = 0;
	for (int i = n; i >= 1; i--) {
		if (a[i] == 0) continue;
		if (a[i] == 1) {
			if (dq.empty()) noanswer();
			++tot, x[tot] = dq.front(), y[tot] = i;
			q1.push(make_pair(i, dq.front())), dq.pop_front();
		}
		if (a[i] == 2) {
			if (q1.empty()) noanswer();
			++tot, x[tot] = q1.front().second, y[tot] = i;
			q2.push(make_pair(i, q1.front().second)), q1.pop();
		}
		if (a[i] == 3) {
			if (dq.empty() || (q1.empty() && q2.empty())) noanswer();
			++tot, x[tot] = dq.front(), y[tot] = i;
			++tot, x[tot] = dq.front(), y[tot] = q2.size()?q2.front().first:q1.front().first;
			if (q2.size()) q2.pop();
			else q1.pop();
			q2.push(make_pair(i, dq.front())), dq.pop_front();
		}
	}
	cout << tot << endl;
	for (int i = 1; i <= tot; i++) cout << x[i] << ' ' << y[i] << endl;
}