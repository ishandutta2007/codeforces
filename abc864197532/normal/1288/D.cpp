#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i = (m); i < (n); ++i)
#define FOP(i,m,n) for (int i = (m) - 1; i >= (n); --i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<lli,int>
#define X first
#define Y second
#define MAXN 300000
int input[MAXN][8], n, m, ans1, ans2;

bool serach(int x) {
	int is[1 << m];
	fop (i,0,1<<m) is[i] = -1;
	fop (i,0,n) {
		int now = 0;
		fop (j,0,m) {
			if (input[i][j] >= x) now |= (1 << j);
		}
		is[now] = i;
	}
	fop (i,0,1<<m) {
		fop (j,0,1<<m) {
			if (is[i] == -1 or is[j] == -1) continue;
			if ((i | j) == (1 << m) - 1) { 
				ans1 = is[i];
				ans2 = is[j];
				return true;
			}
		}
	}
	return false;
}




int main () {
	cin >> n >> m;
	fop (i,0,n) {
		fop (j,0,m) {
			cin >> input[i][j];
		}
	}
	int x = 0;
	FOP (i,30,0) {
		if (serach(x + (1 << i))) x += (1 << i);
	}
	cout << ans1 + 1 << ' ' << ans2 + 1 << endl;
}