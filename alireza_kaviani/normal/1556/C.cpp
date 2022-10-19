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

ll n , ans , A[MAXN];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n;
	for(int i = 0 ; i < n ; i++){
		cin >> A[i];
		if(i & 1){
			A[i] *= -1;
		}
	}
	for(int i = 0 ; i < n ; i += 2){
		ll sum = 0 , mn = -1;
		for(int j = i + 1 ; j < n ; j++){
			if(j & 1){
		//		ll x = (i + 1 != j) , y = (x & (sum != 0)) , yy = ()z = (x & (mn != 0));
				ll cur = min({A[i] + mn, A[i] + sum , -A[j] - 1 , -A[j] - sum + mn}) + 1;
				ans += max(0ll , cur);
		//		cout << i << sep << j << sep << mn << sep << sum << sep << cur << endl;
			}
			sum += A[j];
			mn = min(mn , sum);
		}
	}
	cout << ans << endl;

    return 0;
}
/*

*/