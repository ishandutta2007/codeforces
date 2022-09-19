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

ll a[N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll T;
	cin >> T;
	while(T --){
		ll n, m;
		cin >> n >> m;
		ll fl = 1;
		ll adj;
		for(int i = 0; i < n; i++){
			ll v;
			for(int j = 0; j < m; j++){
				cin >> v;
				adj = 4;;
				if(i == 0) adj --;
				if(i == n - 1) adj --;
				if(j == 0) adj --;
				if(j == m - 1) adj --;
				if(adj < v) fl = 0;
			}
		}
		if(fl == 0){
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
		for(int i = 0; i < n; i++){
			ll v;
			for(int j = 0; j < m; j++){
				adj = 4;
				if(i == 0) adj --;
				if(i == n - 1) adj --;
				if(j == 0) adj --;
				if(j == m - 1) adj --;
				
				cout << adj << ' ';
			}
			cout << '\n';
		}
	}
	return 0;
}