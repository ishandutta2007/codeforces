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

const ll MOD = (ll) 179426549;
const ll MAXN = (ll) 1e3 + 10;
const ll INF = (ll) LONG_LONG_MAX;
const ld EPS = (ld) 1e-8;

map<ll, ll> mp1[MAXN], mp2[MAXN];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n, m;
	cin >> n >> m;
	ll v;
	for(int i = 0; i<n;i++){
		for(int j = 0;j<m;j++){
			cin >> v;
			mp1[i + j][v] ++;
		}
	}
	
	for(int i = 0; i<n;i++){
		for(int j = 0;j<m;j++){
			cin >> v;
			mp2[i + j][v] ++;
		}
	}
	for(int i = 0; i<n+m;i++){
		for(auto x : mp1[i]){
			if(mp2[i][x.F] != x.S){
				return cout << "NO", 0;
			}
		}
	}
	cout << "YES";
	return 0;
}