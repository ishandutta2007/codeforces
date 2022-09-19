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
typedef pair<int, int> pii;

const int Mod = 1000000007LL;
const int N = 2e5 + 10;
const int Log = 30;
const ll Inf = 2242545357980376863LL;

str s[N];

int Main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) cin >> s[i];
	map<str, int> mp;
	for(int _ = 0; _ < 2; _ ++){
		for(int i = 0; i < n; i++){
			str t = s[i];
			reverse(all(t));
			if(s[i] == t) return cout << "YES\n", 0;
			if(mp.count(t)) return cout << "YES\n", 0;

			if(((int) t.size() == 3) && (mp.count(t.substr(0, 2)))) return cout << "YES\n", 0;
			mp[s[i]] = 1;
		}
		mp.clear();
		reverse(s, s + n);
		for(int i = 0; i < n; i++) reverse(all(s[i]));
	}

	cout << "NO\n";
	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc; cin >> tc;
	while(tc --) Main();
	return 0;
}