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

const ll MAXN = 110;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int q , n , m , dp[MAXN][MAXN] , par[MAXN][MAXN];
string names[MAXN] , text[MAXN];
vector<string> vec[MAXN];

vector<string> split(string s){
	int ind = -1;
	for(int i = 0 ; i < SZ(s) ; i++){
		if(s[i] == ':'){
			ind = i;
			break;
		}
	}
	return {s.substr(0 , ind), s.substr(ind + 1)};
}

vector<string> split2(string s){
	vector<string> ans;
	ans.push_back("");
	for(int i = 0 ; i < SZ(s) ; i++){
		if(s[i] == '.' || s[i] == ',' || s[i] == '!' || s[i] == '?' || s[i] == ' '){
			ans.push_back("");
			continue;
		}
		ans[SZ(ans) - 1].push_back(s[i]);
	}
	return ans;
}

int in(string A , string B){
	vector<string> v = split2(B);
	for(string u : v){
		if(A == u){
			return 1;
		}
	}
	return 0;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> q;
	while(q--){
		memset(dp , 0 , sizeof(dp));
		memset(par , 0 , sizeof(par));
		cin >> n;
		for(int i = 1 ; i <= n ; i++){
			cin >> names[i];
		}
		cin >> m;
		getline(cin , text[0]);
		for(int i = 1 ; i <= m ; i++){
			getline(cin , text[i]);
		}
		dp[0][0] = 1;
		for(int i = 1 ; i <= m ; i++){
			vec[i] = split(text[i]);
			for(int j = 1 ; j <= n ; j++){
				dp[i][j] = 0;
				par[i][j] = -1;
				if(in(names[j] , vec[i][1])){
					continue;
				}
				if(vec[i][0] != "?" && vec[i][0] != names[j]){
					continue;
				}
				for(int k = 0 ; k <= n ; k++){
					if(dp[i - 1][k] && k != j){
						dp[i][j] = 1;
						par[i][j] = k;
					}
				}
			}
		}
		int x = 0;
		for(int i = 1 ; i <= n ; i++){
			if(dp[m][i]){
				x = i;
			}
		}
		if(x == 0){
			cout << "Impossible" << endl;
			continue;
		}
		for(int i = m ; i >= 1 ; i--){
			vec[i][0] = names[x];
			x = par[i][x];
		}
		for(int i = 1 ; i <= m ; i++){
			cout << vec[i][0] << ":" << vec[i][1] << endl;
		}
	}

    return 0;
}
/*

*/