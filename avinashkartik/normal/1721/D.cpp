#include<bits/stdc++.h>

using namespace std;

#define  GODSPEED       ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(15);
#define  f              first
#define  s              second
#define  newl           cout<<"\n";
#define  pb             push_back
#define  mset(a,x)      memset(a,x,sizeof(a))
#define  debv(a)        for(auto it: a)cout<<it<<" ";newl;
#define  deb1(a)        cout<<a<<"\n";
#define  deb2(a,b)      cout<<a<<" "<<b<<"\n";
#define  deb3(a,b,c)    cout<<a<<" "<<b<<" "<<c<<"\n";
#define  deb4(a,b,c,d)  cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n";
#define  uniq(a)        a.resize(unique(a.begin(), a.end()) - a.begin());
#define  all(a)         a.begin(),a.end()

typedef  long long             ll;
typedef  long double           ld;

const ll   N     =  3e5 + 5;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

int n, a[N], b[N];

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	vector <int> ai(n), bi(n), mark(31, 1);
	iota(all(ai), 1);
	iota(all(bi), 1);
	vector <vector <int>> A[31];
	vector <vector <int>> B[31];
	A[30].pb(ai);
	B[30].pb(bi);
	for (int i = 29; i >= 0; i--) {
		if (i == -1) return;
		for (int j = 0; j < A[i + 1].size(); j++) {
			vector <int> ai0, ai1, bi0, bi1;
			for (int k = 0; k < A[i + 1][j].size(); k++) {
				if ((a[A[i + 1][j][k]] >> i)&1) ai1.pb(A[i + 1][j][k]);
				else ai0.pb(A[i + 1][j][k]);
				if ((b[B[i + 1][j][k]] >> i)&1) bi1.pb(B[i + 1][j][k]);
				else bi0.pb(B[i + 1][j][k]);
			}
			if (ai0.size() == bi1.size()) {
				if (ai0.size()) A[i].pb(ai0);
				if (ai1.size()) A[i].pb(ai1);
				if (bi1.size()) B[i].pb(bi1);
				if (bi0.size()) B[i].pb(bi0);
			} else {
				mark[i] = 0;
				A[i].clear();
				B[i].clear();
				for (int j = 0; j < A[i + 1].size(); j++) {
					A[i].pb(A[i + 1][j]);
					B[i].pb(B[i + 1][j]);
				}
				break;
			}
		}
		A[i + 1].clear();
		B[i + 1].clear();
	}
	int ans = 0;
	for (int i = 0; i < 30; i++) ans += mark[i] * (1 << i);
	deb1(ans)
}

int main() {
	GODSPEED;
	int test = 1;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}