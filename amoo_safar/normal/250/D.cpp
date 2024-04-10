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

ld ans = 1e9;
ll x1, x2;
ll n, m, a, b;

ll A[N], B[N], l[N];


void check(ll i, ll j){
	if(i <= 0 || i > n) return ;
	ld res = l[j];
	res += sqrt(A[i]*A[i] + a*a);
	res += sqrt((b-a)*(b-a) + (B[j] - A[i])*(B[j] - A[i]));
	if(res < ans){
		ans = res;
		x1 = i;
		x2 = j;
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> a >> b;
	for(int i = 1; i <= n; i++) cin >> A[i];
	sort(A + 1, A + n + 1);
	for(int i = 1; i <= m; i++) cin >> B[i];
	for(int i = 1; i <= m; i++) cin >> l[i];
	for(int i = 1; i <= m; i++){
		ll wh = lower_bound(A + 1, A + n + 1, a*(((ld) B[i]) / b)) - A;
		check(wh, i);
		check(wh-1, i);
	}
	cout << x1 << " " << x2 << '\n';
	return 0;
}