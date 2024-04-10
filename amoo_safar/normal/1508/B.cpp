// faz lati nemigire bache shir !
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
const ll Inf = 2'000'000'000'000'000'000ll;
const ll Log = 30;

ll pw[N];

void Solve(ll n, ll k, ll st){
	if(n == 0){
		cout << "\n";
		return ;
	}
	for(int i = 1; i <= n; i++){
		if(k <= pw[n - i]){
			for(int j = i; j >= 1; j--) cout << j + st << ' ';
			Solve(n - i, k, st + i);
			return ;
		} else {
			k -= pw[n - i];
		}
	}
}

int Main(){
	ll n, k;
	cin >> n >> k;
	// cerr << "!! " << n << ' ' << k << '\n';
	if(k > pw[n]){
		cout << "-1\n";
		return 0;
	}
	Solve(n, k, 0);
	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	pw[0] = 1;
	pw[1] = 1;
	for(int i = 2; i < N; i++) pw[i] = min(Inf, pw[i-1] + pw[i-1]);
	int T = 1;
	cin >> T;
	while(T --) Main();
	return 0;
}