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
typedef pair <ld, ld>                                  pll;
 
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
const int xn = 1e5 + 10;
const int xm = -20 + 10;
const int SQ = 320;
const int sq = 320 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int Md[3] = {1000000007, 987654319, 1000000009};
const int TM = 2;
const int Base = 257;
 
int n, m, part[xn], ans, Len, nxt[2][xn], ptr, P[xn];
string p[xn], s, t;

vector < int > kmp(string ss){
    int nn = ss.size();
    vector < int > f(nn);
    for(int i = 1 ; i < nn ; i ++){
        int j = f[i - 1];
        while(j and ss[i] != ss[j])
            j = f[j - 1];
        j += (ss[i] == ss[j]) , f[i] = j;
    }
    return(f);
}

void Solve(){
	Len = SZ(t);
	if (Len == 1)	 return;
	vector <int> vec = kmp(t + '.' + s);
	for (int i = 1; i <= n; ++ i)	nxt[0][i] = vec[i + Len];
	reverse(all(t));
	reverse(all(s));
	vec = kmp(t + '.' + s);
	reverse(all(vec));
	for (int i = 1; i <= n; ++ i)	nxt[1][i] = vec[i - 1];
	for (int i = n; i >= 1; -- i)	part[i] = max(part[i + 1], nxt[1][i]);
	bool flag = false;
	for (int i = 1; i <= n; ++ i)
		flag |= part[i + 1] >= (Len - nxt[0][i]);
	ans += flag;
	reverse(all(s));
}

int main(){
    InTheNameOfGod;
    
    cin >> s >> m;
    n = SZ(s);
    s = '.' + s;
    for (int i = 0; i < m; ++ i)	cin >> p[i];
	for (int i = 0; i < m; ++ i)	t = p[i], Solve();
	cout << ans << endl;
	
    
    return 0;
}