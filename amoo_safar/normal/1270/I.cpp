// Zende bad Shoma nasime faghat !
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
const int N = 1e3 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

int n, k, t;
ll A[N][N], ps[N][N];

int x[N], y[N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> k;
	n = 1 << k;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++) cin >> A[i][j];
	cin >> t;
	for(int i = 0; i < t; i++) cin >> x[i] >> y[i];
	for(int i = 1; i < t; i++) x[i] -= x[0];
	for(int i = 1; i < t; i++) y[i] -= y[0];
	x[0] = 0;
	y[0] = 0;
	for(int st = 1; st <= k; st++){
		memset(ps, 0, sizeof ps);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				for(int l = 0; l < t; l++){
					ps[i][j] ^= A[(i - x[l] + n) & (n - 1)][(j - y[l] + n) & (n - 1)];
				}
			}
		}
		memcpy(A, ps, sizeof ps);
		for(int l = 0; l < t; l++) x[l] = (x[l] << 1) & (n - 1);
		for(int l = 0; l < t; l++) y[l] = (y[l] << 1) & (n - 1);
		/*
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++)
				cerr << A[i][j] << ' ';
			cerr << '\n';
		}

		cerr << '\n';
		*/
	}
	int ans = 0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			ans += (A[i][j] ? 1 : 0);
	cout << ans << '\n';
	return 0;
}