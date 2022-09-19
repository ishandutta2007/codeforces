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

ll a[4][4], o[4][4], s[4][4];

int Main(){
	int n, k;
	cin >> n >> k;
	vector<int> V;
	for(int i = 1; i <= 3; i++){
		for(int j = i + 1; j <= 3; j++){
			cout << "and " <<  i << ' ' << j << endl;
			cin >> a[i][j];
			cout << "or " <<  i << ' ' << j << endl;
			cin >> o[i][j];
			s[i][j] = o[i][j] + a[i][j];
		}
	}
	V.pb((s[1][2] + s[2][3] - s[1][3])/ 2);
	V.pb(s[1][2] - V[0]);
	V.pb(s[2][3] - V[0]);
	for(int j = 4; j <= n; j++){
		ll aa, b, c = 0;
		cout << "and 1 " << j << endl;
		cin >> aa;
		cout << "or 1 " << j << endl;
		cin >> b;
		V.pb(aa + b - V[1]);
	}
	sort(all(V));
	cout << "finish " << V[k - 1] << endl;

	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc = 1;
	// cin >> tc;
	while(tc --) Main();
	return 0;
}