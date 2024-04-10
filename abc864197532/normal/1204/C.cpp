#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i = (m); i < (n); ++i)
#define FOP(i,m,n) for (int i = (m) - 1; i >= (n); --i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int>
#define X first
#define Y second
#define MAXN 105
int martix[MAXN][MAXN], n;
int shortest[MAXN][MAXN];

int main () {
	cin >> n;
	char c;
	fop (i,0,n) {
		fop (j,0,n) {
			cin >> c;
			shortest[i][j] = 1 << 20;
			if (c == '1') {
				martix[i][j] = 1;
				shortest[i][j] = 1;
			}
			else martix[i][j] = 0; 
		}
	}
	fop (k,0,n) {
		fop (i,0,n) {
			fop (j,0,n) {
				if (shortest[i][j] > shortest[i][k] + shortest[k][j]) {
					shortest[i][j] = shortest[i][k] + shortest[k][j];
				}
			}
		}
	}
	int q;
	cin >> q;
	vector <int> ans, input(q);
	fop (i,0,q) cin >> input[i], input[i]--;
	int p = input[0], p1 = 0;
	ans.pb(input[0]);
	fop (i,1,q) {
		if (shortest[p][input[i]] < i - p1 or p == input[i]) {
			ans.pb(input[i-1]);
			p = input[i-1];
			p1 = i - 1;
		}
	}
	ans.pb(input[q-1]);
	cout << ans.size() << endl;
	for (int i : ans) cout << i + 1 << ' ';
	cout << endl;
}