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

int Main(){
	int ans = 10;
	str p;
	cin >> p;
	int p1 = 0, r1 = 5, p2 = 0, r2 = 5;
	for(int i = 0; i < 10; i++){
		if(i % 2 == 0){
			r1 --;
			if(p[i] == '1' || p[i] == '?') p1 ++;
		}
		if(i % 2 == 1){
			r2 --;
			if(p[i] == '1') p2 ++;
		}
		if(p1 + r1 < p2 || p2 + r2 < p1) ans = min(ans, i + 1);
	}
	p1 = 0, r1 = 5, p2 = 0, r2 = 5;
	for(int i = 0; i < 10; i++){
		if(i % 2 == 0){
			r1 --;
			if(p[i] == '1') p1 ++;
		}
		if(i % 2 == 1){
			r2 --;
			if(p[i] == '1' || p[i] == '?') p2 ++;
		}
		if(p1 + r1 < p2 || p2 + r2 < p1) ans = min(ans, i + 1);
	}

	cout << ans << '\n';
	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc;
	cin >> tc;
	while(tc --) Main();
	return 0;
}