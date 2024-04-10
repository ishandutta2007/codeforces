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

int q , n , A[MAXN];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> q;
	while(q--){
		int ans = 1;
		cin >> n;
		for(int i = 0 ; i < n ; i++){
			cin >> A[i];
		}
		for(int i = 0; i < n ; i++){
			for(int j = i + 1 ; j < n ; j++){
				int x = j - i , y = A[j] - A[i];
				int cur = 0;
				for(int k = 0 ; k < n ; k++){
					if(A[k] * x - y * k == A[i] * x - y * i){
						cur++;
					}
				}
				ans = max(ans , cur);
			}
		}
		cout << n - ans << endl;
	}

    return 0;
}
/*

*/