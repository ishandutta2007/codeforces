#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
const int N = 200015;
int n, mat[N], ans;
char s[N];

void gao(int l, int r) {
	if (l > r) return;
	ans++;

	for (int i = l; i <= r; i = mat[i] + 1)
		gao(i + 1, mat[i] - 1);
}

void solve() {
	scanf("%d", &n);
	scanf("%s", s + 1);
	vector<int> vec;

	rep(i, 1, n * 2) {
		if (s[i] == '(') {
			vec.pb(i);
		} else {
			int j = vec.back();
			vec.pop_back();
			mat[j] = i;
		}
	}

	ans = 0;
	gao(1, n * 2);
	printf("%d\n", ans);
}

int main() {
#ifdef Asuka
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
#endif
	int t;
	scanf("%d", &t);
	while (t--) solve();
	return 0;
}