#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i = (m); i < (n); ++i)
#define FOP(i,m,n) for (int i = (m) - 1; i >= (n); --i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<lli,int>
#define X first
#define Y second
#define MAXN 100087

int main () {
	int n;
	cin >> n;
	int input[n + 1], p;
	fop (i,1,n+1) {
		cin >> input[i];
		if (input[i] == -1) p = i;
	}
	int k = 2;
	if (p == n) {
		cout << 0 << endl;
		return 0;
	}
	lli ans = 0;
	priority_queue <int, vector <int>, greater <int>> pq;
	pq.push(input[n]);
	int now = n;
	while (true) {
		ans += pq.top(); pq.pop();
		bool is = true;
		for (int j = n / k; j > 0; --j) {
			if (now - j == p) {
				is = false;
				break;
			}
			pq.push(input[now - j]);
		}
		if (!is) break;
		now /= 2;
		k *= 2;
	}
	cout << ans << endl;
}