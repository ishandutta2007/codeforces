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

const int xn = 1e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 998244353;
const int base = 257;

int n, m, ptr, a[xn], b[xn], p[xn], dp[xn];
vector <int> vec[xn];
bool mark[xn];

int main(){
	fast_io;

	cin >> n;
	for (int i = 1; i <= n; ++ i)
		cin >> a[i];
	cin >> m;
	for (int i = 1; i <= m; ++ i)
		cin >> b[i];
	sort(b + 1, b + m + 1);
	for (int i = 1; i < xn; ++ i)
		dp[i] = inf;
	for (int i = 1; i <= n; ++ i){
		if (a[i] + 1){
			int lb = 0, rb = n;
			while (1 < rb - lb){
				int mid = lb + rb >> 1;
				if (dp[mid] < a[i])
					lb = mid;
				else
					rb = mid;
			}
			vec[rb].push_back(i);
			p[i] = rb, dp[rb] = a[i];
		}
		else{
			ptr = 0;
			for (int j = m; 1 <= j; -- j){
				while (dp[ptr] < b[j])
					++ ptr;
				while (ptr && b[j] <= dp[ptr - 1])
					-- ptr;
				dp[ptr] = b[j];
			}
		}
	}
	int last = - 1;
	for (int i = 0; i < xn; ++ i)
		if (dp[i] < inf)
			last = i;
	for (int i = n; 1 <= i; -- i){
		if (a[i] == - 1){
			int lb = - 1, rb = SZ(vec[last]);
			while (1 < rb - lb){
				int mid = lb + rb >> 1;
				if (vec[last][mid] < i)
					lb = mid;
				else
					rb = mid;
			}
			ptr = rb;
			if (!ptr || dp[last + 1] <= a[vec[last][ptr - 1]]){
				lb = 1, rb = m + 1;
				while (1 < rb - lb){
					int mid = lb + rb >> 1;
					if (b[mid] < dp[last + 1])
						lb = mid;
					else
						rb = mid;
				}
				a[i] = dp[last] = b[lb];
				mark[lb] = true, -- last;
			}
		}
		else if (p[i] == last)
			dp[last] = a[i], -- last;
		if (last < 0)
			break;
	}
	ptr = 1;
	for (int i = 1; i <= n; ++ i){
		if (a[i] + 1)
			continue;
		while (mark[ptr])
			++ ptr;
		a[i] = b[ptr];
		mark[ptr] = true;
	}
	for (int i = 1; i <= n; ++ i)
		cout << a[i] << sep;
	cout << endl;

	return 0;
}