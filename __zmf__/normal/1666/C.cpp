#include <bits/stdc++.h>
using namespace std;

#define PB push_back
// #define int long long
#define ll long long
#define vi vector<int>
#define siz(a) ((int)((a).size()))
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

int a;
struct node {
	int x, y;
} s[3];

signed main() {
	// freopen("in.in", "r", stdin);
	// freopen("out.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	rep(i, 0, 2) cin >> s[i].x >> s[i].y;
	sort(s, s + 3, [&](node x, node y) {return x.y < y.y;});
	cout << "3\n";
	cout << min(min(s[0].x, s[1].x), s[2].x) << ' ' << s[1].y << ' ' << max(max(s[0].x, s[1].x), s[2].x) << ' ' << s[1].y << endl;
	cout << s[0].x << ' ' << s[0].y << ' ' << s[0].x << ' ' << s[1].y << endl;
	cout << s[2].x << ' ' << s[2].y << ' ' << s[2].x << ' ' << s[1].y;
	return 0;
}