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
	int x;
	cin >> s >> x;

	if (s == "ABC" || s == "abc") {
		puts(x <= 1999 ? "YES" : "NO");

	} else if (s == "ARC" || s == "arc") {
		puts(x <= 2799 ? "YES" : "NO");

	} else {
		puts(x >= 1200 ? "YES" : "NO");
	}

	return 0;
}