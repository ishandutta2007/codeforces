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

vector<ll> A, B;
ll a[N];
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n;
	cin >> n;
	ll s = 0;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		s += a[i];
	}

	if(s % n != 0) return cout << "Unrecoverable configuration.\n", 0;
	ll d = s/n;
	for(int i = 1; i <= n; i++){
		if(a[i] < d) A.pb(i);
		if(a[i] > d) B.pb(i);
	}
	if(A.size() + B.size() == 0) return cout << "Exemplary pages.\n", 0;
	
	if(A.size() != 1 || B.size() != 1) return cout << "Unrecoverable configuration.\n", 0;
	cout << a[B[0]] - d << " ml. from cup #" << A[0] << " to cup #" << B[0] << ".\n";
	return 0;
}