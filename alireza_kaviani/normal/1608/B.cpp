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

int q , n , a , b;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> q;
	while(q--){
		cin >> n >> a >> b;
		if(abs(a - b) > 1 || a + b > n - 2){
			cout << -1 << endl;
			continue;
		}
		int cur = b + 1;
		if(a >= b){
			cout << cur++ << sep;
		}
		for(int i = 1 ; i <= b ; i++){
			cout << cur++ << sep;
			cout << i << sep;
		}
		if(a > b){
			for(int i = n ; i >= cur ; i--){
				cout << i << sep;
			}
		}
		else{
			for(int i = cur ; i <= n ; i++){
				cout << i << sep;
			}
		}
		cout << endl;
	}

    return 0;
}
/*

*/