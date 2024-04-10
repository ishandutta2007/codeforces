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
		int flag = 0;
		for(int i = 0 ; i < n ; i++){
			cin >> A[i];
		}
		for(int i = 1 ; i < (1 << n) ; i++){
			for(int j = i ; j > 0 ; j = (j - 1) & i){
				int sum = 0;
				for(int k = 0 ; k < n ; k++){
					if(i & (1 << k))	sum -= A[k];
					if(j & (1 << k))	sum += A[k] * 2;
				}
				if(sum == 0)	flag = 1;
			}
		}
		cout << (flag ? "YES" : "NO") << endl;
	}

    return 0;
}
/*

*/