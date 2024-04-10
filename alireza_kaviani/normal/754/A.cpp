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

int n , sum , A[MAXN];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n;
	for(int i = 1 ; i <= n ; i++){
		cin >> A[i];
		sum += A[i];
	}
	if(sum != 0){
		cout << "YES" << endl;
		cout << 1 << endl;
		cout << "1 " << n << endl;
		return 0;
	}
	sum = 0;
	for(int i = 1 ; i <= n ; i++){
		sum += A[i];
		if(sum != 0){
			cout << "YES" << endl;
			cout << 2 << endl;
			cout << "1 " << i << endl;
			cout << i + 1 << sep << n << endl;
			return 0;
		}
	}
	cout << "NO" << endl;

    return 0;
}
/*

*/