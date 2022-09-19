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
const int N = 3e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

ll n, a[N], cnt[N];

ll mex(){
	ll mx = 0;
	for(int i = 0; i <= n; i++) cnt[i] = 0;
	for(int i = 1; i <= n; i++) cnt[a[i]] ++;
	for(int i = 0; i <= n; i++) if(cnt[i] == 0) return i;
	return -1;
}
ll idx(){
	for(int i = 1; i <= n; i++) if(a[i] != i) return i;
	return -1;
}
void Main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	vector<ll> ans;

	while(true){
		ll j = idx();
		//debug(j);
		if(j == -1) break;
		ll M = mex();
		if(M == 0){
			ans.pb(j);
			a[j] = M;
		} else {
			ans.pb(M);
			a[M] = M;
		}
	}
	cout << ans.size() << '\n';
	for(auto x : ans){
		cout<< x << ' '; 
	}
	cout << '\n';
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll T;
	cin >> T;
	while(T --) Main();

	return 0;
}