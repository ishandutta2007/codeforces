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

int Main(){
	map<int, int> L, R;
	map<pii, int> LR;
	int n;
	cin >> n;
	int l, r, c;
	int oo = 2'000'000'001;
	int mx = -1, mn = oo;
	for(int i = 0; i < n; i++){
		cin >> l >> r >> c;
		mx = max(mx, r); mn = min(mn, l);

		if(L.count(l) == 0) L[l] = c;
		L[l] = min(L[l], c);
		if(R.count(r) == 0) R[r] = c;
		R[r] = min(R[r], c);
		if(LR.count({l, r}) == 0) LR[{l, r}] = c;
		LR[{l, r}] = min(LR[{l, r}], c);
		cout << min(L[mn] + R[mx], LR.count({mn, mx}) ? LR[{mn, mx}] : oo) << '\n';
	}
	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc;
	cin >> tc;
	while(tc --) Main();
	return 0;
}