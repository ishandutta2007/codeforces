// I'll Crush you !
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

ll a[N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n;
	cin >> n;
	for(int i = 1; i <=n; i++) cin >> a[i];
	bool fl = false;
	for(int i = 1; i <= n; i++) if(a[i] != 0) fl =true;
	if(!fl) return cout << "0\n", 0;
	vector<int> V;
	vector<pll> A;

	int mx = 0, idx = n + 1;
	for(int i = n; i > 0; i--){
		if(a[i] == 0) continue;
		if(a[i] == 1){
			V.pb(i);
			A.pb({i, i});
		}
		if(a[i] == 2){
			if(V.empty()) return cout << "-1\n", 0;
			int la = V.back();
			V.pop_back();
			A.pb({la, i});
		}
		if(a[i] == 3){
			//cout << '!' << mx << ' ' << idx << ' ' << i << '\n';
			if(mx == 0) return cout << "-1\n", 0;
			if(mx == 1){
				int la = V.back();
				V.pop_back();
				A.pb({i, i});
				A.pb({i, la});
			}
			if(mx >= 2){
				A.pb({i, i});
				A.pb({i, idx});	
			}
		}
		mx = max((ll)mx, a[i]);
		if(a[i] == mx) idx = i;
	}


	cout << A.size() << '\n';
	for(auto x : A) cout << x.F << ' ' << x.S << '\n'; 
	return 0;
}