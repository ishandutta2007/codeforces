/*















*/

#include <bits/stdc++.h>

using namespace std;

int l[4], s[4], r[4], p[4];

main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for(int i = 0; i < 4; i++) cin >> l[i] >> s[i] >> r[i] >> p[i];
	if((p[0] && (l[0] || s[0] || r[0] || l[1] || s[2] || r[3])) ||
	   (p[1] && (l[1] || s[1] || r[1] || l[2] || s[3] || r[0])) ||
	   (p[2] && (l[2] || s[2] || r[2] || l[3] || s[0] || r[1])) ||
	   (p[3] && (l[3] || s[3] || r[3] || l[0] || s[1] || r[2]))) cout << "YES";
	else cout << "NO";
}