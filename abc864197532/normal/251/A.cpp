#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 
#define X first
#define Y second

int main() {
	int n, d;
	cin >> n >> d;
	int in[n];
	fop (i,0,n) cin >> in[i];
	deque <int> dq;
	lli ans = 0;
	fop (i,0,n) {
		while (dq.size() and in[i] - in[dq.front()] > d) dq.pop_front();
		if (dq.size() >= 2) ans += (1ll * dq.size() * (dq.size() - 1) / 2);
		dq.push_back(i);
	}
	cout << ans << endl;
}