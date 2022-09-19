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


int c[2];
int Main(){
	int n, m;
	cin >> n >> m;
	c[0] = c[1] = 0;
	for(int i = 0; i < n; i++){
		str S;
		cin >> S;
		for(int j = 0; j < m; j++){
			if(S[j] == '.') continue;
			int v = (S[j] == 'R' ? 0 : 1);
			c[(v + i + j) % 2] ++;
		}
	}
	// cerr << c[0] << ' ' << c[1] << '\n';
	if(min(c[0],c[1]) > 0)
		return cout << "NO\n", 0;
	cout << "YES\n";
	int gd = (c[0] == 0 ? 0 : 1);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cout << "WR"[gd ^ ((i + j) & 1)];
		}
		cout << '\n';
	}
	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T = 1;
	cin >> T;
	while(T --) Main();
	return 0;
}