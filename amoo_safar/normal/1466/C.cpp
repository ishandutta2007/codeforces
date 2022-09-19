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

int dp[N][4];

int Main(){
	int n;
	str s;
	cin >> s;
	s = "!@" + s;
	n = s.size();
	for(int i = 0; i < n; i++) fill(dp[i], dp[i] + 4, n);
	dp[1][0] = 0;
	for(int i = 1; i + 1 < n; i++){
		for(int mk = 0; mk < 4; mk ++){
			int a = mk>>1 & 1;
			int b = mk & 1;
			for(int c = 0; c < 2; c ++){
				if(c == 0 && a == 0 && s[i - 1] == s[i + 1]) continue;
				if(b == 0 && c == 0 && s[i] == s[i + 1]) continue;
				dp[i + 1][b + b + c] = min(dp[i][mk] + c, dp[i + 1][b + b + c]);
			}
		}
	}
	cout << *min_element(dp[n - 1], dp[n - 1] + 4) << '\n';
	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T = 1;
	cin >> T;
	while(T --) Main();
	return 0;
}