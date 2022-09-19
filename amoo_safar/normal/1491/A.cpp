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

int dif[N], a[N];

int sum = 0;
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, q;
	cin >> n >> q;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		sum += a[i];
	}
	for(int i = 1; i <= n; i++){
	}
	int ty, x;
	for(int i = 0; i < q; i++){
		cin >> ty >> x; 
		if(ty == 1){
			sum -= a[x];
			a[x] ^= 1;
			sum += a[x];
		} else {
			cout << (sum >= x ? 1 : 0) << '\n';
		}
	}
	return 0;
}