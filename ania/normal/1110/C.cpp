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

int gen(int a) {
	int res = 0, p2 = 1;
	while (a) {
		res += (1-a%2) * p2;
		p2 *= 2;
		a /= 2;
	}
	return res;
}

void test() {
	int a;
	scanf("%d", &a);
	int b = gen(a);
	if (b == 0) {
		int dd = 1;
		for (int d = 2; d*d <= a; d++) if (a%d == 0) {
			dd = a/d;
			break;
		}
		printf("%d\n", dd);
	} else printf("%d\n", a^b);
	/*int res = 0;
	for (int b = 1; b < a; b++) res = max(res, __gcd(a^b, a&b));
	printf("%d %d\t", a, res);
	for (int b = 1; b < a; b++) if (__gcd(a^b, a&b) == res) printf("%d ", b);
	printf("\n");*/
}

int main() {
	int ttn;
	scanf("%d", &ttn);
	while (ttn--) test();
	return 0;
}