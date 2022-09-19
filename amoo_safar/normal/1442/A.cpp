// nemibinam invara kasi mesle khodemono !
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

ll a[N];
void Main(){
	ll n;
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	ll sm = 0;
	ll s = 0;
	for(int i = 0; i < n; i++) sm += a[i];
	for(int i = 0; i + 1 < n; i++){
		if(a[i] > a[i + 1]){
			s += 1ll * (i + 1) * (a[i] - a[i + 1]);
		} else {
			s += 1ll * (n - 1 - i) * (a[i + 1] - a[i]);
		}
	}
	if(s > sm) cout << "No\n";
	else cout << "Yes\n";
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll T;
	cin >> T;
	while(T --) Main();

	return 0;
}