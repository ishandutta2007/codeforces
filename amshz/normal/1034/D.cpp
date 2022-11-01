//khodaya khodet komak kon
# include <bits/stdc++.h>

using namespace std;

typedef long long                                        ll;
typedef long double                                      ld;
typedef pair <int, int>                                  pii;
typedef pair <pii, int>                                  ppi;
typedef pair <int, pii>                                  pip;
typedef pair <pii, pii>                                  ppp;
typedef pair <ll, ll>                                    pll;

# define A                                               first
# define B                                               second
# define endl                                            '\n'
# define sep                                             ' '
# define all(x)                                          x.begin(), x.end()
# define kill(x)                                         return cout << x << endl, 0
# define SZ(x)                                           int(x.size())
# define lc                                              id << 1
# define rc                                              id << 1 | 1
# define fast_io                                         ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);

ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}

const int xn = 3e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 1e9 + 7;//998244353;
const int base = 257;

int n, k, a[xn], b[xn], c[xn], ptr;
ll cnt, cn, sum, sm;
vector <pii> vec[xn];
set <ppi> st;
 
void build(){
	for (int i = 1; i <= n; ++ i){
		int l = a[i], r = b[i];
		if (l == r)
			continue;
		while (st.lower_bound({{l + 1, - 1}, - 1}) != st.end() && st.lower_bound({{l + 1, -1}, -1}) -> A.B < r){
			ppi x = *st.lower_bound({{l + 1, - 1}, - 1});
			st.erase(x);
			int ind = x.B, t = min(r, x.A.A) - max(l, x.A.B);
			if(x.A.B <= l)
			    st.insert({{l, x.A.B}, ind});
			if(r <= x.A.A)
			    st.insert({{x.A.A, r}, ind});
			vec[i].push_back({ind, - t});
		}
		st.insert({{r, l}, i});
		vec[i].push_back({i, r - l});			
	}                      	
}
pll check(int k){
	cnt = cn = sum = sm = 0;
	for(int i = 0; i < xn; ++ i)
		c[i] = 0;
	ptr = 1;
	for (int i = 1; i <= n; ++ i){
		for (pii x : vec[i]){
			int ind = x.A, t = x.B;
			if(ind < ptr)
				cn += 1ll * ind * t;
			else{
				cn += 1ll * (ptr - 1) * t;
				sm += t, c[ind] += t;
			}
		}
        while (k < sm && ptr <= i)
			cn += sm, sm -= c[ptr ++];
        cnt += ptr - 1, sum += cn;
	}
	return {cnt, sum};
}

int main(){    
	fast_io;

	cin >> n >> k;
	for(int i = 1; i <= n; ++ i)
		cin >> a[i] >> b[i];
	build();
	int lb = 0, rb = inf;
	while (lb <= rb){
		int md = lb + rb >> 1;
		if (k <= check(md).A)
			lb = md + 1;
		else
			rb = md - 1;
	}
    cout << 1ll * lb * (k - check(lb - 1).A) + check(lb - 1).B << endl;

	return 0;
}