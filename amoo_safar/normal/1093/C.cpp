#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x)  cerr << #x << " = " << x << endl
using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ld PI = 3.14159265359;

const ll MOD = (ll) 998244353ll;
const ll MAXN = (ll) 2e5 + 10;
const ll INF = (ll) 2242545357980376863;
const ld EPS = (ld) 1e-8;

ll a[MAXN], b[MAXN];

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;
    cin >> n;
    for(int i = 0 ;i<n/2; i++) cin >> b[i];
    ll j = n - 2;
    a[0] = 0;
    a[n-1] = b[0];
	for(int i = 1 ; i<n/2;i++){
		if(b[i] - a[i - 1] <= a[j + 1]){
			//debug(i);
			a[i] = a[i - 1];
			a[j] = b[i] - a[i];
		} else {
			a[j] = a[j + 1];
			a[i] = b[i] - a[j];
		}
		j--;
	}
    
    for(int i = 0; i<n;i++) cout << a[i] << " ";
	return 0;
}