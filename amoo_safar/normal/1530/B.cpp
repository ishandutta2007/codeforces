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

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t --){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> A(n, vector<int>(m, 0));
		A[0][0] = A[0][m - 1] = A[n - 1][0] = A[n - 1][m - 1] = 1;
		for(int i = 2; i <= m - 3; i += 2)
			A[0][i] = A[n - 1][i] = 1;
		for(int i = 2; i <= n - 3; i += 2)
			A[i][0] = A[i][m - 1] = 1;
		for(auto x : A){
			for(auto y : x) cout << y;
			cout << '\n';
		}
	}
	return 0;
}