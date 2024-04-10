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

int n , L[3] , R[3] , ans[3];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n;
	for(int i = 0 ; i < 3 ; i++){
		cin >> L[i] >> R[i];
		ans[i] = L[i];
		n -= L[i];
	}
	for(int i = 0 ; i < 3 ; i++){
		while(ans[i] < R[i] && n > 0){
			ans[i]++;
			n--;
		}
	}
	for(int i = 0 ; i < 3 ; i++){
		cout << ans[i] << sep;
	}

    return 0;
}
/*

*/