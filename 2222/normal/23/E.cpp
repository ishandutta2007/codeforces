#include <algorithm>
#include <iostream>
#include <sstream>
#include <complex>
#include <numeric>
#include <cstring>
#include <vector>
#include <string>
#include <cstdio>
#include <queue>
#include <cmath>
#include <map>
#include <set>

using namespace std;

#define all(a)		(a).begin(),(a).end()
#define sz(a)		int((a).size())
#define FOR(i,a,b)	for(int i=a;i<b;++i)
#define REP(i,n)	FOR(i,0,n)
#define UN(v)		sort(all(v)),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)		memset(a,b,sizeof a)
#define pb			push_back
#define X			first
#define Y			second

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

int n;
vi a[777];

vi operator * (const vi &a, const vi &b) {
	vi c(sz(a) + sz(b));
	for (int i = 0; i < sz(a); ++i) {
		ll q = 0;
		for (int j = 0; j < sz(b); ++j) {
			q += c[i + j] + a[i] * ll(b[j]);
			c[i + j] = q % 1000000000;
			q /= 1000000000;
		}
		for (int j = i + sz(b); q && j < sz(c); ++j, q /= 1000000000) {
			q += c[j];
			c[j] = q % 1000000000;
		}
	}
	for (; sz(c) > 1 && c.back() == 0; c.pop_back());
	return c;
}

struct number {
	double x;
	vi v;
	number() : x(0), v(1, 1) { }
	vector <vi*> nv;
	void upd() {
		if (sz(nv)) {
			v = *nv[0];
			for (int i = 1; i < sz(nv); ++i)
				v = v * *nv[i];
			nv.clear();
		}
	}
};

number L[777];

vector <number> f(int x, int prev) {
	vector <number> F(1);
	for (vi :: iterator y = a[x].begin(); y != a[x].end(); ++y)
		if (*y != prev) {
			vector <number> G = f(*y, x), R(sz(F) + sz(G));
			for (int i = 0; i < sz(F); ++i)
				for (int j = 0; j < sz(G); ++j) {
					if (F[i].x + G[j].x + L[j].x > R[i].x) {
						R[i].x = F[i].x + G[j].x + L[j].x;
						R[i].nv.clear();
						R[i].nv.pb(&F[i].v);
						R[i].nv.pb(&G[j].v);
						R[i].nv.pb(&L[j].v);
					}
					if (F[i].x + G[j].x > R[i + j + 1].x) {
						R[i + j + 1].x = F[i].x + G[j].x;
						R[i + j + 1].nv.clear();
						R[i + j + 1].nv.pb(&F[i].v);
						R[i + j + 1].nv.pb(&G[j].v);
					}
				}
			for (int i = 0; i < R.size(); ++i)
				R[i].upd();
			F.swap(R);
		}
	return F;
}

void print(const vi &a) {
	cout << a.back();
	for (int i = sz(a) - 1; i > 0; printf("%09d", a[--i]));
}

int main(){
	#ifdef LocalHost
	freopen("x.in","r",stdin);
	freopen("x.out","w",stdout);
	#endif
	cin >> n;
	REP (i, n) {
		L[i].x = log(i + 1.);
		L[i].v = vi(1, i + 1);
	}
	REP (i, n - 1) {
		int x, y;
		cin >> x >> y;
		a[x - 1].pb(y - 1);
		a[y - 1].pb(x - 1);
	}
	vector <number> R = f(0, -1);
	number best;
	best.v = vi(1, 1);
	for (int i = 0; i < sz(R); ++i) {
		if (L[i].x + R[i].x > best.x) {
			best.x = L[i].x + R[i].x;
			best.nv.clear();
			best.nv.pb(&L[i].v);
			best.nv.pb(&R[i].v);
		}
	}
	best.upd();
	print(best.v);
	cout << endl;
	return 0;
}