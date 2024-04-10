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

const int N = 200200;
const int M = 1<<18;

int tot;
int T[2*M+13], S[2*M+13];
pair<pii,int> t[N];
vi ids[N];
int pos[N];

void add(int id) {
	//printf("adding %d (%d)\n", id, t[id].fi.fi);
	int cur = id+M;
	while (cur >= 1) {
		S[cur]++;
		T[cur]+= t[id].fi.fi;
		cur /= 2;
	}
}

bool ok(int k) {
	int sum = 0, fnd = 0, cur = 1;
	if (S[1] < k) return false;
	while (cur < M) {
		if (fnd + S[cur*2] <= k) {
			fnd += S[cur*2];
			sum += T[cur*2];
			cur = cur*2+1;
		} else {
			cur = cur*2;
		}
	}
	//printf("k=%d, sum=%d, fnd=%d\n", k, sum, fnd);
	return sum <= tot;
}

int main() {
	int n;
	scanf("%d%d", &n, &tot);
	FOR(i,n) {
		scanf("%d%d", &t[i].fi.se, &t[i].fi.fi);
		t[i].se = i+1;
		ids[t[i].fi.se].pb(i);
	}
	sort(t,t+n);
	FOR(i,n) {
		pos[t[i].se-1] = i;
	}
	for (int k = n; k >= 1; k--) {
		FOR(i,SZ(ids[k])) {
			add(pos[ids[k][i]]);
		}
		if (ok(k)) {
			printf("%d\n%d\n", k, k);
			FOR(j,n) if (S[M+j]) {
				printf("%d ", t[j].se);
				k--;
				if (k==0) break;
			}
			printf("\n");
			return 0;
		}
	}
	printf("0\n0\n\n");
	return 0;
}