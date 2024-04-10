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
const int N = 4e3 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;


int ps[N][N];
int A[N][N];
int X[N], Y[N], mn[N];
int Main(){
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		str s;
		cin >> s;
		for(int j =0 ; j < m; j++)
			A[i][j] = s[j] - '0';
		for(int j = 1; j <= m; j++){
			ps[i][j] = ps[i][j - 1] + A[i][j - 1];
		}
	}
	int ans = n * m;
	for(int j1 = 0; j1 < m; j1 ++){
		for(int j2 = j1 + 4; j2 <= m; j2++){
			for(int i = 0; i < n; i++)
				X[i] = (ps[i][j2 - 1] - ps[i][j1 + 1]) + (2 - A[i][j1] - A[i][j2 - 1]);
			for(int i = 1; i < n; i++)
				X[i] += X[i - 1];
			for(int i = 0; i < n; i++)
				Y[i] = (j2 - j1 - 2) - (ps[i][j2 - 1] - ps[i][j1 + 1]);
			mn[0] = n * m * 2;
			for(int i = 1; i <= n; i++)
				mn[i] = -X[i - 1] + Y[i - 1];
			for(int i = 1; i <= n; i++)
				mn[i] = min(mn[i], mn[i - 1]);
			for(int i = 4; i < n; i++){
				ans = min(ans, Y[i] + X[i - 1] + mn[i - 3]);
			}
		}
	}
	cout << ans << '\n';
	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc;
	cin >> tc;
	while(tc --) Main();

	return 0;
}