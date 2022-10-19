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

const ll MAXN = 1e5 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int n , q , A[MAXN] , mark[MAXN] , nxt[LOG][MAXN] , last[MAXN];
vector<int> pr[MAXN];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	for(int i = 2 ; i < MAXN ; i++){
		if(mark[i])	continue;
		for(int j = i ; j < MAXN ; j += i){
			pr[j].push_back(i);
			mark[j] = 1;
		}
	}
	cin >> n >> q;
	for(int i = 0 ; i < n ; i++){
		cin >> A[i];
	}
	nxt[0][n] = n;
	fill(last , last + MAXN , n);
	for(int i = n - 1 ; i >= 0 ; i--){
		nxt[0][i] = nxt[0][i + 1];
		for(int j : pr[A[i]]){
			nxt[0][i] = min(nxt[0][i] , last[j]);
			last[j] = i;
		}
	}
	for(int i = 1 ; i < LOG ; i++){
		for(int j = 0 ; j <= n ; j++){
			nxt[i][j] = nxt[i - 1][nxt[i - 1][j]];
		}
	}
	while(q--){
		int l , r;
		cin >> l >> r; l--;
		int ans = 0;
		for(int i = LOG - 1 ; i >= 0 ; i--){
			if(nxt[i][l] < r){
				ans += (1 << i);
				l = nxt[i][l];
			}
		}
		cout << ans + 1 << endl;
	}

    return 0;
}
/*

*/