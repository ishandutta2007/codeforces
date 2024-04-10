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

int q , n , m , A[MAXN] , B[MAXN] , mark[MAXN];
vector<pii> vec[MAXN];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> q;
	while(q--){
		cin >> n >> m;
		int ans = 0;
		vector<int> compress;
		for(int i = 0 ; i < n * m ; i++){
			cin >> A[i]; 
			vec[i].clear(); mark[i] = 0;
			compress.push_back(A[i]);
		}
		sort(all(compress));
		compress.resize(unique(all(compress)) - compress.begin());
		for(int i = 0 ; i < n * m ; i++){
			A[i] = lower_bound(all(compress) , A[i]) - compress.begin();
			B[i] = A[i];
		}
		sort(B , B + n * m);
		for(int i = 0 ; i < n * m ; i++){
			vec[B[i]].push_back({i / m , -i});
		}
		for(int i = 0 ; i < n * m ; i++){
			sort(all(vec[i]));
			reverse(all(vec[i]));
		}
		for(int i = 0 ; i < n * m ; i++){
			pii pos = vec[A[i]].back();
			vec[A[i]].pop_back();
			pos.Y *= -1;
			for(int j = pos.X * m ; j <= pos.Y ; j++){
				ans += mark[j];
			}
			mark[pos.Y] = 1;
		}
		cout << ans << endl;
	}

    return 0;
}
/*

*/