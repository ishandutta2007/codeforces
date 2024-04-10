# include <bits/stdc++.h>

/*
// ordered_set 
# include <ext/pb_ds/assoc_container.hpp>
# include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
# define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
*/
 
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
# define Sort(x)                                         sort(all(x))
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}

//const ll md = 1e9 + 7;//998244353;
const int xn = 2e5 + 10;
const int xm = -20 + 10;
const int SQ = 320;
const int sq = 320 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ll Md[3] = {998244353, 1000000007, 1000000009};
const int TM = 3;
const ll Base = 109661199601;

int n, m, f[xn + xn];
ll Pw[TM][xn], PH[TM][xn], inv[TM][xn], Inv[TM], x[TM], ans;
string s[xn], t[xn], a, b;
vector <pair <char, ll> > vec[2];
bool flag[xn];

void kmp(string ss){
    for(int i = 1 ; i < SZ(ss); ++ i){
        int j = f[i - 1];
        while (j && ss[i] != ss[j])
            j = f[j - 1];
        j += (ss[i] == ss[j]) , f[i] = j;
    }
}

ll get(int l, int r, int ind){
	if (r < l) return 0;
	return ((PH[ind][r] - PH[ind][l - 1] + Md[ind]) % Md[ind]) * inv[ind][l - 1] % Md[ind];
}

int main(){
    InTheNameOfGod;
    
    cin >> n >> m;
    char last = '.';
    for (int i = 0; i < n; ++ i){
    	cin >> t[i];
    	ll res = 0;
    	for (int j = 0; j < SZ(t[i]) - 2; ++ j) res = res * 10 + ll(t[i][j] - '0');
    	char c = t[i][SZ(t[i]) - 1];
    	if (c == last){
    		vec[0].back().B += res;
    		continue;
		}
		last = c;
    	vec[0].push_back({c, res});
    	a += c;
	}
	last = '.';
	for (int i = 0; i < m; ++ i){
    	cin >> s[i];
    	ll res = 0;
    	for (int j = 0; j < SZ(s[i]) - 2; ++ j) res = res * 10 + ll(s[i][j] - '0');
    	char c = s[i][SZ(s[i]) - 1];
    	if (c == last){
    		vec[1].back().B += res;
    		continue;
		}
		last = c;
    	vec[1].push_back({c, res});
    	b += c;
	}
	kmp(b + '$' + a);
	for (int i = SZ(b) + 1; i <= SZ(b) + SZ(a); ++ i) if (f[i] == SZ(b)) flag[i - f[i] - f[i]] = true;
	for (int i = 0; i < TM; ++ i){
		Inv[i] = power(Base % Md[i], Md[i] - 2, Md[i]);
		Pw[i][0] = inv[i][0] = 1;
	}
	for (int i = 0; i < TM; ++ i){
		for (int j = 1; j < SZ(vec[0]); ++ j){
			Pw[i][j] = Pw[i][j - 1] * (Base % Md[i]) % Md[i];
			inv[i][j] = inv[i][j - 1] * Inv[i] % Md[i];
			PH[i][j] = (PH[i][j - 1] + (vec[0][j].B % Md[i]) * Pw[i][j] % Md[i]) % Md[i];
		}
	}
	for (int i = 0; i < TM; ++ i) for (int j = 1; j < SZ(vec[1]) - 1; ++ j) x[i] = (x[i] + (vec[1][j].B % Md[i]) * Pw[i][j] % Md[i]) % Md[i];
	for (int i = 0; i < SZ(vec[0]); ++ i){
		if (!flag[i]) continue;
		bool fl1 = true;
		for (int j = 0; j < TM; ++ j){
			ll res = get(i + 1, i + SZ(b) - 2, j);
			fl1 &= res == x[j];
		}
		fl1 &= vec[1][0].B <= vec[0][i].B;
		fl1 &= vec[1].back().B <= vec[0][i + SZ(b) - 1].B;
		ans += fl1;
		if (SZ(b) == 1) ans += max(0LL, vec[0][i].B - vec[1][0].B);
	}
	cout << ans << endl;
	
	
    return 0;
    
}