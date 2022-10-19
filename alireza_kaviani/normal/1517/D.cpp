#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define all(x)						(x).begin(),(x).end()
#define X							first
#define Y							second
#define sep							' '
#define endl						'\n'
#define SZ(x)						ll(x.size())

const ll MAXN = 500 + 10;
const ll LOG = 12;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int n , m , k , A[MAXN][MAXN] , B[MAXN][MAXN] , dp[LOG][MAXN][MAXN];
int dx[4] = {1 , -1 , 0 , 0} , dy[4] = {0 , 0 , 1 , -1};

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n >> m >> k;
	if(k & 1){
		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < m ; j++){
				cout << -1 << sep;
			}
			cout << endl;
		}
		return 0;
	}
	k /= 2;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m - 1 ; j++){
			cin >> A[i][j];
		}
	}
	for(int i = 0 ; i < n - 1 ; i++){
		for(int j = 0 ; j < m ; j++){
			cin >> B[i][j];
		}
	}
	for(int i = 1 ; i <= k ; i++){
		for(int x = 0 ; x < n ; x++){
			for(int y = 0 ; y < m ; y++){
				dp[i][x][y] = MOD;
				for(int j = 0 ; j < 4 ; j++){
					int nx = x + dx[j] , ny = y + dy[j];
					if(nx < 0 || ny < 0 || nx >= n || ny >= m)	continue;
					int cost = MOD;
					if(j == 0)	cost = B[x][y];
					if(j == 1)	cost = B[nx][ny];
					if(j == 2)	cost = A[x][y];
					if(j == 3)	cost = A[nx][ny];
					dp[i][x][y] = min(dp[i][x][y] , dp[i - 1][nx][ny] + cost);
				}
			}
		}
	}
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			cout << dp[k][i][j] * 2 << sep;
		}
		cout << endl;
	}

    return 0;
}
/*

*/