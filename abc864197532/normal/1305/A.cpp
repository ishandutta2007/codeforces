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
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int A[n], B[n];
		fop (i,0,n) cin >> A[i];
		fop (i,0,n) cin >> B[i];
		sort(A, A + n);
		sort(B, B + n);
		fop (i,0,n) cout << A[i] << " \n"[i == n - 1];
		fop (i,0,n) cout << B[i] << " \n"[i == n - 1];
	}
}