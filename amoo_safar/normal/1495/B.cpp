// vaziat meshki-ghermeze !
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

int p[N], l[N], r[N], mk[N];
int l2[N], r2[N];

int Main(){

	int n;
	cin >> n;
	for(int i = 0; i < n; i++) cin >> p[i];
	int mx = 0; 
	l[0] = 0;
	for(int i = 1; i < n; i++){
		l[i] = (p[i] < p[i - 1] ? l[i - 1] + 1 : 0);
		mx = max(mx, l[i]);
	}
	r[n - 1] = 0;
	for(int i = n - 2; i >= 0; i--){
		r[i] = (p[i] < p[i + 1] ? r[i + 1] + 1 : 0);
		mx = max(mx, r[i]);
	}
	int cnt = 0;
	l2[0] = 0;
	for(int i = 1; i < n; i++){
		l2[i] = (p[i] > p[i - 1] ? l2[i - 1] + 1 : 0);
		cnt += (l2[i] == mx);
	}
	r2[n - 1] = 0;
	for(int i = n - 2; i >= 0; i--){
		r2[i] = (p[i] > p[i + 1] ? r2[i + 1] + 1 : 0);		
		cnt += (r2[i] == mx);
	}
	// cerr << mx << ' ' << cnt << '\n';
	int ans= 0;
	for(int i = 0; i < n; i++){
		if(min(l2[i], r2[i]) == 0) continue;
		if(l2[i] != r2[i]) continue;
		if(l2[i] % 2 == 1) continue;
		if(l2[i] != mx) continue;
		if(cnt >= 3) continue;
		ans ++;
	}
	cout << ans << '\n';
	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T = 1;
	// cin >> T;
	while(T --) Main();

	return 0;
}