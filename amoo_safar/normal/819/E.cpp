// har ki ro didi goft mikhad beshe meslemon !
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

vector< vector<int> > V;

void Solve(int n){
	if(n == 3){
		V.pb({1, 2, 3});
		V.pb({1, 2, 3});
		return ;
	}
	if(n == 4){
		V.pb({1, 2, 3});
		V.pb({1, 2, 4});
		V.pb({1, 3, 4});
		V.pb({2, 3, 4});
		return ;
	}
	Solve(n - 2);

	V.pb({1, n, n - 1});
	V.pb({2, n, n - 1});
	for(int i = 2; i <= n - 2; i++){
		int nx = (i == n - 2 ? 1 : i + 1);
		V.pb({i, n, nx, n - 1});
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	Solve(n);
	cout << V.size() << '\n';
	for(auto X : V){
		cout << X.size();
		for(auto y : X) cout << ' ' << y;
		cout << '\n';
	}
	return 0;
}