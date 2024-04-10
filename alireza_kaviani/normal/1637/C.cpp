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

ll n , q , A[MAXN];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> q;
	while(q--){
		cin >> n;
		ll sum = 0 , even = 0 , odd = 0 , tot = 0;
		for(int i = 1 ; i <= n ; i++){
			cin >> A[i];
			if(i == 1 || i == n)	continue;
			sum += (A[i] + 1) / 2;
			if(A[i] >= 2){
				tot++;
				if(A[i] % 2 == 0){
					even++;
				}
			}
			if(A[i] % 2 == 1){
				odd++;
			}
		}
		if(n == 3){
			if(A[2] % 2 == 0){
				cout << A[2] / 2 << endl;
			}
			else{
				cout << -1 << endl;
			}
			continue;
		}
		if(sum == 0){
			cout << 0 << endl;
			continue;
		}
		if(tot == 0){
			cout << -1 << endl;
			continue;
		}
		if(even >= 1 || odd != 1){
			cout << sum << endl;
			continue;
		}
		if(sum == 2){
			cout << -1 << endl;
			continue;
		}
		cout << sum + 1 << endl;
	}

    return 0;
}
/*

*/