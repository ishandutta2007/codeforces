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

const ll MAXN = 1000 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

ll n , m , k , dp[MAXN][MAXN] , R[MAXN];
string s;
vector<string> vec = {""};
vector<pii> order;

int check(string t){
	//cout << s << sep << t << endl;
	for(int i = 0 ; i < n ; i++){
		R[i] = n + 1;
		for(int j = i ; j < n ; j++){
			if(s[j] < t[j - i])	break;
			if(s[j] > t[j - i] || j - i + 1 == SZ(t)){
				R[i] = j + 1;
				break;
			}
		}
		//cout << i << sep << R[i] << endl;
	}
	fill(dp[0] , dp[0] + MAXN , 0);
	dp[0][n] = 1;
	for(int i = 1 ; i <= m ; i++){
		for(int j = n ; j >= 0 ; j--){
			dp[i - 1][j] = min(k , dp[i - 1][j] + dp[i - 1][j + 1]);
		}
		for(int j = 0 ; j < n ; j++){
			dp[i][j] = dp[i - 1][R[j]];
	//		cout << i << sep << j << sep << dp[i][j] << endl;
		}
	}
	return (dp[m][0] >= k);
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n >> m >> k >> s;
	for(int i = 0 ; i < n ; i++){
		vec.push_back(s.substr(i));
	}
	sort(all(vec));
	for(int i = 1 ; i <= n ; i++){
		int flag = 0;
		for(int j = 0 ; j < SZ(vec[i]) ; j++){
			if(j >= SZ(vec[i - 1]) || vec[i][j] != vec[i - 1][j])	flag = 1;
			if(flag){
				order.push_back({n - SZ(vec[i]) , j + 1});
			}
		}
	}
	int l = 0 , r = SZ(order);
	while(r - l > 1){
		int mid = l + r >> 1;
		string t = s.substr(order[mid].X , order[mid].Y);
		if(check(t))	l = mid;
		else	r = mid;
	}
	//cout << l << endl;
	cout << s.substr(order[l].X , order[l].Y) << endl;;

    return 0;
}
/*

*/