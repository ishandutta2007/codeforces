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

char s[100100];

long long get(int k) {
	return 1LL*k*(k-1)/2;
}

int main () {
	int n,m;
	scanf("%d%d%s", &n, &m, s);
	long long res = 1;
	FOR(i,n-1) if (s[i]!=s[i+1]) res++;
	res *= n*(m-1);
	s[n]='.';
	s[n+1] = '.';
	int last = 0;
	FOR(i,n-1) {
		if (s[i] == s[i+2]) {
		} else {
			if (s[i]!=s[i+1]) res -= get(i-last+2);
			last = i+1;
		}
	}
	cout << res << endl;
	return 0;
}