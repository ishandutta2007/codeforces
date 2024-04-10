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
const ll MAXN = (ll) 1e5 + 10;
const ll INF = (ll) 1e15 + 1;

pll a[MAXN];
ll b[MAXN];
ll out[MAXN];

int main(){
    
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n;
    cin >> n;
    for(int i = 0;i<n;i++){
		cin >> a[i].F ;
		b[i] = a[i].F;
		a[i].S = i;
	}
	sort(a, a+n);
	reverse(a,a+n);
	ll ind, fl;
	for(int i = 0;i<n;i++){
		ind = a[i].S;
		fl = 0;
		for(int j = ind + a[i].F; j < n; j += a[i].F){
			if((b[j] > a[i].F) and (out[j] == 0)) fl = 1;
		}
		for(int j = ind - a[i].F; j >= 0; j -= a[i].F){
			if((b[j] > a[i].F) and (out[j] == 0)) fl = 1;
		}
		out[a[i].S] = fl;
	}
	for(int i =0;i<n;i++){
		if(out[i] == 1) cout << "A";
		else cout << "B";
	}
	return 0;
}