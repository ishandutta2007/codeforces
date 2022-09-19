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

int mk[N], T = 1;

int Main(){
	int n, m;
	cin >> n >> m;
	// ll S = 0;
	int a, b, c;
	T ++;
	for(int i = 0; i < m; i++){
		cin >> a >> b >> c;
		mk[b]=T;
	}
	int idx = -1;
	for(int i = 1; i <= n; i++) if(T != mk[i]) idx = i;
	for(int i = 1; i <= n; i++)if(idx != i) cout << idx << ' ' << i << '\n';
	// cout << '\n';
	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T = 1;
	cin >> T;
	while(T --) Main();
	return 0;
}