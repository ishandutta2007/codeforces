#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m)-((m)>(n));i!=(n)-((m)>(n));i+=2*((m)<(n))-1)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair <int,int>


int main () {
	int n;
	cin >> n;
	int in[n], v[n];
	fop (i,0,n) cin >> in[i];
	fop (i,0,n) cin >> v[i];
	int minn = INT_MAX;
	fop (b,1,n-1) {
		int m1=INT_MAX, m2=INT_MAX;
		fop (a,0,b) {
			if (in[a] < in[b]) m1 = min(m1, v[a]);
		}
		fop (c,b+1,n) {
			if (in[b] < in[c]) m2 = min(m2, v[c]);
		}
		if (m1 != INT_MAX && m2 != INT_MAX)minn = min(minn, m1 + m2 + v[b]);
	}
	if (minn != INT_MAX) cout << minn << endl;
	else cout << -1 << endl;
}