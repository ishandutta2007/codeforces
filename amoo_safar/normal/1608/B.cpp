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
typedef pair<int, int> pii;

const int Mod = 1000000007LL;
const int N = 2e5 + 10;
const int Log = 30;
const ll Inf = 2242545357980376863LL;

int ans[N];
int bb[N];

int Main(){
	int n, a, b;
	cin >> n >> a >> b;
	if(a + b > n - 2) return cout << "-1\n", 0;
	if(abs(a - b) > 1) return cout << "-1\n", 0;
	int la = 0;
	bb[0] = +1;

	if(a >= b){
		for(int i = 0, j = 1; i < a; i++, j += 2){
			bb[j] = 1;
			bb[j + 1] = -1;
			la = j + 1;
		}
		if(b == a){
			bb[la + 1] = 1;
			la ++;
		}
	} else {
		for(int i = 0, j = 1; i < b; i++, j += 2){
			// debug(j);
			bb[j] = -1;
			bb[j + 1] = +1;
			la = j + 1;
		}
	}
	for(int i = la + 1; i < n; i++) bb[i] = bb[la];
	ans[0] = 0;
	int r = 1, l = -1, mn = 0;
	for(int i = 1; i < n; i++){
		if(bb[i] == 1){
			ans[i] = r;
			r ++;
		} else {
			ans[i] = l;
			l --;
		}
		mn = min(mn, ans[i]);
	}
	for(int i = 0; i < n; i++) cout << ans[i] - mn + 1 << ' ';

	// for(int i = 2; i <= n + 1; i++) cout << i << ' ';
	cout << '\n';

	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc;
	cin >> tc;
	while(tc --) Main();
	return 0;
}