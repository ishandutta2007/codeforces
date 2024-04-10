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

int a[N];

vector<pair<int, pll> > V;
void Add(int x){
	V.pb({1, {x, x + 1}});
	V.pb({2, {x, x + 1}});
	V.pb({1, {x, x + 1}});
}

int Main(){
	V.clear();
	int n;
	cin >> n;
	int v;
	for(int i = 0; i < n; i++) cin >> v;
	for(int i = 1; i <= n; i += 2){
		Add(i);
		Add(i);
	}
	cout << V.size() << '\n';
	for(auto [x, y] : V) cout << x << ' ' << y.F << ' ' <<y.S << '\n';
	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T = 1;
	cin >> T;
	while(T --) Main();
	return 0;
}