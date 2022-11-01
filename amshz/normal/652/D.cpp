# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair < pair <int, int> , int> ppi;
typedef pair < pair <int, int> , ll> ppll;
typedef pair <ll, ll> pll;
typedef string str;
 
# define endl         '\n'
# define sep         ' '
# define F              first
# define S              second
# define pb             push_back
# define fast_io      ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
const ll md = 1e9+7;

ll gcd(ll a, ll b){
	if (b > a) swap(a, b);
	if (b == 0) return a;
	return gcd(b, a%b);
}
ll lcm(ll a, ll b){
	return a*b/gcd(a, b);
}
ll power(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));
}
 
const int xn = 2e5+10;
const int xm = 5e4+10;
const int SQ = 1000;

ppi a[xn];
int n, s[xn];
vector <ppi> b[xn];

bool cmp(ppi i, ppi j){
	return i.F.S < j.F.S;
}

int fn1(int y, int x){
	int l = -1, r = b[y].size(), mid;
	
	while (r-l > 1){
		mid = (l+r)/2;
		
		if (mid == -1 || b[y][mid].F.S < x) l = mid;
		else r = mid;
	}
	
	return r;
}

int get(int l, int r, int x){
	int ans = 0;
	for (int i = l+1; i <= r;){
		if (i%SQ == 0 && i+SQ-1 <= r){
			ans += fn1(i/SQ, x);
			i += SQ;
		}
		else{
			if (a[i].F.S < x) ans++;
			i++;
		}
	}
	return ans;
}


int main(){
    fast_io;
    
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i].F.F >> a[i].F.S, a[i].S = i;
    
    sort(a, a+n);
    
    for (int i = 0; i < n; i++) b[i/SQ].pb(a[i]);
    
    for (int i = 0; i < n; i++) sort(b[i].begin(), b[i].end(), cmp);
    
    for (int i = 0; i < n; i++){
    	s[a[i].S] = get(i, n-1, a[i].F.S);
	}
	for (int i = 0; i < n; i++) cout << s[i] << endl;
	cout << endl;
    
    return 0;
}