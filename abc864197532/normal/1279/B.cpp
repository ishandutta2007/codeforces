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

int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n,s;
		cin >> n >> s;
		int a[n];
		fop (i,0,n) cin >> a[i];
		lli summ[n];
		int maxx[n], order[n];
		summ[0] = a[0];
		maxx[0] = a[0];
		order[0] = 0;
		fop (i,1,n) summ[i] = summ[i-1] + a[i];
		fop (i,1,n) {
			if (maxx[i-1] < a[i]) {
				maxx[i] = a[i];
				order[i] = i;
			} else {
				order[i] = order[i-1];
				maxx[i] = maxx[i-1];
			}
		}
		bool is = true;
		fop (i,0,n) {
			if (summ[i] - maxx[i] > s) {
				cout << order[i-1] + 1 << endl;
				is = false;
				break;
			}
		}
		if (is) {
			if (summ[n-1] > s) {
				cout << order[n-1] + 1 << endl;
			} else {
				cout << 0 << endl;
			}
		}
	}
}