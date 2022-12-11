#include<bits/stdc++.h>

using namespace std;

#define REP(i,a,b) for(int i = (a); i <= (b); ++i)
#define FORI(i,n) REP(i,1,n)
#define FOR(i,n) REP(i,0,int(n)-1)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define ll long long
#define SZ(x) ((int)((x).size()))
#define IN(x,y) ((y).find((x)) != (y).end())
#define DBG(v) cerr<<#v<<" = "<<(v)<<endl;
#define FOREACH(i,t) for (typeof(t.begin()) i = t.begin(); i != t.end(); ++i)
#define fi first
#define se second

int n, res;
int t[200200];
bool ok[200200];

vi rmv(vi v, int a, int b) {
	vi R;
	FOR(i,SZ(v)) if (v[i] != a && v[i] != b) R.pb(v[i]);
	return R;
}

bool chk(int a, int b) {
	if (a < 0 || b < 0 || a >= n || b >= n) return true;
	if (a&1) return t[a] > t[b];
	return t[a] < t[b];
}

void try_swap(int a, int b) {
	if (a < 0 || b < 0 || a >= n || b >= n) return;
	swap(t[a], t[b]);
	bool R = true;
	for (int i = -2; i <= 2; i++) {
		R &= chk(a+i, a+i+1);
		R &= chk(b+i, b+i+1);
	}
	if (R) {
		//printf("swap %d(%d) %d(%d) ok\n", a, t[b], b, t[a]);
		res++;
	}
	swap(t[a], t[b]);
}

int main() {
	scanf("%d", &n);
	FOR(i,n) scanf("%d", &t[i]);
	vi bad;
	FOR(i,n-1) {
		if (i&1) ok[i] = t[i] > t[i+1];
		else ok[i] = t[i] < t[i+1];
		if (!ok[i]) bad.push_back(i);
	}
	if (bad.size() > 4) {
		printf("0\n");
		return 0;
	}
	//FOR(i,n-1) printf("%d ", ok[i]); printf("\n");
	FOR(i,n) {
		vi v = rmv(bad, i-1, i);
		if (v.size() > 2) continue;
		if (v.size() == 2 && v[0]+1 != v[1]) continue;
		if (v.size() == 2) {
			try_swap(i,v[1]); 
		} else if (v.size() == 1) {
			try_swap(i, v[0]);
			try_swap(i, v[0]+1);
		} else {
			FOR(j, n) if (j != i) try_swap(i,j);
		}
	}
	printf("%d\n", res/2);
	return 0;
}