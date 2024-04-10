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
const int N = 1e6 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;


int pr[N];
int n, e;
ll a[N], b[N], c[N], d[N];
ll Calc(){
	ll res = 0;
	for(int i = n - 1; i>=0;i--){
		c[i] = 1;
		if(i + e < n && a[i+e]==1)
			c[i] = 1 + c[i + e];
	}
	for(int i = 0; i<n;i++){
		d[i] = 1;
		if(i - e >= 0 && a[i-e]==1)
			d[i] = 1 + d[i - e];
		if(a[i] > 1 && pr[a[i]] == 0)
			res += 1ll * c[i] * d[i] - 1ll;
		
	}
	return res;
}

int Main(){
	cin >> n >> e;
	ll ans = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		b[i] = ((a[i] == 1) || (pr[a[i]] == 0));
		// debug(b[i]);
	}
	ans = Calc();
	cout << ans << '\n';
	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for(int i = 2; i < N; i++)
		if(pr[i] == 0)
			for(int j = i + i; j < N; j += i)
				pr[j] = 1;
	int tc = 1;
	cin >> tc;
	while(tc --) Main();
	return 0;
}
/*
1
7 3
10 2 1 3 1 19 3

*/