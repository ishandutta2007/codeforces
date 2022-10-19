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

int q , n , m;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> q;
	while(q--){
		cin >> n >> m;
		for(int i = 1 ; i <= m ; i++){
			cout << i % 2;
		}
		cout << endl;
		for(int i = 2 ; i < n ; i++){
			cout << i % 2;
			for(int j = 2 ; j < m ; j++){
				cout << 0;
			}
			cout << i % 2 << endl;
		}
		for(int i = 1 ; i <= m ; i++){
			if(i % 2 == 0){
				cout << 0;
				continue;
			}
			if(i != 1 && i != m && i != m - 1){
				cout << 1;
				continue;
			}
			cout << n % 2;
		}
		cout << endl;
	}

    return 0;
}
/*

*/