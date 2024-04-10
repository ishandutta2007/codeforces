// Null
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

ll n;
str a, b;
vector<ll> V;

void Move(ll x){
	V.pb(x);
}

void Not(int i){
	if(a[i] == '0') a[i] = '1';
	else a[i] = '0';
}
void Main(){
	cin >> n >> a >> b;
	V.clear();
	int l = 0, r = n - 1;
	int X = 0, nw2;
	for(int i = n - 1; i >= 0; i--){
		int nw = a[r] - '0';
		nw ^= X;
		if(nw == (b[i] - '0')){
			if(r >= l) r--;
			else r ++;
			continue;
		}
		nw2 = a[l] - '0';
		nw2 ^= X;
		if(nw2 == (b[i]-'0')){
			Move(1);
			Not(l);
		}
		swap(l, r);
		
		if(r >= l) r--;
		else r ++;
		X ^= 1;

		Move(i + 1);
	}
	cout << V.size();
	for(auto x : V) cout << ' ' << x;
	cout << '\n';
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll T;
	cin >> T;
	while(T --) Main();
	return 0;
}