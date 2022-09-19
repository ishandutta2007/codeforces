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
	int n;
	cin >> n;
	map<int, int> mp, c[2];
	
	int x;
	for(int i = 0; i < n; i++){
		cin >> x;
		mp[x] ++;
		c[i & 1][x] ++;
	}
	int sm = 0;
	int r[2];
	for(auto [v, cn] : mp){
		r[sm & 1] = (cn + 1) / 2;
		r[(sm & 1) ^ 1] = (cn) / 2;
		if((c[0][v] != r[0]) || (c[1][v] != r[1]))
			return cout << "NO\n", 0;
		sm += cn;
	}
	cout << "YES\n";
	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while(T--) Main();
	return 0;
}