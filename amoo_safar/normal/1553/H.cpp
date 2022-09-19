// vaziat meshki-ghermeze !
#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ll Mod = 1000000007LL;
const int N = 2e6 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

typedef pair<int, pair<int, int>> dat;

vector<dat> X[N];

int ps[N];


bool Solve(int id, int L, int R, int bt){
	// debug(id);
	if(ps[R] == ps[L]) return false;
	if(bt == -1){
		X[id] = { {3000000, {L, L}} };
		return true;
	}
	int mid = (L + R) >> 1;
	bool lf = Solve(id << 1, L, mid, bt - 1);
	bool rt = Solve(id << 1 | 1, mid, R, bt - 1);
	X[id].resize(1 << (bt + 1));

	int gd = -1;
	if(!lf) gd = id << 1 | 1;
	if(!rt) gd = id << 1;
	if(gd != -1){
		int pw = 1 << bt, ad, ps;
		for(int i = 0; i < (int) X[id].size(); i++){
			ad = i & pw;
			ps = i - ad;
			vector<int> vl = {X[gd][ps].S.F, X[gd][ps].S.S};
			for(auto &x : vl) x ^= ad;
			sort(all(vl));
			X[id][i].F = X[gd][ps].F;
			X[id][i].S = {vl[0], vl[1]};
		}
		return true;
	}
	int pw = 1 << bt, ad, ps;
	for(int i = 0; i < (int) X[id].size(); i++){
		ad = i & pw;
		ps = i - ad;
		vector<int> vl = {X[id << 1][ps].S.F, X[id << 1][ps].S.S, X[id <<1|1][ps].S.F, X[id << 1|1][ps].S.S};
		for(auto &x : vl) x ^= ad;
		sort(all(vl));
		X[id][i].F = min(X[id << 1][ps].F, X[id << 1 | 1][ps].F);
		assert(vl[2] != vl[1]);

		X[id][i].F = min(X[id][i].F, vl[2] - vl[1]);
		X[id][i].S = {vl[0], vl[3]};
	}
	return true;
}


int main(){
	// ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, k;
	// cin >> k >> n;
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; i++){
		int v;
		scanf("%d", &v);
		ps[v + 1] ++;
	}
	for(int i = 1; i < N; i++) ps[i] += ps[i - 1];
	// debug(ps[0]);
	// debug(k);
	// debug(ps[1 << k]);
	Solve(1, 0, 1 << k, k - 1);
	for(auto el : X[1])
		printf("%d ", el.F);
	printf("\n");
	return 0;
}