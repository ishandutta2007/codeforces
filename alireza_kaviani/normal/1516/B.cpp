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

int q , n , A[MAXN];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> q;
	while(q--){
		cin >> n;
		int xr = 0;
		for(int i = 0 ; i < n ; i++){
			cin >> A[i];
			xr ^= A[i];
		}
		if(xr == 0){
			cout << "YES" << endl;
			continue;
		}
		int cnt = 0 , cur = 0;
		for(int i = 0 ; i < n ; i++){
			cur ^= A[i];
			if(cnt == 0 && cur == xr)	cnt++;
			if(cnt == 1 && cur == 0)	cnt++;
		}
		cout << (cnt == 2 ? "YES" : "NO") << endl;
	}

    return 0;
}
/*

*/