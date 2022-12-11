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

const int N = 1000100;

int n;
char s[N];
int le[N], ri[N];

int main() {
	scanf("%s", s+1);
	for (n = 1; s[n]; n++) ;
	for (int i = 2; i <= n; i++) {
		if (s[i] == 'v' && s[i-1] == 'v') {
			le[i] = le[i-1] + 1;
		} else {
			le[i] = le[i-1];
		}
	}
	for (int i = n-1; i >= 0; i--) {
		if (s[i] == 'v' && s[i+1] == 'v') {
			ri[i] = ri[i+1] + 1;
		} else {
			ri[i] = ri[i+1];
		}
	}
	ll res = 0;
	for (int i = 2; i < n; i++) if (s[i] == 'o') res += 1LL * le[i-1] * ri[i+1];
	cout << res << "\n";
	return 0;
}