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
const int N = 3e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

ll a[N];
void Main(){
	vector< pair<pair<int, int>, ll> > A;
	ll n;
	cin >> n;

	ll sm = 0;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		sm += a[i];
	}
	if(sm % n != 0){
		cout << "-1\n";
		return ;
	}
	ll X = sm / n;
	for(int i = 2; i <= n; i++){
		ll rq = (i - (a[i] % i)) % i;
		assert(a[1] >= rq);
		
		A.pb({{1, i}, rq});
		a[i] += rq;
		a[1] -= rq;

		ll d = a[i] / i;
		A.pb({{i, 1}, d});
		a[i] -= d * i;
		a[1] += d * i;
	}
	for(int i = 2; i <= n; i++){
		A.pb({{1, i}, X});
	}
	cout << A.size() << '\n';
	for(auto el : A)
		cout << el.F.F << ' ' << el.F.S << ' ' << el.S << '\n';
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll T;
	cin >> T;
	while(T --) Main();
	return 0;
}