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

const ll MAXN = 2e5 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

ll n , res , A[MAXN] , cnt[MAXN * 2] , ans[MAXN];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n;
	for(int i = 1 ; i <= n ; i++){
		cin >> A[i];
		cnt[A[i]]++;
	}
	partial_sum(cnt , cnt + MAXN * 2 , cnt);
	for(int i = 1 ; i < MAXN ; i++){
		for(int j = i ; j < MAXN ; j += i){
			ans[i] += (cnt[j + i - 1] - cnt[j - 1]) * j;
		}
	}
	for(int i = 1 ; i <= n ; i++){
		res = max(res , ans[A[i]]);
	}
	cout << res << endl;

    return 0;
}
/*

*/