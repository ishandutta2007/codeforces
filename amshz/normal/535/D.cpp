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
const int xn = 1e6 + 10;
const int xm = -20 + 10;
const int SQ = 320;
const int sq = 320 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int Md[3] = {1000000007, 987654319, 1000000009};
const int TM = 2;
const int Base = 257;

int n, m, sz, f[xn], num[xn], ptr, part[xn], ted;
string s;
bool flag[xn], flg = true;

void kmp(string ss){
    for(int i = 1 ; i < SZ(ss); ++ i){
        int j = f[i - 1];
        while (j && ss[i] != ss[j])
            j = f[j - 1];
        j += (ss[i] == ss[j]) , f[i] = j;
    }
}

int main(){
    InTheNameOfGod;
    
    cin >> n >> m >> s;
    sz = ptr = SZ(s) - 1;
    for (int i = 0; i < m; ++ i)	cin >> num[i], ++ part[num[i]], -- part[num[i] + sz + 1];
    kmp(s);
    while (ptr > 0) 	ptr = f[ptr] - 1, flag[ptr] = true;
	for (int i = 1; i <= n; ++ i)	part[i] += part[i - 1], ted += !(part[i]);
	for (int i = 1; i < m; ++ i)	flg &= (flag[sz - num[i] + num[i - 1]] | sz - num[i] + num[i - 1] < 0);
	if (!flg && m)	kill(0);
    else 	kill(power(26, ted, Md[0]));
    
    return 0;
}