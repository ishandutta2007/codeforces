#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define PF push_front
#define MP make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, ll> pii;
const int maxn = 1e5 + 100;

ll a[maxn];

bool perfect(ll x){
	ll y = sqrt(x);
	if (y * y == x)
		return 1;
	return 0;
}

int main(){
	ios_base::sync_with_stdio(false);
	ll n;
	cin >> n;
	for (int i = 2; i <= n; i += 2)
		cin >> a[i];
	
	ll N = 1000 * 1000;
	ll last = 0;
	for (int i = 1; i <= n; i += 2){
		for (ll j = last + 1; j <= N; j++){
			ll x = j * j - last * last;
			if (perfect(last * last + x + a[i + 1])){
				a[i] = x;
				last = sqrt(last * last + x + a[i + 1]);
				break;
			}
		}
		if (a[i] == 0)
			return cout << "No" << endl, 0;
	}
	cout << "Yes" << endl;
	for (int i = 1; i <= n; i++)
		cout << a[i] << " ";
	cout << endl;
}