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

const ll MAXN = 1024;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int n , k , x , cnt[MAXN] , cnt2[MAXN];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n >> k >> x;
	for(int i = 0 ; i < n ; i++){
		int A; cin >> A;
		cnt[A]++;
	}
	for(int i = 0 ; i < k ; i++){
		fill(cnt2 , cnt2 + MAXN , 0);
		int cur = 1;
		for(int j = 0 ; j < MAXN ; j++){
			int v = (cnt[j] + cur) / 2 , u = cnt[j] - v;
			cnt2[j] += u;
			cnt2[(j ^ x)] += v;
			cur = (cur ^ cnt[j]) % 2;
		}
		for(int j = 0 ; j < MAXN ; j++){
			cnt[j] = cnt2[j];
		}
	}
	int mn = MAXN , mx = 0;
	for(int i = 0 ; i < MAXN ; i++){
		if(cnt[i]){
			mn = min(mn , i);
			mx = max(mx , i);
		}
	}
	cout << mx << sep << mn << endl;

    return 0;
}
/*

*/