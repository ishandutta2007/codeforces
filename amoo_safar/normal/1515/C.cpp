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
const int N = 3e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;


int Main(){
	set<pll> S;
	int n, m, x;
	cin >> n >> m >> x;
	for(int i = 1; i <= m; i++) S.insert({0, i});
	cout << "YES\n";
	for(int i = 1; i <= n; i++){
		ll v;
		cin >> v;
		pll fr = *S.begin();
		S.erase(S.begin());
		fr.F += v;
		S.insert(fr);
		cout << fr.S << " \n"[i == n];
	}
	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc = 1;
	cin >> tc;
	while(tc --) Main();
	return 0;
}