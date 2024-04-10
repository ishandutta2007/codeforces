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
const int N = 3e3 + 10;
const int Log = 30;
const ll Inf = 2242545357980376863LL;

int A[N][N];

int Main(){
	int n;
	cin >> n;
	ll ans = 0;
	for(int i = 0; i < n + n; i++){
		for(int j = 0; j < n + n; j++){
			cin >> A[i][j];
			if(i >= n && j >= n) ans += A[i][j];
		}
	}
	int mn = A[n][0];
	int x = 0, y = n;
	mn = min({mn, A[x][y], A[x][y + n - 1], A[x + n - 1][y], A[x + n - 1][y + n - 1]});
	x = n, y = 0;
	mn = min({mn, A[x][y], A[x][y + n - 1], A[x + n - 1][y], A[x + n - 1][y + n - 1]});
	cout << ans + mn << '\n';
	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc;
	cin >> tc;
	while(tc --) Main();
	return 0;
}