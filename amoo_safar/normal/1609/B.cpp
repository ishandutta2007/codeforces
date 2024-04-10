// Dennis - Toney
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

str s;
int Calc(int i){
	if(i < 0 || s.size() <= i + 2) return 0;
	return s[i] == 'a' && s[i+1] == 'b' && s[i+2] =='c'; 
}
int G(int i){
	return Calc(i) + Calc(i - 1) + Calc(i - 2);
}
int Main(){
	int n, q;
	cin >> n >> q;
	cin >> s;
	int ans = 0;
	for(int  i = 0; i < n; i++) ans += Calc(i);
	for(int i = 0; i < q; i++){
		int d;
		char c;
		cin >> d >> c; d--;
		ans -= G(d);
		s[d] = c;
		ans += G(d);
		cout << ans << '\n';
	}
	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc = 1;
	// cin >> tc;
	while(tc --) Main();
	return 0;
}