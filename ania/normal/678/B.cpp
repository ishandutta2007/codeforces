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

int f(int y) {
	return y%400 == 0 ? 2 : y%100 == 0 ? 1 : y%4 == 0 ? 2 : 1;
}

int main() {
	int n, r=0, t;
	scanf("%d", &n);
	t=f(n);
	while (r%7 != 0 || r==0 || t!=f(n)) {
		r += f(n);
		n++;
	}
	printf("%d\n", n);
	return 0;
}