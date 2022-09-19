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
const int N = 2e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

int A[N],B[N];

vector<int> V[2];

int fnd[500'000 * 13];
int n;
int m = 0;

vector<int> Get(int mk){
	vector<int> res;
	for(int i = 0; i < m; i++) if(mk >> i & 1) res.pb(A[i]);
	return res;
}

void Solve(int mk1, int mk2){
	int an = mk1&mk2;
	mk1 ^= an;
	mk2 ^= an;
	auto g1 = Get(mk1);
	auto g2 = Get(mk2);
	// debug(mk1);
	// debug(mk2);
	vector<int> ans = {0};
	int nw = 0;
	for(int i = 0; i < (int) g1.size(); i++){
		nw = g1[i] - nw;
		ans.pb(nw);
		// debug(nw);
		nw = g2[i] - nw;
		// debug(nw);
		if(i + 1 != (int)g1.size())
			ans.pb(nw);
	}
	for(int i = 0; i < n; i++){
		if((i >= m)) ans.pb(A[i]);
		else {
			if(mk1 >> i & 1) continue;
			if(mk2 >> i & 1) continue;
			ans.pb(A[i]);
		}
	}
	cout << "YES\n";
	for(int i = 0; i < n; i++){
		cout <<ans[i] << ' ';
	}
	cout << '\n';
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> A[i];
		V[A[i] & 1].pb(i);
	}

	if(n == 2){
		if(A[0] != A[1]) return cout << "NO\n", 0;
		cout << "YES\n0 " << A[0] << '\n';
		return 0;
	}
	vector<int> C3;
	if((int) V[0].size() >= 3){
		C3 = {V[0][0], V[0][1], V[0][2]};
	} 
	if((int) V[0].size() >= 1 && (int)V[1].size() >= 2){
		C3 = {V[0][0], V[1][0], V[1][1]};
	}
	vector<int> ans;
	if((int)C3.size() == 3){
		int x = A[C3[0]] + A[C3[2]] - A[C3[1]];
		x /= 2;
		ans = {x};
		ans.pb(A[C3[0]] - x);
		ans.pb(A[C3[1]] - (A[C3[0]] - x));
		// cerr << "!! " <<
		for(int i = 0; i < n; i++){
			int fl = 0;
			for(auto c : C3) fl |= (c == i);
			// cerr << "!! " << fl << '\n';
			if(!fl)
				ans.pb(A[i] - x);
		}
		cout << "YES\n";
		for(auto x:ans) cout << x << ' ';
		cout << '\n';
		return 0;
	}
	if(n == 3){
		sort(A, A + 3);
		if(A[0] != A[1] && A[1] != A[2]) return cout << "NO\n", 0;
		cout << "YES\n";
		cout << "0 " << A[0] << ' ' << A[2] << '\n';
		// cout << "0 " << A[0] << ' ' << A[2] << '\n';
		return 0;
	}
	for(int i = 0; i < N; i++) B[i] = A[i] / 2;

	if(true){
		m = min(n, 26);
		int rq = m / 2;
		for(int i = 0; i < (1 << m); i++){
			if(__builtin_popcount(i) != rq) continue;
			int sm = 0;
			for(int j = 0; j < m; j++){
				if(i >> j & 1) sm += B[j];
			}
			if(fnd[sm]){
				// debug(sm);
				Solve(i, fnd[sm]);
				return 0;
			}
			fnd[sm] = i;
		}
	}
	cout << "NO\n";
	return 0;
}