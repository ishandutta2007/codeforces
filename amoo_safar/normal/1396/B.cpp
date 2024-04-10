// That's How much we have in common
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

ll A[N];
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll T;
	cin >> T;
	for(int i = 0; i < T; i++){
		ll n;
		cin >> n;
		ll sm = 0;
		ll mx = 0;
		for(int j = 1; j <= n; j++){
			cin >> A[j];
			mx = max(mx, A[j]);
			sm += A[j];
		}
		if(mx > sm - mx) cout << "T\n";
		else {
			if(sm % 2 == 0) cout << "HL\n";
			else cout << "T\n";
		}
	}
	return 0;
}