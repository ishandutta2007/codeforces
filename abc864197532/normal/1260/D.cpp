#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m)-((m)>(n));i!=(n)-((m)>(n));i+=2*((m)<(n))-1)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair <int,int>
vector <pii> trap[200001];
int maxx[200001];
vector <int> a(200001);
int m,n,q,t;
 
bool bigger (pii a, pii b) {
	if (a.second != b.second) return a.second > b.second;
	return a.first > b.first;
}
 
 
bool find(int v) {
	int k = t;
	vector <pii> nums;
	int now, l, r;
	bool is = false;
	fop (i,1,n+1) {
		fop (j,0,trap[i].size()) {
			if (trap[i][j].second > a[v]) {
				if (!is) {
					l = i - 1;
					r = trap[i][j].first;
					now = r - l;
					is = true;
					break;
				}
				if (r >= i - 1) {
					now += max(trap[i][j].first - r, 0);
					r = max(trap[i][j].first , r);
				} else {
					l = i - 1;
					r = trap[i][j].first;
					now += (trap[i][j].first - i + 1);
				}
				break;
			}
		}
	}
	return !is or k >= (now * 2);
}
 
 
int main () {
	cin >> m >> n >> q >> t;
	fop (i,0,m) cin >> a[i];
	a.resize(m);
	sort(a.begin(), a.end());
	t -= (n + 1);
	fop (i,0,q) {
		int aa,bb,cc;
		cin >> aa >> bb >> cc;
		trap[aa].eb(bb, cc);
	}
	fop (i,1,n+1) {
		if (!trap[i].size()) continue;
		sort(trap[i].begin(), trap[i].end(), bigger);
		fop (j,1,trap[i].size()) {
			trap[i][j].first = max(trap[i][j].first, trap[i][j-1].first);
		}
		reverse(trap[i].begin(), trap[i].end());
	}
	int l = 0, r = m;
	while (r > l) {
		int m = l + r >> 1;
		if (find(m)) r = m;
		else l = m + 1;
	}
	cout << m - l << endl;
}