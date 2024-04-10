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

int n , ans , first[26][26];
string s , t;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n >> s >> t;
	for(int i = 0 ; i < SZ(s) ; i++){
		if(s[i] != t[i]){
			first[s[i] - 97][t[i] - 97] = i + 1;
			ans++;
		}
	}
	for(int i = 0 ; i < 26 ; i++){
		for(int j = 0 ; j < i ; j++){
			if(first[i][j] > 0 && first[j][i] > 0){
				return cout << ans - 2 << endl << first[i][j] << sep << first[j][i] << endl , 0;
			}
		}
	}
	for(int i = 0 ; i < 26 ; i++){
		for(int j = 0 ; j < 26 ; j++){
			for(int k = 0 ; k < 26 ; k++){
				if(first[i][j] > 0 && first[j][k] > 0){
					return cout << ans - 1 << endl << first[i][j] << sep << first[j][k] << endl , 0;
				}
			}
		}
	}
	cout << ans << endl << -1 << sep << -1 << endl;;

    return 0;
}
/*

*/