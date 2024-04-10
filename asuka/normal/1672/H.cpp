#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;

const int N = 200015;

int n, q, pre[N][2];
char s[N];

int main() {
#ifdef Asuka
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	scanf("%d%d%s", &n, &q, s + 1);

	rep(i, 2, n) {
		if (s[i] == s[i - 1]) pre[i][s[i] - '0']++;

		rep(o, 0, 1) pre[i][o] += pre[i - 1][o];
	}

	rep(i, 1, q) {
		int l, r, u, v;
		scanf("%d%d", &l, &r);
		u = pre[r][0] - pre[l][0]; v = pre[r][1] - pre[l][1];
		printf("%d\n", max(u, v) + 1);
	}

	return 0;
}