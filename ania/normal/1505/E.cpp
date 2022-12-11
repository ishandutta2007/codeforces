#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for (int i = (a); i <= (b); ++i)
#define REPD(i,a,b) for (int i = (a); i >= (b); --i)
#define FORI(i,n) REP(i,1,n)
#define FOR(i,n) REP(i,0,int(n)-1)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define ll long long
#define SZ(x) int((x).size())
#define DBG(v) cerr << #v << " = " << (v) << endl;
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define fi first
#define se second

int n,m;
string s[55];

int main() {
	cin >> n >> m;
	FOR(i,n) cin >> s[i];
	int x = 0, y = 0, res = s[0][0]=='*';
	while (x != n-1 || y != m-1) {
		bool fnd = false;
		for (int d = 1; d < 7 && !fnd; d++) {
			for (int dx = 0; dx <= d; dx++) {
				int dy = d - dx;
				if (x+dx<n && y+dy<m && s[x+dx][y+dy]=='*') {
					fnd = true;
					x += dx;
					y += dy;
					res++;
					break;
				}
			}
		}
		if (!fnd) break;
	}
	cout << res << "\n";
	return 0;
}