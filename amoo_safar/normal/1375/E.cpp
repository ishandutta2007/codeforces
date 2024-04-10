// Amsal Shoma Ro Gaedan Ye Amal Pasandidas !
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
ll b[N], c[N];
vector<pll> V;
int main(){
	ll n;
	scanf("%lld", &n);
	for(int i = 1; i <= n; i++){
		scanf("%lld", a + i);
		V.pb({a[i], i});
	}
	sort(all(V));
	for(int i = 0; i < n; i++){
		b[i + 1] = V[i].S;
	}
	ll cnt = 0;
	for(int i = 1;  i<= n; i++) for(int j = 1; j < i; j++){
		if(a[j] > a[i]) cnt ++;
	}
	cout << cnt << '\n';
	for(int i = 1; i <= n; i++){
		for(int j = i - 1; j >= 1; j--){
			if(b[j] > b[j + 1]){
				printf("%lld %lld\n", b[j + 1], b[j]);
				//cout << b[j + 1] << ' ' << b[j] << '\n';
				swap(b[j], b[j + 1]);
			} else {
				break;
			}
		}
	}
	return 0;
}