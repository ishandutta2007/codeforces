#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ll Mod = 1000000007LL;
const int N = 2e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

ll b[N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, k;
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> b[i];
	for(int i = 1; i <= n; i++){
		ll idx = -1;
		for(int j = n; j >= 1; j--) if(b[j] == 0) idx = j;
		cout << idx << ' ';
		b[idx] --;
		for(int i = 1; i <= idx - k; i++) b[i] --;
	}
	return 0;
}