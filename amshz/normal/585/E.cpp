# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef double ld;
typedef pair <int, int> pii;
 
# define F first
# define S second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e9 + 7;
const int xn = 5e5 + 10;
const int xm = 1e7 + 10;
const int Lim = 4e3;
const int SQ = 650;
const int sq = 1e3 + 10;
const ll inf = 1e18 + 10;
 
 
ll power(ll a, ll b){return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));}
 

int a[xn];
ll Tot, n, ans, cnt[xm], ted[xm], Pw[xn], t;
vector <int> adj[xn], Primes;
bool prime[xn];

void fn1(int ind, int pnt, int s, int t){
	if (pnt == adj[ind].size()){
		ted[s] = t;
		cnt[s] ++;
		return;
	}
	fn1(ind, pnt + 1, s * adj[ind][pnt], t + 1);
	fn1(ind, pnt + 1, s, t);
}


void Build(){
	for (int i = 0; i <= n; i ++) Pw[i] = power(2, i);
	for (int i = 2; i <= Lim; i ++){
		if (prime[i]) continue;
		Primes.push_back(i);
		for (int j = i + i; j <= Lim; j += i)
			prime[j] = true;
	}
	for (int i = 0; i < n; i ++){
		int x = a[i];
		for (int j : Primes){
			if (x % j == 0) adj[i].push_back(j);
			while (x % j == 0) x /= j;
		}
		if (x > 1) adj[i].push_back(x);
	}
	for (int i = 0; i < n; i ++)
		fn1(i, 0, 1, 0);
}

void fn2(int ind, int pnt, int s){
	if (pnt == adj[ind].size()){
		if (s == 1) return;
		if (ted[s] % 2 == 1) t = (t + Pw[cnt[s]] - 1 + md) % md;
		else t = (t - Pw[cnt[s]] + 1 + 10 * md) % md;
		return;
	}
	fn2(ind, pnt + 1, s * adj[ind][pnt]);
	fn2(ind, pnt + 1, s);
}
 
int main(){
	fast_io;
	
	cin >> n;
	for (int i = 0; i < n; i ++) cin >> a[i];
	
	Build();
	
	for (int i = 2; i <= 1e7; i ++){
		if (cnt[i] == 0) continue;
		if (ted[i] % 2) Tot = (Tot + Pw[cnt[i]] - 1 + 10 * md) % md;
		else Tot = (Tot - Pw[cnt[i]] + 1 + 10 * md) % md;
	}
	
	for (int i = 0; i < n; i ++){
		t = 0;
		fn2(i, 0, 1);
		ans = (ans + Tot - t + 10 * md) % md;
	}
	
	cout << ans << endl;
	
	return 0;
}