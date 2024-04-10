#include <bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define PF push_front
#define MP make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int maxn = 1e5 + 10;
int n, x[maxn];

void vitex (set <int> &s, int mid, int i) {
	while (!s.empty() and abs (*s.begin() - x[i]) > mid) {
		s.erase (s.begin());
	}
	while (!s.empty()) {
		auto it = s.end();
		it --;
		if (abs (*it - x[i]) > mid) 
			s.erase (it);
		else
			break;
	}
}

bool check (int mid, int s, int t) {
	set <int> s1, s2;
	s1.insert (s);
	s2.insert (t);
	for (int i = 0; i < n; i++) {
		vitex (s1, mid, i);
		vitex (s2, mid, i);
		bool E1 = !(s1.empty()), E2 = !(s2.empty());
		if (E1)
			s2.insert (x[i]);
		if (E2)
			s1.insert (x[i]);
	}
	if (!s1.empty() or !s2.empty())
		return 1;
	return 0;
}

int main () {
	ios::sync_with_stdio(false);
	int s, t;
	cin >> n >> s >> t;
	for (int i = 0; i < n; i++)
		cin >> x[i];
	if (s > t)
		swap (s, t);
	int lo = t - s - 1, hi = 1000 * 1000 * 1000;
	while (hi - lo > 1) {
		int mid = (hi + lo) >> 1;
		if (check (mid, s, t))
			hi = mid;
		else
			lo = mid;	
	}
	cout << hi << endl;
}