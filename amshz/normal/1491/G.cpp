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

const int xn = 2e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 1e9 + 7;//998244353;
const int base = 257;

int n, a[xn], ptr;
bool mark[xn];
vector <int> vec[xn];
vector <pii> ans;

void DFS(int v, int c){
	mark[v] = true;
	vec[c].push_back(v);
	if (!mark[a[v]])
		DFS(a[v], c);
}

int main(){
	fast_io;

	cin >> n;
	for (int i = 1; i <= n; ++ i)
		cin >> a[i], mark[i] = i == a[i];
	for (int i = 1; i <= n; ++ i)
		if (!mark[i])
			DFS(i, ++ ptr);
	memset(mark, false, sizeof mark);
	for (int i = 1; i < ptr; i += 2){
		ans.push_back({vec[i][0], vec[i + 1][0]});
		for (int j = 1; j < SZ(vec[i]); ++ j)
			ans.push_back({vec[i + 1][0], vec[i][j]});
		for (int j = 1; j < SZ(vec[i + 1]); ++ j)
			ans.push_back({vec[i][0], vec[i + 1][j]});
		ans.push_back({vec[i][0], vec[i + 1][0]});
	}
	if (ptr % 2){
		if (SZ(vec[ptr]) == 2){
			int x = vec[ptr][0], y = vec[ptr][1], z;
			for (int i = 1; i <= 3; ++ i)
				if (i != x && i != y)
					z = i;
			ans.push_back({x, z});
			ans.push_back({y, z});
			ans.push_back({z, x});
		}
		else{
			ans.push_back({vec[ptr][1], vec[ptr][2]});
			ans.push_back({vec[ptr][0], vec[ptr][2]});
			for (int i = 3; i < SZ(vec[ptr]); ++ i)
				ans.push_back({vec[ptr][1], vec[ptr][i]});
			ans.push_back({vec[ptr][1], vec[ptr][0]});
			ans.push_back({vec[ptr][1], vec[ptr][2]});
		}
	}
	for (pii x : ans)
		swap(a[x.A], a[x.B]), a[x.A] *= - 1, a[x.B] *= - 1;
	for (int i = 1; i <= n; ++ i)
		if (a[i] != i)
			kill("FUCK");
	cout << SZ(ans) << endl;
	for (pii x : ans)
		cout << x.A << sep << x.B << endl;

	return 0;
}