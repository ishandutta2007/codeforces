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

int Main(){
	str s, t;
	cin >> s >> t;
	reverse(all(s));
	reverse(all(t));
	int rm = 0;
	int p = 0;
	for(auto x : s){
		if(p == (int) t.size()) break;
		if(x != t[p]){
			rm ++;
			continue;
		}
		if(rm % 2 == 1){
			rm ++;
			continue;
		}
		p ++;
	}
	cout << (p == (int) t.size() ? "YES\n" : "NO\n");
	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc;
	cin >> tc;
	while(tc --) Main();
	return 0;
}