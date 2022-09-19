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

int Main(){
	map<ll, ll> mp;
	ll n;
	cin >> n;
	str s;
	cin >> s;
	if(n == 1) return cout << s + s << '\n', 0;
	if(s[0] == s[1]) return cout << s[0] << s[0] << '\n', 0;
	for(int i = 1; i < n; i++){
		if(s[i] > s[i - 1]){
			str t = s.substr(0, i);
			reverse(all(t));
			cout << s.substr(0, i) + t << '\n';
			return 0;
		}
	}
	str t = s;
	reverse(all(t));
	cout << s + t << '\n';
			
	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc = 1;
	cin >> tc;
	while(tc --) Main();
	return 0;
}