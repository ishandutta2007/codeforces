#include <bits/stdc++.h>
// #undef BALBIT
using namespace std;
 
#define ll long long
#define pii pair<int, int>
#define f first
#define s second
 
#define REP(i,n) for (int i = 0; i<n; ++i)
#define REP1(i,n) for (int i = 1; i<=n; ++i)
 
#define MX(a,b) a = max(a,b)
#define MN(a,b) a = min(a,b)
#define pb push_back
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(), (x).end()
 
#ifdef BALBIT
#define bug(...) cerr<<"#"<<__LINE__<<": "<<#__VA_ARGS__<<"- ", _do(__VA_ARGS__)
template<typename T> void _do(T && x) {cerr<<x<<endl;}
template<typename T, typename ...S> void _do(T && x, S && ...y) {cerr<<x<<", "; _do(y...);}
#else
#define bug(...)
#endif // BALBIT

#ifdef BALBIT
vector<int> S;
#endif

int get(int a, int b, int c) {
#ifdef BALBIT
vector<int> ha = {abs(S[a] - S[b]), abs(S[b] - S[c]), abs(S[c] - S[a])};
sort(ALL(ha));
// bug(a,b,c,ha[1]);
return ha[1];
#else
cout<<"? "<<a+1<<' '<<b+1<<' '<<c+1<<endl<<flush;
int t; cin>>t;
return t;
#endif
}


void solve(){
	mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

	int n; cin>>n;
	#ifdef BALBIT
	S.clear();
	REP(i,n) S.pb(i+1);
	shuffle(ALL(S), rnd);
	for (int e : S) cout<<e<<' ';
	cout<<endl<<flush;
	#endif
	int womp = 300;
	int best = n * 2;
	vector<int> yay;
	while (womp) {
		int a = rnd() % n, b = rnd()%n, c = rnd()%n;
		if (a == b || b == c || a == c) {
			continue;
		}
		--womp;
		int gt = get(a,b,c);
		if (gt < best) {
			best = gt;
			yay = {a,b,c};
		}
	}
	int a = yay[0], b = yay[1];
	bug(a,b);
	vector<pii> uh;
	REP(i, n) {
		if (i != a && i != b) {
			int h = get(a,b,i);
			uh.pb({h, i});
		}
	}
	sort(ALL(uh));
	int fardst = uh.back().f;
	int far = uh.back().s;
	vector<int> maybe2;
	for (pii p : uh) {
		if (p.f == fardst-1) {
			maybe2.pb(p.s);
		}
	}
	assert(SZ(maybe2) >= 1 && SZ(maybe2) <= 2);

	int two;
	if (SZ(maybe2) == 1) two = maybe2[0];
	else {
		int g0 = get(a,far,maybe2[0]) + get(b,far,maybe2[0]);
		int g1 = get(a,far,maybe2[1]) + get(b,far,maybe2[1]);
		if (g0 < g1) two = maybe2[0];
		else two = maybe2[1];
	}

	bug(far, two);

	vector<int> per(n);
	per[0] = far, per[1] = two;
	REP(i, n) {
		if (i != far && i != two) {
			int ga = get(far,two,i);
			per[ga+1] = i;
		}
	}

	// REP(i,n) bug(i, per[i]);

	vector<int> P(n);
	REP(i,n) P[per[i]] = i;

	if (P[0] > P[1]) {
		for (int &e : P) e = n-1-e;
	}

	cout<<"! ";
	for (int e : P) cout<<e+1<<' ';
	cout<<endl<<flush;

	int confirm; cin>>confirm;
	assert(confirm == 1);
}

signed main(){
	// ios::sync_with_stdio(0), cin.tie(0);

	int T; cin>>T;
	while (T--) {
		solve();
	}

}