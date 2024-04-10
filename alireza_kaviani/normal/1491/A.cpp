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

int n , q , cnt[2] , A[MAXN];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n >> q;
	for(int i = 1 ; i <= n ; i++){
		cin >> A[i];
		cnt[A[i]]++;
	}
	while(q--){
		int t , x;
		cin >> t >> x;
		if(t == 1){
			cnt[A[x]]--;
			A[x] = 1 - A[x];
			cnt[A[x]]++;
		}
		if(t == 2){
			if(cnt[1] >= x)	cout << 1 << endl;
			else	cout << 0 << endl;
		}
	}

    return 0;
}
/*

*/