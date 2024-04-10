// Null
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

ll cnt[30][30];

void Main(){
	ll n;
	cin >> n;

	str a, b;
	cin >> a >> b;
	memset(cnt, 0, sizeof cnt);
	for(int i = 0; i < n; i++){
		if(a[i] > b[i]){
			cout << "-1\n";
			return ;
		}
		if(a[i] == b[i]) continue;
		cnt[a[i] - 'a'][b[i] - 'a'] ++;
	
	}
	ll sig = 20, ans = 0;
	for(int i = 0; i < sig; i++){
		ll idx = -1;
		for(int j = i + 1; j < sig; j++){
			if(cnt[i][j]){
				idx = j;
				break;
			}
		}
		if(idx == -1) continue;
		for(int j = i + 1; j < sig; j++){
			cnt[idx][j] += cnt[i][j];
		}
		ans ++;
	}
	cout << ans << '\n';
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll T;
	cin >> T;
	while(T --) Main();
	return 0;
}