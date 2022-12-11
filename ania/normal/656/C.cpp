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

char s[111];

int main() {
	int res = 0;
	scanf("%s", s);
	for (int i = 0; s[i]; i++) {
		if ('a' <= s[i] && s[i] <= 'z') res -= s[i]-'a'+1;
		if ('A' <= s[i] && s[i] <= 'Z') res += s[i]-'A'+1;
	}
	printf("%d\n", res);
	return 0;
}