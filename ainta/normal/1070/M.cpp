#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define Fi first
#define Se second
#define pb(x) push_back(x)
#define szz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define rep(i,n) for(int i=0;i<n;i++)
#define repp(i,n) for(int i=1;i<=n;i++)

pii operator-(pii a, pii b) { return pii(a.Fi - b.Fi, a.Se - b.Se); }
int operator/(pii a, pii b) { return a.Fi * b.Se - a.Se * b.Fi; }
int operator*(pii a, pii b) { return a.Fi * b.Fi + a.Se * b.Se; }
int N, M;
struct point {
	point() {}
	point(pii p, int cnt) : p(p), cnt(cnt) {}
	int cnt;
	pii p;
} P[6060];

int deg[3030];
vector <pii> ans;
void addE(int x, int y) {
	if(x > N) swap(x, y);
	ans.pb(pii(y - N, x));
}

void Do(vector <int> &pl) {
	if(szz(pl) <= 1) return;
//	puts("!!"); for(int e : pl) printf("%d ", e); puts("");
	int idx = 0, len = szz(pl);
	for(int i=1;i<len;i++) {
		if(P[pl[idx]].p > P[pl[i]].p) idx = i;
	}
	vector <int> w;
	for(int i=0;i<len;i++) if(i != idx) w.pb(pl[i]);
	pii o = P[pl[idx]].p;
	sort(all(w), [&o](int x, int y) {
		return (P[x].p-o) / (P[y].p-o) > 0;
	});

	if(P[pl[idx]].cnt >= 0) {
		// red point
		int now = -1, prev = 0;
		int exp = -P[pl[idx]].cnt - 1;
		for(int j=0, sum=0;j<szz(w);j++) {
			int cv = P[w[j]].cnt;
			sum += cv;
			if(sum == now) {
				vector <int> temp;
				addE(pl[idx], w[j]);
				for(int k=prev;k<=j;k++) {
					temp.pb(w[k]);
				}
				Do(temp);
				if(now == exp) {
					temp.clear();
					for(int k=j;k<szz(w);k++) {
						temp.pb(w[k]);
					}
					if(szz(temp) > 1) Do(temp);
					return;
				}
				--now;
				prev = j + 1;
			}
		}
	}
	else {
		int me = pl[idx];
		for(int j=0, sum=0;j<szz(w);j++) {
			sum += P[w[j]].cnt;
			if(P[w[j]].cnt >= 0 && sum >= 0) {
				addE(me, w[j]);
				vector <int> f1;
				for(int k=0;k<=j;k++) f1.pb(w[k]);
				int lv = P[w[j]].cnt - sum - 1;
				int rv = P[w[j]].cnt - lv - 2;
			//	printf("%d : %d %d\n", w[j], lv, rv);
				P[w[j]].cnt = lv;
				Do(f1);
				if(rv >= 0) {
					P[w[j]].cnt = rv;
					f1.clear();
					for(int k=j;k<szz(w);k++) f1.pb(w[k]);
					Do(f1);
				}
				else {
					f1.clear();
					for(int k=j+1;k<szz(w);k++) f1.pb(w[k]);
					f1.pb(me);
					Do(f1);
				}
				return;
			}
		}
	}
}

void solve() {
	ans.clear();
	scanf("%d%d", &N, &M);
	for(int i=1;i<=M;i++) {
		scanf("%d", deg + i);
	}
	vector <point> pv;
	for(int i=1;i<=N;i++) {
		int x, y; scanf("%d%d", &x, &y);
		P[i] = point(pii(x, y), -1);
	}
	for(int i=1;i<=M;i++) {
		int x, y; scanf("%d%d", &x, &y);
		P[N + i] = point(pii(x, y), deg[i] - 1);
	}
	vector <int> w;
	for(int i=1;i<=N+M;i++) w.pb(i);
	Do(w);
	puts("YES");
	for(pii e : ans) printf("%d %d\n", e.Fi, e.Se);
}

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		solve();
	}
}