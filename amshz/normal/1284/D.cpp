# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
 
# define F first
# define S second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e9+7;
const int xn = 2e5 + 10;
const int xm = 5e5;
const int SQ = 320;
const int sq = 1e3 + 10;
const int inf = 1e9 + 10;
 
 
ll power(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));
}
 

int n, b[xn], c[xn];
pair <pii, pii> a[xn];
bool flag;



void Build(){
	for (int i = 0; i < n; i ++) b[i] = inf, c[i] = 0;
	for (int i = 0; i < n; i ++){
		b[i / SQ] = min(b[i / SQ], a[i].S.S);
		c[i / SQ] = max(c[i / SQ], a[i].S.F);
	}
}

int Get1(int l, int r){
	int mn = inf;
	for (int i = l; i <= r;){
		if (i % SQ == 0 && i + SQ - 1 <= r) mn = min(mn, b[i / SQ]), i += SQ;
		else mn = min(mn, a[i].S.S), i ++;
	}
	return mn;
}
int Get2(int l, int r){
	int mx = 0;
	for (int i = l; i <= r;){
		if (i % SQ == 0 && i + SQ - 1 <= r) mx = max(mx, c[i / SQ]), i += SQ;
		else mx = max(mx, a[i].S.F), i ++;
	}
	return mx;
}


bool cmp(pair <pii, pii> i, pair <pii, pii> j){
	return i.F.S < j.F.S;
}
 
 
void Main(){

	Build();
	
	for (int i = 0; i < n; i ++){
		int x = a[i].F.F;
		int L = -1, R = i, Mid;
		while (R - L > 1){
			Mid = (L + R) / 2;
			if (a[Mid].F.S < x) L = Mid;
			else R = Mid;
		}
		int mn = Get1(L + 1, i - 1);
		int mx = Get2(L + 1, i - 1);
		if (mx > a[i].S.S || mn < a[i].S.F) flag = true;
	}
}

int main(){
	fast_io;
	
	cin >> n;
	for (int i = 0; i < n; i ++) cin >> a[i].F.F >> a[i].F.S >> a[i].S.F >> a[i].S.S;
	sort(a, a + n, cmp);
	
	Main();
	
	for (int i = 0; i < n; i ++) swap(a[i].F.F, a[i].S.F), swap(a[i].F.S, a[i].S.S);
	sort(a, a + n, cmp);
	
	Main();
	
	if (flag) cout << "NO" << endl;
	else cout << "YES" << endl;
	return 0;
}