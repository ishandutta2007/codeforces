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

int q , x , d;

int check(int n){
	for(int i = 2 ; i * i <= n && i < n ; i++){
		if(n % i == 0){
			return 1;
		}
	}
	return 0;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> q;
	while(q--){
		int cnt = 0;
		cin >> x >> d;
		while(x % d == 0){
			x /= d;
			cnt++;
		}
		if(cnt <= 1){
			cout << "NO" << endl;
		}
		else if(check(x) || (cnt >= 4 && check(d))){
			cout << "YES" << endl;
		}
		else if(cnt == 3 && check(d) && 1ll * x * x != d){
			cout << "YES" << endl;
		}
		else{
			cout << "NO" << endl;
		}
	}

    return 0;
}
/*

*/