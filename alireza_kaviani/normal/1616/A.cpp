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

const ll MAXN = 110;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int q , n , cnt[MAXN];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> q;
	while(q--){
		cin >> n;
		fill(cnt , cnt + MAXN , 0);
		for(int i = 0 ; i < n ; i++){
			int x;
			cin >> x;
			cnt[abs(x)]++;
		}
		int ans = min(cnt[0], 1);
		for(int i = 1 ; i < MAXN ; i++){
			ans += min(cnt[i], 2);
		}
		cout << ans << endl;
	}

    return 0;
}
/*

*/