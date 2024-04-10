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


vector<ll> A, B;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll T;
	cin >> T;
	for(int i = 0; i < T;i++){
		A.clear();
		B.clear();
		ll n;
		cin >> n;
		ll v;
		for(int j = 0; j <n ;j++){
			cin >> v;
			A.pb(v);
		}
		for(int j = 0; j <n ;j++){
			cin >> v;
			B.pb(v);
		}
		sort(all(A));
		sort(all(B));
		for(auto x : A) cout << x << ' ';
			cout << '\n';
		for(auto x : B) cout << x << ' ';
			cout << '\n';
			
	}
	return 0;
}