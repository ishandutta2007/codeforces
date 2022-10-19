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
const ll LOG = 31;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int q , v , u , dp[LOG][LOG];
vector<int> A , B;

vector<int> get(int x){
	vector<int> ans = {-1};
	for(int i = 0 ; i < 30 ; i++){
		if(x & (1 << i))	ans.push_back(i);
	}
	return ans;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> q;
	while(q--){
		cin >> v >> u;
		A = get(v); B = get(u);
		if(SZ(B) > SZ(A)){
			cout << "NO" << endl;
			continue;
		}
		memset(dp , 0 , sizeof(dp));
		int flag = 0;
		dp[0][0] = 1;
		for(int i = 1 ; i < SZ(A) ; i++){
			for(int j = 1 ; j < SZ(B) ; j++){
				if(A[i] > B[j])	continue;
				dp[i][j] = dp[i - 1][j - 1];
				if(A[i] == B[j]){
					continue;
				}
				dp[i][j] |= dp[i - 1][j];
			}
		}
		if(dp[SZ(A) - 1][SZ(B) - 1] == 0){
			cout << "NO" << endl;
			continue;
		}
		cout << "YES" << endl;
	}
	
    return 0;
}
/*

*/