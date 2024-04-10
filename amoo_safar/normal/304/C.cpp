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

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n;
	cin >> n;
	if(n % 2 == 0) return cout << "-1\n", 0;
	for(int i = 0; i < n; i++) cout << i << ' ';
	cout << '\n';
	for(int i = 0; i < n; i++) cout << i << ' ';
	cout << '\n';
	for(int i = 0; i < n; i++) cout << (i+i)%n << ' ';
	cout << '\n';

	return 0;
}