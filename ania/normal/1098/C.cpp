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

const int N = 100100;
int n;
ll s;
int deg[N];
int moves = 0;
vi v[N];

void output(int b) {
	printf("Yes\n");
	int id = 1;
	for (int i = 1; deg[i]; i++) {
		FOR(j,deg[i]) {
			v[i].pb(j+id);
			if (i>1) printf("%d ", v[i-1][j/b]);
		}
		id += deg[i];
	}
	printf("\n");
	/*printf("%d moves\n", moves);
	for (int i = 1; deg[i]; i++) printf("%d ", deg[i]);
	printf("\n");
	ll res=0;
	for (int i = 1; deg[i]; i++) res += deg[i]*i;
	printf("%lld\n", res);*/
	exit(0);
}

void build(int b) {
	//printf("b = %d\n", b);
	ll min_sum = 0;
	ll b_pow = 1, cur_n = 0, dep = 1;
	while (cur_n < n) {
		//printf("power = %lld, nodes = %lld, sum = %lld, depth = %lld\n", b_pow, cur_n, min_sum, dep);
		ll add = min(n-cur_n, b_pow);
		deg[dep] = add;
		cur_n += add;
		min_sum += add * dep;
		b_pow *= b;
		dep++;
	}
	//printf("%lld\n", min_sum);
	if (s == min_sum) {
		output(b);
	}
	FOR(i,dep+3) deg[i]=0;
	if (s < min_sum) {
		return;
	}
	if (b==1 && s>min_sum) {
		printf("No\n");
		exit(0);
	}
	ll sum = 0;
	b_pow = 1, cur_n = 0, dep = 1;
	while (cur_n < n) {
		//printf("power = %lld, nodes = %lld, sum = %lld, depth = %lld\n", b_pow, cur_n, min_sum, dep);
		ll add = min(n-cur_n, b_pow);
		deg[dep] = add;
		cur_n += add;
		sum += add * dep;
		b_pow *= b-1;
		dep++;
	}
	
	// decrease sum
	int lower = 2, upper = dep-1;
	while (sum > s) {
		//printf("lower = %d, upper = %d\n", lower, upper);
		ll can = 1LL * deg[lower-1] * b - deg[lower];
		can = min(can, 1LL * deg[upper]);
		int diff = upper - lower;
		if (s+diff > sum) {
			//printf("s=%lld, sum=%lld\n", s, sum);
			int pos = upper-(sum-s);
			//printf("s=%lld, sum=%lld, pos=%d, b=%d\n", s, sum, pos, b);
			while (1LL*deg[pos-1]*b == deg[pos]) pos++;
			deg[pos]++;
			deg[upper]--;
			sum -= upper-pos;
			if (deg[upper]==0) upper--;
			continue;
		}
		can = min(can, (sum-s) / diff);
		deg[lower] += can;
		deg[upper] -= can;
		if (deg[upper] == 0) upper--;
		if (1LL * deg[lower-1] * b == deg[lower]) lower++;
		sum -= can * diff;
		moves++;
	}
	//printf("lower = %d, upper = %d\n", lower, upper);
	//for (int i = 1; deg[i]; i++) printf("%d ", deg[i]);
	//printf("\n");
	//ll res=0;
	//for (int i = 1; deg[i]; i++) res += deg[i]*i;
	//printf("%lld %lld\n", res, sum);
	
	// increase sum
	int high = dep;
	int ini = lower;
	while (sum < s) {
		for (int i = ini; deg[i] > 0; i++) {
			ll add = min(s - sum, (1LL*deg[i]*b-deg[i+1]) / (b+1));
			moves++;
			//printf("moving %lld from %d to %d\n", add, i, i+1);
			deg[i] -= add;
			deg[i+1] += add;
			sum += add;
			if (sum == s) break;
			if (i == ini && add > 0) ini--;
		}
	}
	output(b);
}

int main() {
	cin >> n >> s;
	for (int b = 1; b < n; b++) build(b);
	printf("No\n");
	return 0;
}