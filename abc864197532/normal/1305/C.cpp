#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int>
#define pli pair<lli,int> 
#define X first
#define Y second

int main () {
	lli n, m, ans = 1;
	cin >> n >> m;
	vector <int> input(n);
	fop (i,0,n) cin >> input[i];
	if (n > 1000) {
		cout << 0 << endl;
	} else {
		fop (i,0,n) {
			fop (j,i+1,n) {
				ans = ans * abs(input[i] - input[j]) % m;
			}
		}
		cout << ans << endl;
	}
}