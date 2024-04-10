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


vector<ll> V;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	str s;
	cin >> s;
	ll n = s.size();

	ll p0 = 0;
	ll p1 = n - 1;
	while(p0 <= p1){
		//cerr << p0 << " " << p1 << '\n';
		if(s[p0] == ')'){
			//V.pb(p0);
			p0 ++;
			continue;
		}

		if(s[p1] == '('){
			//V.pb(p1);
			p1--;
			continue;
		}
		V.pb(p0);
		V.pb(p1);
		p0++;
		p1--;
	}
	sort(all(V));
	if(V.size()){
		cout << "1\n" << V.size() << '\n';
		for(auto x : V) cout << x + 1 << ' ' ;

	}else cout << "0\n";
	return 0;
}