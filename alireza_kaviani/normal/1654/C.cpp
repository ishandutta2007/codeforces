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

ll q , n , sum , A[MAXN];
map<ll , ll> cnt;

int solve(ll n){
	if(cnt[n]){
		cnt[n]--;
		return 1;
	}
	if(n == 1)	return 0;
	return (solve((n + 1) / 2) && solve(n / 2));
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> q;
	while(q--){
		cin >> n;
		sum = 0; cnt.clear();
		for(int i = 0 ; i < n ; i++){
			cin >> A[i];
			sum += A[i];
			cnt[A[i]]++;
		}
		ll res = solve(sum);
		cout << (res ? "YES" : "NO") << endl;
	}

    return 0;
}
/*

*/