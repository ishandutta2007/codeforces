//khodaya khodet komak kon
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
# define lc                                              id << 1
# define rc                                              id << 1 | 1
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}
 
const int xn = 1e5 + 10;
const int xm = - 20 + 10;
const int sq = 3e3;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e9 + 7;//998244353;
const int base = 257;

int n, q, a[xn], ord[xn], c[xn + xn];
int ptr, cnt[xn + xn], ans[xn], m, k;
pii b[xn];
pip query[xn];
vector <int> compress;
unordered_map <int, int> mp;
 
bool cmp(int i, int j){
	if (query[i].A / sq != query[j].A / sq)
		return query[i].A / sq < query[j].A / sq;
	if (query[i].B.A / sq != query[j].B.A / sq)
		return query[i].B.A / sq < query[j].B.A / sq;
	return query[i].B.B < query[j].B.B;
}
 
void add(int x, int y){
    -- cnt[c[x]];
    c[x] += y;
    ++ cnt[c[x]];
}
 
int main(){
    InTheNameOfGod;
    
    cin >> n >> q;
    compress.push_back(0);
    for (int i = 1; i <= n; ++ i)
        cin >> a[i], compress.push_back(a[i]);
    for (int i = 1; i <= q; ++ i){
        int t, x, y;
        cin >> t >> x >> y;
        if (t == 1)
            query[++ m] = {k, {x, y}}, ord[m] = m;
        else
            b[++ k] = {x, y}, compress.push_back(y);
    }
    sort(all(compress));
    for (int i = 0; i < SZ(compress); ++ i){
    	if (i && compress[i] == compress[i - 1])
    		continue;
    	mp[compress[i]] = ptr ++;
	}
	for (int i = 1; i <= n; ++ i)
		a[i] = mp[a[i]];
    for (int i = 1; i <= k; ++ i)
    	b[i].B = mp[b[i].B];
    sort(ord + 1, ord + m + 1, cmp);
    c[0] = xn * 10;
    int t = 0, l = 1, r = 0;
    for (int i = 1; i <= m; ++ i){
        int ind = ord[i], T = query[ind].A;
        int L = query[ind].B.A, R = query[ind].B.B;
        while (L < l)
            l --, add(a[l], 1);
        while (r < R)
            r ++, add(a[r], 1);
        while (l < L)
            add(a[l], - 1), ++ l;
        while (R < r)
            add(a[r], - 1), -- r;
        while (t < T){
            ++ t;
            int p = b[t].A;
            if (L <= p && p <= R)
                add(a[p], - 1), add(b[t].B, 1);
            swap(a[p], b[t].B);
        }
        while (T < t){
            int p = b[t].A;
            if (L <= p && p <= R)
                add(a[p], - 1), add(b[t].B, 1);
            swap(a[p], b[t].B);
            -- t;
        }
        ans[ind] = 1;
        while (cnt[ans[ind]])
            ++ ans[ind];
    }
    for (int i = 1; i <= m; i ++)
        cout << ans[i] << endl;

    return 0;
}