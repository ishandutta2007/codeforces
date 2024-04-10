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

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int n , A[MAXN] , cnt[MAXN] , pw2[MAXN] , ans[MAXN];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	pw2[0] = 1;
	for(int i = 1 ; i < MAXN ; i++)	pw2[i] = pw2[i - 1] * 2 % MOD;

	cin >> n;
	for(int i = 0 ; i < n ; i++){
		cin >> A[i];
		cnt[A[i]]++;
	}
	for(int i = 1 ; i < MAXN ; i++){
		for(int j = i + i ; j < MAXN ; j += i){
			cnt[i] += cnt[j];
		}
		if(cnt[i] == 0)	continue;
		ans[i] = 1ll * pw2[cnt[i] - 1] * cnt[i] % MOD;
	}
	for(int i = MAXN - 1 ; i >= 1 ; i--){
		for(int j = i + i ; j < MAXN ; j += i){
			ans[i] = (ans[i] + MOD - ans[j]) % MOD;
		}
	}
	ll res = 0;
	for(int i = 2 ; i < MAXN ; i++){
		res = (res + 1ll * i * ans[i]) % MOD;
	}
	cout << res << endl;

    return 0;
}
/*

*/