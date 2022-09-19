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
const int N = 3e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

int n, a[N], ans[N];
int m1[N], m2[N];
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i + 1 < n; i++) m1[i] = max(a[i], a[i + 1]);
	for(int i = 1; i + 1 < n; i++) m2[i] = max(min(a[i - 1], a[i]), min(a[i], a[i + 1]));
	int l, r;
	l = (n - 1) / 2; r = (n - 1) / 2;
	if(n & 1) swap(m1, m2);
	ans[0] = m1[l];
	for(int i = 2; i < n - 2; i += 2) ans[i] = max({ans[i - 2], m1[-- l], m1[++ r]});
	l = n / 2 - 1; r = n / 2;
	ans[1] = max(m2[l], m2[r]);
	for(int i = 3; i < n - 2; i += 2) ans[i] = max({ans[i - 2], m2[-- l], m2[++ r]});
	ans[n - 1] = *max_element(a, a + n);
	ans[n - 2] = ans[n - 1];
	for(int i = 0; i < n; i++) cout << ans[i] << ' ';
	cout << '\n';
	return 0;
}