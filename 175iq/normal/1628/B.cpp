#include<iostream>
#include<vector>
#include<deque>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<utility>
#include<tuple>
#include<algorithm>
using namespace std;
typedef long long ll;
#define For(i, l, r) for (int i=l; i<r; i++)
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	bool vis2[26][26], vis3[26][26], vis33[26][26][26];
	cin >> t;
	while (t--) {
		int n;
		bool can = false;
		string s;
		cin >> n;
		For(i, 0, 26) {
			fill(vis2[i], vis2[i]+26, false);
			fill(vis3[i], vis3[i]+26, false);
			For(j, 0, 26) fill(vis33[i][j], vis33[i][j]+26, false);
		}
		For(i, 0, n) {
			cin >> s;
			int l = s.size();
			if (l == 1) can = true;
			else if (l == 2) {
				if (s[0] == s[1]) can = true;
				int a = s[0] - 'a', b = s[1] - 'a';
				if (vis2[b][a]) can = true;
				if (vis3[b][a]) can = true;
				vis2[a][b] = true;
			}
			else if (l == 3) {
				if (s[0] == s[2]) can = true;
				int a = s[0], b = s[1], c = s[2];
				a -= 'a', b -= 'a', c -= 'a';
				vis3[a][b] = true;
				if (vis33[c][b][a]) can = true;
				if (vis2[c][b]) can = true;
				vis33[a][b][c] = true;
			}
		}
		
		
		if (can) cout << "YES\n";
		else cout << "NO\n";
	}
}