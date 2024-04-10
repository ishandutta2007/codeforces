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

ll les(int s, int d, int p) {
	ll res = 1;
	FOR(i,s) res *= d+1;
	if (s >= p/4+1) {
		res /= d+1;
		int c=0;
		FOR(x,d+1) if ((1<<(p%4)) & x) c++;
		res *= c;
	}
	return res;
}

ll cnt(string s, int d, int p) {
	if (d<0) return 0;
	if (SZ(s)==0) return 1;
	int c = s[0]<='9' && s[0]>='0' ? s[0]-'0' : s[0]-'a'+10;
	//cout << "digit = " << c << "\n";
	ll res=0;
	for (int x=0; x<=d && x<=c; x++) {
		if (p/4+1 == SZ(s)) {
			if (((1<<(p%4)) & x) == 0) continue;
		}
		if (x==c) res += cnt(s.substr(1), d, p);
		else res += les(SZ(s)-1, d, p);
		//cout << "new digit = " << x << ", res = " << res << "\n";
	}
	return res;
}

ll get(string s) {
	ll res = 0;
	FOR(d,16) {
		if (d/4+1 > SZ(s)) continue;
		res += cnt(s, d, d) - cnt(s, d-1, d);
		//cout << "get " << d << " = " << res << "\n";
	}
	return res;
}

char tx[22], ty[22];
void test() {
	scanf("%s%s", tx, ty);
	int n=0;
	for (; tx[n]; n++) ;
	while (n>=1 && tx[n-1]=='0') {
		tx[n-1]='f';
		n--;
	}
	if (n>=1) tx[n-1]--;
	cout << get(ty) - get(tx) << "\n";
}

int main() {
	int q;
	scanf("%d", &q);
	while (q--) test();
	return 0;
}