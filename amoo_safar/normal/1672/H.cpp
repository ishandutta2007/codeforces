// Son
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

const ll Mod = 1000000007LL;
const int N = 1e6 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

int p0[N], p1[N];
int Main(){
	int n, q;
	cin >> n >> q;

	str S;
	cin >> S;
	S = "!" + S;
	for(int i = 1; i + 1 <= n; i++){
		p0[i] = (S[i] == '0' && S[i + 1] == '0');
		p1[i] = (S[i] == '1' && S[i + 1] == '1');
	}
	for(int i = 1; i <= n; i++) p0[i] += p0[i - 1];
	for(int i = 1; i <= n; i++) p1[i] += p1[i - 1];
	int l, r;
	for(int i = 0; i < q; i++){
		cin >> l >> r;
		int c0 = p0[r - 1] - p0[l - 1];
		int c1 = p1[r - 1] - p1[l - 1];
		cout << max(c0, c1) + 1 << '\n';
	}
	return 0;
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc = 1;
	// cin >> tc;
	while(tc --) Main();
	return 0;
}