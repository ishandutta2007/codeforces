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
const int N = 5e2 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

int r[N][N], d[N][N];
ll dp[N][N], tmp[N][N];
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	if(k % 2 != 0){
		for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cout << "-1" << " \n"[j == m - 1];
		return 0;
	}
	k /= 2;
	for(int i = 0; i < n; i++)
		for(int j = 0; j + 1 < m; j++)
			cin >> r[i][j];

	for(int i = 0; i + 1 < n; i++)
		for(int j = 0; j < m; j++)
			cin >> d[i][j];

	for(int it = 0; it < k; it ++){
		memset(tmp, 31, sizeof tmp);
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++){
				if(i > 0)
					tmp[i - 1][j] = min(tmp[i - 1][j], dp[i][j] + d[i - 1][j]);
				if(j > 0)
					tmp[i][j - 1] = min(tmp[i][j - 1], dp[i][j] + r[i][j - 1]);
				
				if(i + 1 < n)
					tmp[i + 1][j] = min(tmp[i + 1][j], dp[i][j] + d[i][j]);
				if(j + 1 < m)
					tmp[i][j + 1] = min(tmp[i][j + 1], dp[i][j] + r[i][j]);
			}
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++) dp[i][j] = tmp[i][j];
	}
	for(int i = 0; i < n; i++)
		for(int j =0 ; j < m; j++)
			cout << 2ll * dp[i][j] << " \n"[j == m - 1];

	return 0;
}