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
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}
 
const int xn = 150 + 10;
const int xm = - 20;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e9 + 7;
const int base = 257;

struct matrix{
    ll n, m;
    bitset <xn> bs[2][xn];
    matrix(int n1, int m1){
        n = n1; m = m1;
        for (int i = 0; i < n; i ++)
            for (int j = 0; j < m; j ++)
                bs[0][i][j] = bs[1][j][i] = 0;
    }
    matrix operator * (const matrix &t){
        matrix r = matrix(n, t.m);
        for (int i = 0; i < n; i ++)
            for (int j = 0; j < t.m; j ++)
            	r.bs[0][i][j] = r.bs[1][j][i] = (bs[0][i] & t.bs[1][j]).count() > 0;
        return r;
    }
};
 
matrix Pow(matrix a, ll b){
    matrix res = matrix(a.n, a.m);
    for (int i = 0; i < a.n; i ++)
    	res.bs[0][i][i] = res.bs[1][i][i] = 1;
    for (; b; b = b >> 1){
        if (b & 1)
            res = res * a;
        a = a * a;
    }
    return res;
}

ll n, m, ans = INF, last, dist[xn];
pip E[xn];
vector <int> adj[xn];
queue <int> q;

int main(){
	InTheNameOfGod;
    
    cin >> n >> m;
    for (int i = 0; i < m; ++ i)
    	cin >> E[i].B.A >> E[i].B.B >> E[i].A;
    sort(E, E + m);
    matrix c(n, n), mat(n, 1);
    mat.bs[0][0][0] = mat.bs[1][0][0] = 1;
    for (int i = 0; i < m; ++ i){
    	mat = Pow(c, E[i].A - last) * mat, last = E[i].A;
    	adj[E[i].B.B].push_back(E[i].B.A);
    	c.bs[0][E[i].B.B - 1][E[i].B.A - 1] = 1;
    	c.bs[1][E[i].B.A - 1][E[i].B.B - 1] = 1;
    	memset(dist, - 1, sizeof dist);
		dist[n] = 0;
		q.push(n);
		while (SZ(q)){
			int v = q.front();
			q.pop();
			if (mat.bs[0][v - 1][0])
				ans = min(ans, last + dist[v]);
			for (int u : adj[v]){
				if (dist[u] != - 1)
					continue;
				dist[u] = dist[v] + 1;
				q.push(u);
			}
		}
	}
	if (ans == INF) kill("Impossible");
	cout << ans << endl;
	
    return 0;
}