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

ll n;
vector<pll> V;
ll Sm, ans;

ll foo(ll x){
	ll res = 0;
	for(int i = 1; i <= x; i++){
		res += i * (x + 1 - i);
	}
	return res;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	str s;
	cin >> s;
	ll cnt = 0;

	for(int i = 0; i < n; i++){
		//cerr << "! " << i << '\n';
		if(s[i] == '0'){
			ll p = 0;
			for(int j = i - 1; j >= 0; j--){
				if(s[j] == '0') break;
				p ++;
			}
			for(int j = p; j >= 0; j--){
				V.pb({j, 1});
				Sm += j;
			}
			ans += Sm;
			ans += foo(cnt);
			cnt = 0;

		} else {
			cnt ++;
			ll c2 = 0;
			while(!V.empty()){
				if(V.back().F > cnt) break;
				Sm -= V.back().F * V.back().S;
				c2 += V.back().S;
				V.pop_back();
			}
			Sm += c2 * cnt;
			V.pb({cnt, c2});
			ans += Sm;
		}


	}
	ans += foo(cnt);
	cout << ans << '\n';
	return 0;
}