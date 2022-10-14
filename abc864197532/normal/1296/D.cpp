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

int main () {
	int n, a, b, k;
	cin >> n >> a >> b >> k;
	int in[n], need[n];
	fop (i,0,n) {
		cin >> in[i];
		if (in[i] % (a + b) <= a and in[i] % (a + b) > 0) need[i] = 0;
		else {
			if (in[i] % (a + b) == 0) need[i] = ((a + b + a - 1) / a) - 1;
			else need[i] = ((in[i] % (a + b) + a - 1) / a) - 1;
		}
	}
	sort(need, need + n);
	lli all = 0;
	int now = 0;
	while (all + need[now] <= k and now < n) {
		all += need[now];
		now++;
	}
	cout << now << endl;
}