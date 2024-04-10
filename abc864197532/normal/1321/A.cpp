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
#define X first
#define Y second

int main () {
	int n;
	cin >> n;
	int a[n], b[n], c = 0, d = 0;
	fop (i,0,n) cin >> a[i];
	fop (i,0,n) cin >> b[i];
	fop (i,0,n) {
		if (a[i] and !b[i]) c++;
		if (!a[i] and b[i]) d++;
	}
	if (c == 0) cout << -1 << endl;
	else cout << d / c + 1 << endl;
}