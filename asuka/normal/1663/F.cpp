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

int main() {
#ifdef Asuka
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	string s;
	cin >> s;

	if (SZ(s) == 4) {
		puts("none");
		return 0;
	}

	string ns = SZ(s) == 3 ? "the" : SZ(s) == 5 ? "buffy" : SZ(s) == 6 ? "slayer" : "vampire";

	rep(i, 0, SZ(s) - 1) {
		printf("%c", ((s[i] - 'a') + (ns[i] - 'a')) % 26 + 'a');
	}

	return 0;
}