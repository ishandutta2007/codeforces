#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define F first
#define S second
#define debug(x)  cerr << #x << " = " << x << endl
using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ld Pi = 3.14159265359;

const ll MOD = (ll) 998244353ll;
const ll MAXN = (ll) 2e5 + 10;
const ll INF = (ll) 9223372036854775;

ll a[MAXN];
ll b[MAXN];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n, ra;
	cin >> n >> ra;
	for(int i = 0;i<n;i++) cin >> a[i];
	for(int i = 0;i<n;i++) cin >> b[i];
	a[ra - 1] += b[0];
	ll i = 1;
	ll j = n - 1;
	swap(a[0],a[ra-1]);
	sort(a + 1, a + n);
	reverse(a+1,a+n);
	//for(int i = 0;i<n;i++) debug(a[i]);
	for(int k = 1;k<n;k++){
		if(a[k] + b[j] > a[0]){
			a[k] += b[i];
			i++;
		}else{
			a[k] += b[j];
			j--;
		}
	}
	//for(int i = 0;i<n;i++) debug(a[i]);
	ll ran = 1;
	for(int i = 1;i<n;i++){
		if(a[i] > a[0])ran ++;
	}
	cout << ran;
    return 0;

}