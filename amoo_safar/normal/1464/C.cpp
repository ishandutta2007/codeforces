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

ll Get(char c){
	int id = c - 'a';
	return 1ll << id;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	str s;
	ll T;
	int n;
	cin >> n >> T;

	cin >> s;
	vector<ll> V;
	// int n = s.size();
	T -= Get(s[n - 1]);
	T += Get(s[n - 2]);

	for(int i = 0; i < n - 2; i++){
		V.pb(2ll * Get(s[i]));
		T += Get(s[i]);
	}
	sort(all(V));
	reverse(all(V));
	for(auto x : V){
		if(T >= x) T -= x;
	}
	cout << (T == 0 ? "Yes\n" : "No\n");
	return 0;
}