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

int q , n , l , r , col[MAXN] , cnt[MAXN];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> q;
	while(q--){
		cin >> n >> l >> r;
		fill(cnt , cnt + n + 5 , 0);
		for(int i = 0 ; i < l ; i++){
			cin >> col[i];
			cnt[col[i]]++;
		}
		for(int i = 0 ; i < r ; i++){
			cin >> col[i];
			cnt[col[i]]--;
		}
		ll ans = 0 , cur = 0 , val = 0;
		for(int i = 1 ; i <= n ; i++){
		//cout << abs(cnt[i]) << endl;
			ans += abs(cnt[i]);
			if(l > r && cnt[i] > 0)	val += abs(cnt[i]) / 2;
			if(r > l && cnt[i] < 0)	val += abs(cnt[i]) / 2;
//			cout << i << sep << ans << sep << val << sep << cur << endl;
		}
//		cout << ans << sep << val << sep << abs(r - l) << endl;
//		cout << abs(r - l) / 2 - val << endl;
		cout << ans / 2 + max(0ll , abs(r - l) / 2 - val) << endl;
	}

    return 0;
}
/*

*/