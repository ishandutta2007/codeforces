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

ll n , m , k , x , s , ans = INF , A[MAXN] , B[MAXN] , C[MAXN] , D[MAXN];
vector<pll> vec = {{0 , 0}};

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n >> m >> k >> x >> s;
	for(int i = 1 ; i <= m ; i++){
		cin >> A[i];
	}
	for(int i = 1 ; i <= m ; i++){
		cin >> B[i];
	}
	for(int i = 1 ; i <= k ; i++){
		cin >> C[i];
	}
	for(int i = 1 ; i <= k ; i++){
		cin >> D[i];
		vec.push_back({D[i] , C[i]});
	}
	A[0] = x;
	for(int i = 0 ; i <= m ; i++){
		if(B[i] > s)	continue;
		int ind = upper_bound(all(vec) , pll(s - B[i] , INF)) - vec.begin() - 1;
		ll cnt = n - vec[ind].Y;
		ans = min(ans , cnt * A[i]);
	}
	cout << ans << endl;

    return 0;
}
/*

*/