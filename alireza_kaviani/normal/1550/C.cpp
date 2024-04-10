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

ll q , n , A[MAXN];

int bad(int x , int y , int z){
	return (abs(x - y) + abs(y - z) == abs(z - x));
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> q;
	while(q--){
		cin >> n;
		for(int i = 0 ; i < n ; i++){
			cin >> A[i];
		}
		if(n == 1){
			cout << 1 << endl;
			continue;
		}
		ll ans = 0;
		int L = 0;
		for(int i = 0 ; i < n ; i++){
			for(int j = i ; j < n ; j++){
				int flag = 0;
				for(int k = i ; k < j ; k++){
					for(int l = k + 1 ; l < j ; l++){
						if(bad(A[k] , A[l] , A[j]))	flag = 1;
					}
				}
				if(flag)	break;
				ans++;
			}
		}
		cout << ans << endl;
	}

    return 0;
}
/*

*/