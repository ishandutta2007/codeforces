#include <bits/stdc++.h>

using namespace std;

const int N = 200005;

long long a[N], b[N], t[N], n, k, cnt[N];

struct Stu {
	long long id, min;
};

struct cmp{
    bool operator() (Stu a,Stu b) {
        return a.min > b.min;
    }
};

priority_queue<Stu, vector<Stu>, cmp> q;

bool check(long long x) {
	q = priority_queue<Stu, vector<Stu>, cmp>();
	for (int i = 1; i <= n; i++) {
		cnt[i] = 0;
		Stu u;
		u.id = i;
		u.min = a[i] / b[i] + 1;
		q.push(u);
	}
	for (int i = 1; i <= k; i++) {
		Stu u = q.top();
		q.pop();
		if (u.min < i) {
			return false;
		}
		cnt[u.id]++;
		u.min = (a[u.id] + x * cnt[u.id]) / b[u.id] + 1;
		q.push(u);
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("in", "r", stdin);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
	}
	long long l = 0, r = 2000000000005;
	while (l + 1 < r) {
		long long mid = (l + r) / 2;
		if (check(mid)) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	for (long long i = l; i <= r; i++) {
		if (check(i)) {
			return cout << i, 0;
		}
	}
	cout << -1;
	return 0;
}