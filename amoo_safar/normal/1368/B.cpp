// Amsal Shoma Ro Gaedan Ye Amal Pasandidas !
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

ll cnt[N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	str s = "codeforces";
	int m = 10;
	fill(cnt, cnt + 10, 1);
	ll ans = 1;

	ll k;
	cin >> k;
	int p = 0;
	while(ans < k){
		ans /= cnt[p];
		cnt[p] ++;
		ans *= cnt[p];
		p ++;
		if(p == 10) p = 0;
	}
	for(int i = 0; i < 10; i++){
		for(int j =0 ; j < cnt[i]; j++) cout << s[i];
	}
cout << '\n';
	return 0;
}