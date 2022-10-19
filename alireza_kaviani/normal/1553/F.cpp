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

const ll MAXN = 3e5 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

ll n , ans , sum , A[MAXN] , fen[2][MAXN];

void add(int ind , int x , ll val){
	for( ; x < MAXN ; x += x & -x)	fen[ind][x] += val;
}

ll get(int ind , int x){
	ll ans = 0;
	for( ; x ; x -= x & -x)	ans += fen[ind][x];
	return ans;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n;
	for(ll i = 0 ; i < n ; i++){
		cin >> A[i];
		ans += sum + A[i] * i - get(0 , A[i]); sum += A[i];
		for(ll j = A[i] ; j < MAXN ; j += A[i]){
			add(0 , j , A[i]);
			ans -= (i - get(1 , j - 1)) * A[i];
		}
		add(1 , A[i] , 1);
		cout << ans << sep;
	}

    return 0;
}
/*

*/