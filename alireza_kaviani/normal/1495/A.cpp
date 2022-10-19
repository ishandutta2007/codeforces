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

ll q , n , A[MAXN] , B[MAXN];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> q;
	while(q--){
		cin >> n;
		int curx = 0 , cury = 0;
		for(int i = 0 ; i < 2 * n ; i++){
			ll x , y;
			cin >> x >> y;
			x *= x; y *= y;
			if(x == 0)	A[cury++] = y;
			if(y == 0)	B[curx++] = x;
		}
		sort(A , A + n);
		sort(B , B + n);
		double ans = 0;
		for(int i = 0 ; i < n ; i++){
			ans += sqrt(A[i] + B[i]);
		}
		printf("%.20f\n" , ans);
	}

    return 0;
}
/*

*/