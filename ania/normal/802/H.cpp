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

int q;
char s[1234];

int main() {
	int n;
	scanf("%d", &n);
	REP(a,0,197) REP(b,0,197-a) REP(c,0,197-a-b) REP(d,0,197-a-b-c) {
		int val = a*b*c*d + a*b*c + a*b + a;
		if (val > n) continue;
		int x = n-val;
		if (a+b+c+d+x+3 <= 200) {
			FOR(i,a) s[q++] = 'a';
			FOR(i,b) s[q++] = 'b';
			FOR(i,c) s[q++] = 'c';
			FOR(i,d) s[q++] = 'd';
			FOR(i,x) s[q++] = 'a';
			s[q++] = 'b';
			s[q++] = 'c';
			s[q++] = 'd';
			printf("%s abcd\n", s);
			return 0;
		}
	}
	return 0;
}