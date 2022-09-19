// har ki ro didi goft mikhad beshe meslemon !
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
int ps[N];
int Main(){
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	reverse(a + 1, a + n + 1);
	ps[1] = 0;
	for(int i = 2; i <= n + 1; i++) ps[i] = ps[i - 1] ^ a[i - 1];
	for(int i = 1; i + 2 <= n; i++){
		if((a[i] ^ a[i + 1]) < a[i + 2])
			return cout << "1\n", 0;
	}
	//debug("S");
	int ans = n;
	for(int i = 1; i <= n + 1; i++){
		for(int j = i + 1; j <= n + 1; j++){
			for(int k = j + 1; k <= n + 1; k++){
				if((ps[j] ^ ps[i]) < (ps[k] ^ ps[j]))
					ans = min(ans, k - i - 2);
			}
		}
	}
	cout << (ans == n ? -1 : ans) << '\n';
	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T;
	T = 1;
	// cin >> T;
	for(int i = 0; i < T; i++){
		Main();
	}
	return 0;
}