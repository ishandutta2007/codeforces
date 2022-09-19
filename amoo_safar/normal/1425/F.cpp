// That's How much we have in common
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
int main(){
	//ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n;
	cin >> n;
	ll r123, r12, r23;
	
	cout << "? 1 3\n" << flush;
	cin >> r123; 
	cout << "? 1 2\n" << flush;
	cin >> r12; 
	cout << "? 2 3\n" << flush;
	cin >> r23;
	
	a[1] = r123 - r23;
	a[3] = r123 - r12;
	a[2] = r123 - a[1] - a[3];
	for(int i = 4; i <= n; i++){
		cout << "? " << i - 1 << ' ' << i << '\n' << flush;
		ll res; cin >> res;
		a[i] = res - a[i - 1];
	}
	cout << "!";
	for(int i = 1; i <= n; i++) cout << " " << a[i];
	cout << endl;
	return 0;
}