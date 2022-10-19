#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define all(x)						(x).begin(),(x).end()
#define X							first
#define Y							second
#define sep							' '
//#define endl						'\n'
#define SZ(x)						ll(x.size())

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int n , k , xr , res[MAXN];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n >> k;
	if(n % 2 == 1 && k % 2 == 0)	return cout << -1 << endl , 0;
	int cnt = -1;
	for(int i = 0 ; i < 1000 ; i++){
		if(k * i >= n && (k * i) % 2 == n % 2){
			int cur = (i * k - n) / 2;
			if((cur + n - 1) / n * 2 + 1 > i)	continue;
			cnt = i;
			break;
		}
	}
	int cur = (cnt * k - n) / 2 , ptr = cur + 1 , ans = 0;
	for(int i = 1 ; i <= n ; i++){
		res[i] = (cur / n + (cur % n >= i)) * 2 + 1;
	}
	for(int i = 0 ; i < cnt ; i++){
		vector<pii> vec;
		for(int j = 1 ; j <= n ; j++){
			vec.push_back({res[j] , j});
		}
		sort(all(vec) , greater<pii>());
		cout << "? ";
		for(int j = 0 ; j < k ; j++){
			cout << vec[j].Y << sep;
			res[vec[j].Y]--;
		}
		cout << endl;
		int x; cin >> x;
		ans ^= x;
	}
	cout << "! " << ans << endl;

    return 0;
}
/*

*/