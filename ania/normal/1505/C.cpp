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

int main() {
	string s;
	cin >> s;
	for (int i = 2; i < SZ(s); i++) {
		if (((s[i-1]-'A') + (s[i-2]-'A')) % 26 != (s[i]-'A')) {
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
	return 0;
}