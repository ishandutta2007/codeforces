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

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int q , n , m;
string s[MAXN];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> q;
	while(q--){
		cin >> n >> m;
		vector<pair<pii, pii>> ans;
		for(int i = 0 ; i < n ; i++){
			cin >> s[i];
		}
		if(s[0][0] == '1'){
			cout << -1 << endl;
			continue;
		}
		for(int i = n - 1 ; i >= 0 ; i--){
			for(int j = m - 1 ; j >= 0 ; j--){
				if(s[i][j] == '0')	continue;
				int x = i - 1 , y = j;
				if(i == 0){
					x = i; y = j - 1;
				}
				ans.push_back({{x + 1 , y + 1}, {i + 1 , j + 1}});
			}
		}
		cout << SZ(ans) << endl;
		for(pair<pii, pii> i : ans){
			cout << i.X.X << sep << i.X.Y << sep << i.Y.X << sep << i.Y.Y << endl;
		}
	}

    return 0;
}
/*

*/