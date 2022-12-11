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

const int M = 1<<20;

int t[2*M+17];

void put(int x) {
	x += M;
	while (x) {
		t[x]++;
		x /= 2;
	}
}

int get(int x, int y) {
	if (x>=y) return 0;
	x += M;
	y += M;
	int res = t[x];
	while (x+1 < y) {
		if (x%2==0) res += t[x+1];
		if (y%2==1) res += t[y-1];
		x /= 2;
		y /= 2;
	}
	return res;
}

int main() {
	int n,k;
	scanf("%d%d", &n, &k);
	if (2*k>n) k=n-k;
	long long seg=1;
	int p=0;
	FOR(i,n) {
		if (p+k <= n) {
			seg += get(p+1, p+k);
		} else {
			seg += get(p+1, n);
			seg += get(0, (p+k)%n);
		}
		seg++;
		put(p);
		p = (p+k)%n;
		put(p);
		cout << seg << " ";
	}
	cout << "\n";
	return 0;
}