#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m)-((m)>(n));i!=(n)-((m)>(n));i+=2*((m)<(n))-1)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair <int,int>
int dij[26];

int find (int n) {
	if (dij[n] == n) return n;
	return dij[n] = find(dij[n]);
}


int main () {
	int t;
	cin >> t;
	int ans = 0;
	bool is[26];
	fop (i,0,26) {
		dij[i] = i;
		is[i] = false;
	}
	while (t--) {
		string s;
		cin >> s;
		fop (i,0,s.length()) is[s[i] - 'a'] = true;
		fop (i,1,s.length()) {
			int a = find(s[i] - 'a'), b = find(s[i-1] - 'a');
			if (a == b) continue;
			dij[a] = b;
		}
	}
	fop (i,0,26) {
		if (is[i] and find(i) == i) ans++;
	}
	cout << ans << endl; 
}