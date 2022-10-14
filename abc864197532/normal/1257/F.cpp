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
	int in[n];
	fop (i,0,n) cin >> in[i];
	map <string, int> m1;
	fop (i,0,1<<15) {
		string s="";
		int tmp[n], minn = INT_MAX;
		fop (j,0,n) {
			tmp[j] = __builtin_popcount((in[j] & ((1 << 15) - 1)) ^ i);
			minn = min(minn, tmp[j]);
		}
		fop (j,0,n) s += ('a' + tmp[j] - minn);
		if (!m1.count(s)) m1[s] = i;
	}
	fop (i,0,1<<15) {
		string s="";
		int tmp[n], maxx = 0;
		fop (j,0,n) {
			tmp[j] = __builtin_popcount((in[j] >> 15) ^ i);
			maxx = max(maxx, tmp[j]);
		}
		fop (j,0,n) s += ('a' + maxx - tmp[j]);
		if (m1.count(s)) {
			cout << ((i << 15) | m1[s]) << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
	
}