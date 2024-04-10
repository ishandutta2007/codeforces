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
const int N = 400087;

int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, tmp;
	cin >> n;
	vector <pii> A;
	fop (i,0,n) {
		cin >> tmp;
		A.eb(tmp - i, tmp);
	}
	sort(A.begin(), A.end());
	lli ans = 0, all = 0;
	int now = 0, back = A[0].X;
	while (now < n) {
		while (now < n and A[now].X == back) {
			all += A[now].Y;
			now++;
		}
		ans = max(ans, all);
		all = 0;
		back = A[now].X;
	}
	cout << ans << endl;
}