// I'll Crush you !
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
	ll n;
	str s;
	cin >> s;
	n = s.size();
	int ans = 0;
	int sm = 0;
	for(int i =  n - 1; i >= 0; i--){
		if(s[i] == 'B') sm ++;
		else {
			if(sm > 0){
				sm --;
				ans ++;
			}
		}
	}
	ans += sm / 2;
	cout << n - (ans*2) << '\n';
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll T;
	cin >> T;
	while(T --) Main();
	return 0;
}