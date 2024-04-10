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

ll q , n , S[MAXN] , A[MAXN];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> q;
	while(q--){
		cin >> n; ll ans = 0;
		fill(A , A + n + 10 , 0);
		for(int i = 1 ; i <= n ; i++){
			cin >> S[i];
		}
		for(int i = 1 ; i <= n ; i++){
			ans += max(0ll , S[i] - 1 - A[i]);
			for(int j = i + 2 ; j <= min(n , i + S[i]) ; j++)	A[j]++;
			A[i + 1] += max(0ll , A[i] - S[i] + 1);
		}
		cout << ans << endl;
	}

    return 0;
}
/*

*/