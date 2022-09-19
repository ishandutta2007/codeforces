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

int Main(){
	int n;
	cin >> n;
	ll S = 0;
	int idx = -1;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		S += a[i];
		if(a[i] % 2 == 1) idx = i;
	}
	for(int i = 2; i < S; i++){
		if(S % i == 0){
			cout << n << "\n";
			for(int i = 0; i < n; i++) cout << i + 1 << ' ';
			cout << '\n';
			return 0;
		}
	}
	assert(idx != -1);
	cout << n-1 << "\n";
	for(int i = 1; i <= n; i++)if(idx != i - 1) cout << i << ' ';
	cout << '\n';
	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T = 1;
	cin >> T;
	while(T --) Main();
	return 0;
}