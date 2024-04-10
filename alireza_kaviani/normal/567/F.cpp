#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define all(x)      (x).begin(),(x).end()
#define X           first
#define Y           second
#define sep         ' '
#define endl        '\n'
#define SZ(x)       ll(x.size())

const ll MAXN = 80;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

ll n , k , A[MAXN] , dp[MAXN][MAXN];
vector<pair<pii, string>> vec;

int check(int l , int r , int v , int u){
	fill(A + l , A + r + 1 , 2);
	A[v] = A[u] = 1;
	for(pair<pii , string> i : vec){
		int x = i.X.X , y = i.X.Y;
		string s = i.Y;
		if(x < l || r < x)	continue;
		if(y < l || r < y)	continue;
		if(A[x] + A[y] == 4)	continue;
		if(s == "<=" && A[x] > A[y]){
			return 0;
		}
		if(s == "<" && A[x] >= A[y]){
			return 0;
		}
		if(s == "=" && A[x] != A[y]){
			return 0;
		}
	}
	return 1;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n >> k;
	for(int i = 0 ; i < k ; i++){
		int x , y;
		string s;
		cin >> x >> s >> y;
		if(s[0] == '>'){
			s[0] = '<';
			swap(x , y);
		}
		vec.push_back({{x , y} , s});
	}
	for(int i = 0 ; i < MAXN ; i++){
		for(int j = 0 ; j < i ; j++){
			dp[i][j] = 1;
		}
	}
	for(int l = 2 * n ; l >= 1 ; l--){
		for(int r = l ; r <= 2 * n ; r++){
			if(l % 2 == r % 2)	continue;
			if(check(l , r , l , l + 1)){
				dp[l][r] += dp[l + 2][r];
			}
			if(check(l , r , l , r)){
				dp[l][r] += dp[l + 1][r - 1];
			}
			if(check(l , r , r - 1 , r)){
				dp[l][r] += dp[l][r - 2];
			}
		}
	}
	cout << dp[1][2 * n] / 3 << endl;

    return 0;
}
/*

*/