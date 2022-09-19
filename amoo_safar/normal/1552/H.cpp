// Doooop !
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

const ll Mod = 998244353ll;
const int N = 2e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

typedef pair<int, int> pii;
typedef vector<pii> vp;

int Get(int a, int b){
	return (a + b - 2) * 2;
}
int Val(vp V){
	set<int> st;
	for(auto x : V)
		st.insert(Get(x.F, x.S));
	return st.size();
}

pii Rot(pii rc){ return pii(rc.S, rc.F); }

typedef vector<int> vi;
vi Int(pii rc, int d){
	if(d == -1) return {0};
	int mx = 1 + (rc.F - 1) / d;
	int mn = {rc.F < d ? 0 : rc.F / d };
	if(mn == mx) return {mn};
	return {mn, mx};
}

void Solve(vp V, int dep){
	if(Val(V) <= 1){
		assert(V.size() != 0);
		cout << "! " << Get(V[0].F, V[0].S) << endl;
		return ;
	}
	// debug(de

	int bst = 200*200;
	pii ask = {1,1};
	for(int i = -1; i <= 199; i++){
		if(i == 0) continue;
		if(i != 1 && dep == 0) continue;
		for(int j = -1; j <= 199; j++){
			if(j == 0) continue;
			if(j != 1 && dep == 0) continue;
			
			map<int, vp> mp;
			for(auto el : V){
				vi A = Int(el, i);
				vi B = Int(Rot(el), j);
				for(auto a : A) for(auto b : B){
					mp[a * el.S + b * el.F - a * b].pb(el);
				}
			}
			int res = 0;
			for(auto &el : mp) res = max(res, (int)el.S.size());
			if(res < bst){
				bst = res;
				ask = {i, j};
			}
		}
	}
	// debug(bst);
	// if(dep == 4){
	// 	for(auto rc : V) cerr << "!! " << rc.F << ' ' << rc.S << '\n';
	// }
	// assert(dep <= 3);
	int i = ask.F, j = ask.S;
	map<int, vp> mp;
	for(auto el : V){
		vi A = Int(el, i);
		vi B = Int(Rot(el), j);
		for(auto a : A) for(auto b : B){
			mp[a * el.S + b * el.F - a * b].pb(el);
		}
	}
	vector<pii> P;
	map<int, int> mkx, mky;
	if(i != -1)
		for(int ii = 1; ii <= 200; ii += i) mkx[ii] = 1;
	if(j != -1)
		for(int ii = 1; ii <= 200; ii += j) mky[ii] = 1;
	for(int ii = 1; ii <= 200; ii++)
		for(int jj = 1; jj <= 200; jj++)
			if(mkx[ii] || mky[jj])
				P.pb({ii, jj});
	cout << "? " << P.size();
	for(auto uu : P) cout << ' ' << uu.F << ' ' << uu.S;
	cout << endl;
	int qqq;
	cin >> qqq;
	Solve(mp[qqq], dep + 1);
	// int mx = 0;
	// for(auto el : mp) mx = max(mx, Solve(el.S, dep + 1));
	return ;
}


int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	vp A = {};
	for(int i = 2; i <= 200; i++)
		for(int j = 2; j <= 200; j++)
			A.pb({i, j});
	Solve(A, 0);
	// debug(x);
	return 0;
}