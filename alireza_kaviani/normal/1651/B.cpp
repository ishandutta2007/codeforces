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
const ll MOD = 1e9; //998244353; //1e9 + 9;

int q , n;
vector<ll> vec;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	vec.push_back(1);
	while(vec.back() * 3 <= MOD){
		vec.push_back(vec.back() * 3);
	}
	cin >> q;
	while(q--){
		cin >> n;
		if(SZ(vec) < n){
			cout << "NO" << endl;
			continue;
		}
		cout << "YES" << endl;
		for(int i = 0 ; i < n ; i++){
			cout << vec[i] << sep;
		}
		cout << endl;
	}

    return 0;
}
/*

*/