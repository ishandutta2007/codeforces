// Amsal Shoma Ro Gaedan Ye Amal Pasandidas !
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

ll cnt[N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n;
	ll v;
	cin >> n;
	for(int  i = 0; i < n; i++){
		cin >> v;
		cnt[v] ++;
	}
	ll ans = 0;
	for(int i = 0; i < n + n + 3; i++){
		if(cnt[i]){
			cnt[i + 1] += cnt[i] - 1;
			ans += cnt[i] - 1;
		}
	}
	cout << ans << '\n';
	return 0;
}