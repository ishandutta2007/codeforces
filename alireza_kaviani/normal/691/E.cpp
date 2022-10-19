#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef vector<vector<ll>> Mat;

#define all(x)						(x).begin(),(x).end()
#define X							first
#define Y							second
#define sep							' '
#define endl						'\n'
#define SZ(x)						ll(x.size())

const ll MAXN = 100 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

ll n , k , A[MAXN];
Mat M(MAXN , vector<ll>(MAXN , 0));

Mat Mul(Mat A , Mat B){
	Mat ans(MAXN , vector<ll>(MAXN , 0));
	for(int i = 0 ; i < MAXN ; i++){
		for(int j = 0 ; j < MAXN ; j++){
			for(int k = 0 ; k < MAXN ; k++){
				ans[i][k] = (ans[i][k] + A[i][j] * B[j][k]) % MOD;
			}
		}
	}
	return ans;
}

Mat Pow(Mat A , ll k){
	Mat ans(MAXN , vector<ll>(MAXN , 0));
	for(int i = 0 ; i < MAXN ; i++)	ans[i][i] = 1;
	for( ; k ; A = Mul(A , A) , k >>= 1){
		if(k & 1){
			ans = Mul(ans , A);
		}
	}
	return ans;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n >> k;
	for(int i = 0 ; i < n ; i++)	cin >> A[i];
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			if(__builtin_popcountll(A[i] ^ A[j]) % 3 == 0){
				M[i][j] = 1;
			}
		}
	}
	Mat ans = Pow(M , k - 1);
	ll res = 0;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			res = (res + ans[i][j]) % MOD;
		}
	}
	cout << res << endl;

    return 0;
}
/*

*/