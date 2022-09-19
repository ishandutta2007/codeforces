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
const int N = 1e6 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

int mk[N], T = 1;
int ans[N];
int Main(){
	int n, m;
	cin >> n >> m;
	char c;
	vector<vector<char>> V(n, vector<char>(m, 0));
	for(int i = 0; i < n; i++){
		str s;
		cin >> s;
		for(int j = 0; j < m; j ++){
			// scanf("%c", &c);
			c = s[j];
			if((c == 'X') && (j + 1 < m) && (i > 0) && (V[i - 1][j + 1] == 'X'))
				mk[j] = 1;
			// cerr << c << '\n';
			V[i][j] = c;
		}
	}
	ans[m - 1] = m - 1;
	for(int i = m - 2; i >= 0; i--){
		ans[i] = (mk[i] ? i : ans[i + 1]);
	}
	int q;
	cin >> q;
	// scanf("%d", &q);
	int l, r;
	for(int i =0 ; i <  q;i++){
		// scanf("%d%d", &l, &r); l--; r--;
		cin >>l >> r;l--; r--;
		// debug(ans[l]);
		cout << (r <= ans[l] ? "Yes\n" : "No\n" ); 
	}
	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T = 1;
	// cin >> T;
	while(T --) Main();
	return 0;
}