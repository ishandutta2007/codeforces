#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

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
 
ll q , n , m , A[MAXN] , dp[MAXN][2];
vector<pll> vec[MAXN];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> q;
	while(q--){
		cin >> n >> m;
		for(int i = 0 ; i < n + 5 ; i++){
			dp[i][0] = dp[i][1] = 0;
			vec[i].clear();
		}
		for(int i = 0 ; i < n ; i++){
			cin >> A[i];
		}
		sort(A , A + n); A[n] = MOD;
		vector<pll> v1 , v2;
		for(int i = 0 ; i < m ; i++){
			int l , r;
			cin >> l >> r;
			if((*lower_bound(A , A + n , l)) <= r)	continue;
			v1.push_back({l , -r});
		}
		sort(all(v1));
		for(pll i : v1){
			while(SZ(v2) && v2.back().Y >= -i.Y)	v2.pop_back();
			v2.push_back({i.X , -i.Y});
		}
		for(int i = 0 ; i < n ; i++){
			vec[i + 1].push_back({A[i] , A[i]});
		}
		for(pll i : v2){
			int ind = lower_bound(A , A + n , i.X) - A;
			vec[ind].push_back(i);
		}
		for(int i = 0 ; i < n ; i++){
			vec[i].push_back({A[i] , A[i]});
		}
		dp[0][0] = A[0] - vec[0][0].Y;
		dp[0][1] = dp[0][0] * 2;
		for(int i = 1 ; i < n ; i++){
			for(int j = 0 ; j < 2 ; j++){
				dp[i][j] = INF;
				for(int k = 0 ; k < 2 ; k++){
					for(int l = 0 ; l + 1 < SZ(vec[i]) ; l++){
						ll cost = (vec[i][l].X - A[i - 1]) * (2 - k) + (A[i] - vec[i][l + 1].Y) * (j + 1);
						dp[i][j] = min(dp[i][j] , dp[i - 1][k] + cost);
					}
				}
			}
		}
		ll ans = INF;
		for(int i = 0 ; i < 2 ; i++){
			ans = min(ans , dp[n - 1][i] + (vec[n].back().X - A[n - 1]) * (2 - i));
		}
		cout << ans << endl;
	}

    return 0;
}
/*

*/