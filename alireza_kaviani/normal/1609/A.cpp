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

ll q , n , A[MAXN];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> q;
	while(q--){
		cin >> n; 
		ll sum = 0 , mx = 0 , mul = 1;
		for(int i = 0 ; i < n ; i++){
			cin >> A[i];
			while(A[i] % 2 == 0){
				A[i] /= 2;
				mul *= 2;
			}
			mx = max(mx , A[i]);
			sum += A[i];
		}
		cout << sum - mx + mx * mul << endl;
	}

    return 0;
}
/*

*/