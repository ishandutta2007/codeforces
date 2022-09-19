// nemibinam invara kasi mesle khodemono !
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

int cnt[N], a[N];

int fs[N + N], mk[N + N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	int mx = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		cnt[a[i]] ++;
		mx = max(mx, cnt[a[i]]);
	}
	int c = 0, la = 0;
	for(int i = 1; i <= n; i++){
		if(cnt[i] == mx) c++, la = i;
	}
	if(c >= 2) return cout << n << '\n', 0;
	int ans = 0;
	for(int q = 1; q <= 100; q++){
		if(q == la) continue;
		int sm = n;
		fs[sm] = 0;
		mk[sm] = q;
		for(int i = 1; i <= n; i++){
			if(a[i - 1] == la) sm --;
			if(a[i - 1] == q) sm ++;
			if(mk[sm] == q){
				ans = max(ans, i - fs[sm]);
			} else {
				mk[sm] = q;
				fs[sm] = i;
			}
		}
	}
	cout << ans << '\n';
	return 0;
}