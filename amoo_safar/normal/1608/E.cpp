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
typedef pair<int, int> pii;

const int Mod = 1000000007LL;
const int N = 2e5 + 10;
const int Log = 30;
const int Inf = 1000000010;

int x[N], y[N], c[N];
vector<int> V, X, Y;
int mk[N];
int n;
	
bool Check(int K){
	fill(mk, mk + N, 0);
	int rm = K, rq = V[0];
	int la = -Inf;
	for(int ii = 0; ii < n; ii++){
		int i = X[ii];
		mk[i] = 1;
		if(c[i] != rq) continue;
		rm --;
		if(rm == 0){
			la = x[i];
			break;
		}
	}
	if(rm) return false;
	// X - X;

	bool fail = false;
	rq = V[1]; rm = K;
	int la2;

	for(int ii = 0; ii < n; ii++){
		int i = X[ii];
		if(x[i] <= la) continue;
		if(c[i] != rq) continue;
		rm --;
		if(rm == 0){
			la2 = x[i];
			break;
		}
	}
	if(rm) fail = true;
	rq = V[2]; rm = K;
	for(int ii = 0; ii < n; ii++){
		int i = X[ii];
		if(x[i] <= la2) continue;
		if(c[i] != rq) continue;
		rm --;
		if(rm == 0){
			la2 = x[i];
			break;
		}
	}
	if(rm) fail = true;
	if(!fail) return true;
	
	// Y Y
	fail = false;
	rq = V[1]; rm = K;
	for(int ii = 0; ii < n; ii++){
		int i = Y[ii];
		if(x[i] <= la) continue;
		if(c[i] != rq) continue;
		rm --;
		if(rm == 0){
			la2 = y[i];
			break;
		}
	}
	if(rm) fail = true;
	rq = V[2]; rm = K;
	for(int ii = 0; ii < n; ii++){
		int i = Y[ii];
		if(x[i] <= la || y[i] <= la2) continue;
		if(c[i] != rq) continue;
		rm --;
		if(rm == 0)
			break;
	}
	if(rm) fail = true;
	if(!fail) return true;
	return false;
}
int Solve(){
	int res = 0;
	V = {1, 2, 3};
	do {
		int L = 0, R = (n / 3) + 1, mid;
		while(L + 1 < R){
			mid = (L + R) >> 1;
			if(Check(mid)) L = mid;
			else R = mid;
		}
		res = max(res, L);
	} while(next_permutation(all(V)));
	return res;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> x[i] >> y[i] >> c[i];
	}
	int ans = 1;
	X.resize(n); iota(all(X), 1);
	Y.resize(n); iota(all(Y), 1);
	for(int _ = 0; _ < 4; _++){
		sort(all(X), [&](int i, int j){ return x[i] < x[j]; });
		sort(all(Y), [&](int i, int j){ return y[i] < y[j]; });
		ans = max(ans, Solve());
		for(int i = 1; i <= n; i++){
			int tmp = x[i];
			x[i] = y[i];
			y[i] = -tmp;
		}
	}
	cout << ans * 3 << '\n';
	return 0;
}