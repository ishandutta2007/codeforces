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

const int N = 205;

pair<int, vector<char>> FK(char s[]) {
	int fl = 0;
	vector<char> vec;

	for (int i = 1; s[i]; ++i) {
		if (s[i] == 'B') fl ^= 1;
		else {
			if (SZ(vec) > 0 && vec.back() == s[i]) vec.pop_back();
			else vec.push_back(s[i]);
		}
	}

	return mp(fl, vec);
}


char s[N], t[N];

void solve() {
	scanf("%s%s", s + 1, t + 1);
	auto u = FK(s);
	auto v = FK(t);

	puts(u == v ? "YES" : "NO");
}

int main() {
#ifdef Asuka
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif

	int T;

	for (scanf("%d", &T); T; T--) solve();

	return 0;
}