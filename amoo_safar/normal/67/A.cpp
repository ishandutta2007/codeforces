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

ll l[N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n;
	cin >> n;
	str s;
	cin >> s;
	l[n - 1] = 1;
	for(int i = n - 2; i >= 0; i--){
		if(s[i] == '=') l[i] = l[i + 1];
		if(s[i] == 'R') l[i] = 1;
		if(s[i] == 'L') l[i] = l[i + 1] + 1;
	}
	//for(int i = 0; i < n; i++) cerr << l[i] << '\n';
	cout << l[0] << ' ';;
	ll la = l[0];
	for(int i = 1; i < n; i++){
		if(s[i - 1] == '='){cout << la << ' '; continue;}
		if(s[i - 1] == 'L'){cout <<  l[i] << ' '; la = l[i]; continue;}
		cout << max(l[i] ,la + 1ll) << ' ';
		la = max(l[i] ,la + 1ll);
	}
	return 0;
}