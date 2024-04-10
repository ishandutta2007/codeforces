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

const ll MAXN = 1e6;
const ll LOG = 25;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int l , r;
vector<pair<pii , int>> ans;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> l >> r;
	cout << "YES" << endl;
	if(l == r){
		cout << 2 << sep << 1 << endl;
		cout << 1 << sep << 2 << sep << l << endl;
		return 0;
	}
	int x = r - l , n = LOG + 2;
	for(int i = 2 ; i < n ; i++){
		for(int j = i + 1 ; j <= n ; j++){
			int cost = (1 << max(0 , n - j - 1));
			if(cost > MAXN)	continue;
			ans.push_back({{i , j} , (1 << max(0 , n - j - 1))});
		}
	}
	ans.push_back({{1 , n} , l});
	for(int i = 0 , cur = 0 ; i < LOG ; i++){
		if(x & (1 << i)){
			ans.push_back({{1 , n - i - 1} , l + cur});
			cur += (1 << i);
		}
	}
	cout << n << sep << SZ(ans) << endl;
	for(auto &i : ans){
		cout << i.X.X << sep << i.X.Y << sep << i.Y << endl;
	}

    return 0;
}
/*

*/