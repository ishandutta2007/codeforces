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

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 1e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

ll q , n , A[MAXN] , B[MAXN];

ll get(ll A[] , ll x){
	ll ans = INF;
	for(int i = 1 ; i <= n ; i++){
		ans = min(ans , abs(A[i] - x));
	}
	return ans;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> q;
	while(q--){
		cin >> n;
		for(int i = 1 ; i <= n ; i++)	cin >> A[i];
		for(int i = 1 ; i <= n ; i++)	cin >> B[i];
		ll ans = min(abs(A[1] - B[1]) + abs(A[n] - B[n]) , abs(A[1] - B[n]) + abs(A[n] - B[1]));
		ll la = get(B , A[1]) , ra = get(B , A[n]) , lb = get(A , B[1]) , rb = get(A , B[n]);
		ans = min(ans , la + ra + lb + rb);
		ans = min(ans , abs(A[1] - B[1]) + ra + rb);
		ans = min(ans , abs(A[1] - B[n]) + ra + lb);
		ans = min(ans , abs(A[n] - B[1]) + la + rb);
		ans = min(ans , abs(A[n] - B[n]) + la + lb);
		cout << ans << endl;
	}

    return 0;
}
/*

*/