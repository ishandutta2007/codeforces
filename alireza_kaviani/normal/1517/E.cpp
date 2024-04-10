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

const ll MAXN = 3e5 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 998244353; //1e9 + 9;

ll q , n , bound , ans , A[MAXN] , ps[2][MAXN];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> q;
	while(q--){
		cin >> n; bound = ans = 0;
		fill(ps[0] , ps[0] + n + 10 , 0);
		fill(ps[1] , ps[1] + n + 10 , 0);
		for(int i = 0 ; i < n ; i++){
			cin >> A[i];
			bound += A[i];
			ps[i % 2][i] = A[i];
		}
		if(n == 1){
			cout << 1 << endl;
			continue;
		}
		partial_sum(ps[0] , ps[0] + n + 10 , ps[0]);
		partial_sum(ps[1] , ps[1] + n + 10 , ps[1]);
		bound = (bound - 1) / 2;
		for(int x = 0 ; x < 2 ; x++){
			for(int y = 0 ; y < 2 ; y++){
				if(n == 2 && x == 1 && y == 1)	continue;
				bound += x * A[0] + y * A[n - 1];
//				cout << bound << endl;
				ll cur = 0;
				for(int i = 0 ; i < n ; i++){
					cur += A[i];
					if(cur + (i < n - 1 ? A[n - 1] : 0) > bound)	break;
					int l = i , r = n - 1;
					while(r - l > 1){
						int mid = l + r >> 1;
						ll cost = cur + ps[i%2][mid] - ps[i%2][i] + A[n - 1];
						if(cost <= bound)	l = mid;
						else	r = mid;
					}
					if(i == 0 && x == 1)	continue;
					if(l % 2 != i % 2)	l--;
					if(l == n - 2 && y == 0)	l -= 2;
					if(i == n - 2)	continue;
					ans += (l - i + 2) / 2;
//					cout << "ans " << i << sep << l << endl;
				}
				bound -= x * A[0] + y * A[n - 1];
//				cout << x << sep << y << sep << ans << endl;
			}
		}
//		cout << ans % MOD << endl;
		ll sum = 0;
		for(int i = n ; i >= 2 ; i--){
			if(sum <= bound)	ans++;
			sum += A[i - 1];
		}
		cout << ans % MOD << endl;
//		cout << "==========" << endl;
	}

    return 0;
}
/*

*/