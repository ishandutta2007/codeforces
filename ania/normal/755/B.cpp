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

char tmp[12345];
string s[12345], t[12345];

int main() {
	int n,m;
	scanf("%d%d", &n, &m);
	FOR(i,n) {
		scanf("%s", tmp);
		s[i]=tmp;
	}
	FOR(i,m) {
		scanf("%s", tmp);
		t[i]=tmp;
	}
	sort(s,s+n);
	sort(t,t+m);
	int j=0, cnt=0;
	FOR(i,n) {
		while (j<m && t[j]<s[i]) j++;
		if (s[i]==t[j]) {
			cnt++;
			j++;
		}
	}
	n -= cnt;
	m -= cnt;
	if (cnt%2==1) m--;
	printf("%s\n", n>m ? "YES" : "NO");
	return 0;
}