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

const ll MAXN = 50;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int q , n , k , ans[MAXN][MAXN];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> q;
	while(q--){
		memset(ans , 0 , sizeof(ans));
		cin >> n >> k;
		if(k > (n + 1) / 2){
			cout << -1 << endl;
			continue;
		}
		for(int i = 0 ; i < k ; i++){
			ans[2 * i][2 * i] = 1;
		}
		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < n ; j++){
				cout << (ans[i][j] ? "R" : ".");
			}
			cout << endl;
		}
	}

    return 0;
}
/*

*/