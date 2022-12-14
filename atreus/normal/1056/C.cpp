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
const int maxn = 1e5 + 100;

int p[maxn], mch[maxn];

bool cmp (int fi, int se) {
	return p[fi] > p[se];
}

int main() {
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= 2 * n; i++)
		cin >> p[i];
	for (int i = 1; i <= m; i++) {
		int fi, se;
		cin >> fi >> se;
		mch[fi] = se;
		mch[se] = fi;
	}
	
	int cnt = 0;
	int t;
	cin >> t;
	
	if (t == 2) {
		int x;
		cin >> x;
		cnt ++;
		while (mch[x] > 0) {
			cout << mch[x] << endl;
			mch[mch[x]] = -1;
			mch[x] = -1;
			
			cnt ++;
			cin >> x;
			cnt ++;
		}
		mch[x] = -1;
	}

	for (int i = 1; i <= 2 * n; i++) {
		if (mch[i] > 0) {
			int fi = p[i];
			int se = p[mch[i]];
			if (fi > se) {
				cout << i << endl;
				cnt ++;
			}
			else {
				cout << mch[i] << endl;
				cnt ++;
			}
			int dis;
			cin >> dis;
			cnt ++;
			mch[mch[i]] = -1;
			mch[i] = -1;
		}
	}

	vector <int> v;
	for (int i = 1; i <= 2 * n; i++) {
		if (mch[i] == 0)
			v.PB (i);
	}
	
	sort (v.begin(), v.end(), cmp);
	for (auto it : v) {
		if (mch[it] == 0) {
			cout << it << endl;
			mch[it] = -1;
			cnt ++;
			
			if (cnt == 2 * n)
				return 0;
			
			int x;
			cin >> x;
			cnt ++;
			mch[x] = -1;
		}
	}

}