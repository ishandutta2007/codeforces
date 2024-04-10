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

const ll MAXN = 2e5 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

ll n , k , T , mark[LOG] , last[LOG] , cost[LOG][LOG] , remCost[LOG] , dp[1 << LOG];
string s;
vector<int> vec;

void insert(int i){
	if(find(all(vec) , i) != vec.end())	vec.erase(find(all(vec) , i));
	vec.push_back(i);
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	fill(last , last + LOG , -1);

	cin >> n >> k >> T >> s;
	for(int i = 0 ; i < k ; i++)	cin >> remCost[i];
	for(int i = 0 ; i < k ; i++){
		for(int j = 0 ; j < k ; j++){
			cin >> cost[i][j];
		}
	}
	for(int i = 0 ; i < n ; i++){
		int x = s[i] - 'A' , mask = (1 << k) - 1;
		mark[x] = 1;
		for(int j = SZ(vec) - 1 ; j >= 0 ; j--){
			int y = vec[j];
			if(x == y){
				dp[mask] += cost[x][x];
				dp[mask - (1 << x)] -= cost[x][x];
				break;
			}
			dp[mask] += cost[y][x];
			dp[mask - (1 << x)] -= cost[y][x];
			mask -= (1 << y);
			dp[mask] -= cost[y][x];
			dp[mask - (1 << x)] += cost[y][x];
		}
		insert(x);
	}
	for(int i = 0 ; i < k ; i++){
		for(int j = 0 ; j < (1 << k) ; j++){
			if((j & (1 << i)) == 0){
				dp[j] += dp[j + (1 << i)];
			}
		}
	}
	ll ans = 0;
	for(int i = 0 ; i < (1 << k) ; i++){
		int flag = 0;
		for(int j = 0 ; j < k ; j++){
			if((i & (1 << j)) == 0 && mark[j] == 0){
				flag = 1;
			}
		}
		if(flag)	continue;
		ll cur = dp[i];
	//	cout << i << sep << dp[i] << endl;
		for(int j = 0 ; j < k ; j++){
			if(i & (1 << j)){
				cur += 0;
				flag |= mark[j];
			}
			else{
				cur += remCost[j];
			}
		}
		if(flag == 0)	continue;
		if(cur <= T){
			ans++;
		}
	}
	cout << ans << endl;

    return 0;
}
/*

*/