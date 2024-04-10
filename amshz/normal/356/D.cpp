# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long                                        ll;
typedef long double                                      ld;
typedef pair <int, int>                                  pii;
 
# define A                                               first
# define B                                               second
# define endl                                            '\n'
# define sep                                             ' '
# define all(x)                                          x.begin(), x.end()
# define kill(x)                                         return cout << x << endl, 0
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}
 
const int xn = 7e4 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e9 + 7;
const int base = 257;

int n, s, a[xn], root = 1, par[xn], p[xn];
bitset <xn> bs[2], x;
vector <int> vec;
bool mark[xn];

bool CMP(int i, int j){ return a[i] > a[j];}

int main(){
    InTheNameOfGod;
    
	cin >> n >> s;
	for (int i = 1; i <= n; ++ i){
		cin >> a[i];
		if (a[i] > a[root]) root = i;
	}
	bs[0][0] = 1;
	s -= a[root];
	for (int i = 1; i <= n; ++ i){
		if (i == root) continue;
		bs[1] = bs[0] | (bs[0] << a[i]);
		x = bs[0] ^ bs[1];
		for (int j = x._Find_first(); j < x.size(); j = x._Find_next(j)) p[j] = i;
		bs[0] = bs[1];
	}
	if (s < 0 || !bs[0][s]) kill(- 1);
	while (s){
		mark[p[s]] = true;
		s -= a[p[s]];
	}
	for (int i = 1; i <= n; ++ i) if (!mark[i]) vec.push_back(i);
	sort(all(vec), CMP);
	for (int i = 0; i < vec.size() - 1; ++ i) par[vec[i]] = vec[i + 1];
	for (int i = 1; i <= n; ++ i){
		cout << a[i] - a[par[i]] << sep;
		if (par[i]) cout << 1 << sep << par[i] << endl;
		else cout << 0 << endl;
	}

    return 0;
}