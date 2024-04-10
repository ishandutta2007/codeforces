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
#define lc			id << 1
#define rc			lc | 1

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

ll q , n , x , A[MAXN] , ps[MAXN] , L[MAXN] , dp[MAXN];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> q;
	while(q--){
		cin >> n;
		fill(A , A + n + 5 , 0);
		fill(ps , ps + n + 5 , 0);
		fill(dp , dp + n + 5 , 0);
		for(int i = 1 ; i <= n ; i++){
			cin >> A[i];
		}
		cin >> x;
		for(int i = 1 ; i <= n ; i++){
			A[i] -= x;
		}
		partial_sum(A , A + n + 5 , ps);
		vector<pll> vec;
		set<int> st;
		for(int i = 0 ; i <= n ; i++){
			vec.push_back({ps[i] , i});
		}
		sort(all(vec) , greater<pll>());
		st.insert(-1);
		for(pll i : vec){
			int ind = i.Y;
			L[ind] = *prev(st.lower_bound(ind - 1));
			st.insert(ind);
		}
		ll ans = 0;
		for(int i = 1 ; i <= n ; i++){
			if(i > 1){
				L[i] = max(L[i] , L[i - 1]);
			}
			int prv = (L[i] < 0 ? 0 : dp[L[i]]);
			dp[i] = prv + (i - L[i] - 1);
			ans = max(ans , dp[i]);
		//	cout << i << sep << dp[i] << sep << L[i] << sep << ps[i] << endl;
		}
		cout << ans << endl;
	}

    return 0;
}
/*

*/