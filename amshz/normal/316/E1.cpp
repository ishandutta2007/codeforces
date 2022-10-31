# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef double ld;
typedef pair <ll, ll> pii;
 
# define F first
# define S second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e9;
const int xn = 2e5 + 10;
const int xm = 1e6 + 10;
const int SQ = 450;
const int sq = 1e3 + 10;
const ll inf = 1e18 + 10;
 
 
ll power(ll a, ll b){return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));}
ll jaam(ll a, ll b){return (a + b + 10 * md) % md;}
ll menha(ll a, ll b){return (a - b + 10 * md) % md;}
ll zarb(ll a, ll b){return (a * b + 10 * md) % md;}
 

int n, m;
ll Fib[xn], Part[xn], Sum[xn], Ans[xn][2], PS, a[xn];
pii zarib[xn];


void Build(){
	Fib[0] = Fib[1] = 1LL;
	Part[0] = 1LL, Part[1] = 2LL;
	for (int i = 2; i <= n; i ++){
		Fib[i] = (Fib[i - 1] + Fib[i - 2] + 10 * md) % md;
		Part[i] = (Part[i - 1] + Fib[i] + 10 * md) % md;
	}
	zarib[0] = {1, 0};
	zarib[1] = {0, 1};
	for (int i = 2; i <= n; i ++){
		zarib[i].first = (zarib[i - 1].first + zarib[i - 2].first + 10 * md) % md;
		zarib[i].second = (zarib[i - 1].second + zarib[i - 2].second + 10 * md) % md;
	}
	for (int i = 0; i < n; i ++){
		Ans[i / SQ][0] = jaam(Ans[i / SQ][0], zarb(Fib[i % SQ], a[i]));
		Ans[i / SQ][1] = jaam(Ans[i / SQ][1], zarb(Fib[i % SQ + 1], a[i]));
	}
}

ll Find(int ind, ll a, ll b){
	return jaam(zarb(a, zarib[ind].first), zarb(b, zarib[ind].second));
}

void Update1(int ind, ll x){
	Ans[ind / SQ][0] = menha(Ans[ind / SQ][0], zarb(a[ind], Fib[ind % SQ]));
	Ans[ind / SQ][1] = menha(Ans[ind / SQ][1], zarb(a[ind], Fib[ind % SQ + 1]));
	a[ind] = x;
	Ans[ind / SQ][0] = jaam(Ans[ind / SQ][0], zarb(a[ind], Fib[ind % SQ]));
	Ans[ind / SQ][1] = jaam(Ans[ind / SQ][1], zarb(a[ind], Fib[ind % SQ + 1]));
}
void Update2(int l, int r, ll x){
	for (int i = l; i <= r;){
		if (i % SQ == 0 && i + SQ - 1 <= r){
			Sum[i / SQ] = jaam(Sum[i / SQ], x);
			PS = menha(Part[SQ], Part[0]);
			Ans[i / SQ][0] = jaam(Ans[i / SQ][0], zarb(x, Part[SQ - 1]));
			Ans[i / SQ][1] = jaam(Ans[i / SQ][1], zarb(x, PS));
			i += SQ;
		}
		else{
			int ind = i;
			Ans[ind / SQ][0] = menha(Ans[ind / SQ][0], zarb(a[ind], Fib[ind % SQ]));
			Ans[ind / SQ][1] = menha(Ans[ind / SQ][1], zarb(a[ind], Fib[ind % SQ + 1]));
			a[ind] = jaam(a[ind], x);
			Ans[ind / SQ][0] = jaam(Ans[ind / SQ][0], zarb(a[ind], Fib[ind % SQ]));
			Ans[ind / SQ][1] = jaam(Ans[ind / SQ][1], zarb(a[ind], Fib[ind % SQ + 1]));
			i ++;
		}
	}
}

void Get(int l, int r){
	ll ans = 0;
	for (int i = l; i <= r;){
		if (i % SQ == 0 && i + SQ - 1 <= r){
			ans = jaam(ans, Find(i - l, Ans[i / SQ][0], Ans[i / SQ][1]));
			i += SQ;
		}
		else{
			ans = jaam(ans, zarb(Fib[i - l], jaam(a[i], Sum[i / SQ])));
			i ++;
		}
	}
	cout << ans << endl;
}



 
int main(){
	fast_io;
	
	
	cin >> n >> m;
	for (int i = 0; i < n; i ++) cin >> a[i];
	
	Build();
	
	while (m --){
		int l, r, ind, t;
		ll x;
		cin >> t;
		if (t == 1){
			cin >> ind >> x;
			ind --;
			Update1(ind, x);
		}
		if (t == 2){
			cin >> l >> r;
			l --, r --;
			Get(l, r);
		}
		if (t == 3){
			cin >> l >> r >> x;
			l --, r --;
			Update2(l, r, x);
		}
	}
	
	
	return 0;
}