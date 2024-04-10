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

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> q;
	while(q--){
		vector<int> vec;
		cin >> n >> m;
		for(int i = 1 ; i <= n ; i++){
			for(int j = 1 ; j <= m ; j++){
				vec.push_back(max(i - 1 , n - i) + max(j - 1 , m - j));
			}
		}
		sort(all(vec));
		for(int i = 0 ; i < n * m ; i++){
			cout << vec[i] << sep;
		}
		cout << endl;
	}

    return 0;
}
/*

*/