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

int sti(string s) {
	int c=0;
	FOR(i,SZ(s)) {
		if (s[i]=='+' || s[i]=='-') return c;
		c = c*10+(s[i]-'0');
	}
	return c;
}

char ss[5];

int main() {
	string s;
	int r=0;
	cin >> s;
	if (s[0]!='-') s = "+"+s;
	FOR(i,SZ(s)) {
		if (s[i]=='+') {
			int cur = sti(s.substr(i+1));
			r += cur;
		} else if (s[i] == '-') {
			int cur = sti(s.substr(i+1));
			r -= cur;
		}
	}
	sprintf(ss, "%d", r);
	int v=0;
	for (int i=0; ss[i]; i++) {
		for (; v<ss[i]; v++) printf("+");
		for (; v>ss[i]; v--) printf("-");
		printf(".");
	}
	printf("\n");
	return 0;
}