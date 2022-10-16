#include <iostream>
#include <queue>
#include <utility>

#define lint long long int
using namespace std;

priority_queue <pair <lint, int> , vector <pair <lint, int> >, greater <pair <lint, int> > > pq;

const int NMAX = 200000 + 5;

lint v[NMAX];

inline lint absss(lint x) {
	if (x < 0)
		return -x;
	return x;
}

int main() {
	ios_base :: sync_with_stdio(false);

	int n, k, x;
	cin >> n >> k >> x;

	int semn = 1;
	for (int i = 1; i <= n; ++ i) {
		cin >> v[i];

		if (v[i] < 0)
			semn *= (-1);
		pq.push(make_pair(absss(v[i]), i));
	}

	while (k --) {
		int where = pq.top().second;
		pq.pop();

		if (semn == 1) {
			if (v[where] > 0) {
				v[where] -= x;
				if (v[where] < 0)
					semn *= (-1);
			}
			else if (v[where] == 0) {
				v[where] -= x;
				semn *= (-1);
			}
			else if (v[where] < 0) {
				v[where] += x;
				if (v[where] > 0)
					semn *= (-1);
				else if (v[where] == 0)
					semn = -1;
			}
		}
		else {
			if (v[where] < 0)
				v[where] -= x;
			else if (v[where] >= 0)
				v[where] += x;
		}

		pq.push(make_pair(absss(v[where]), where));
	}

	for (int i = 1; i <= n; ++ i)
		cout << v[i] << " \n"[i == n];
	return 0;
}