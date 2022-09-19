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
const int N = 4e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;


int a[N];

int Main(){
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	a[0] = a[n + 1] = 0;
	if(n == 1) 
		return cout << a[1] << '\n', 0;
	ll res = 0;
	for(int i = 0; i <= n; i++)
		res += abs(a[i] - a[i + 1]);
	// debug(res);
	for(int i = 1; i <= n; i++){
		if(a[i - 1] < a[i] && a[i + 1] < a[i])
			res -= (a[i] - max(a[i - 1], a[i + 1]));
	}
	cout << res << '\n';
	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T = 1;
	cin >> T;
	while(T --) Main();
	return 0;
}