// God & me
// Love or like? This is the problem !!
#include <bits/stdc++.h>
#define pb push_back
#define X first
#define Y second
using namespace std;
template <class T, class L> bool smax(T &x, L y){  return x < y ? ( x = y, 1) : 0;  }
template <class T, class L> bool smin(T &x, L y){  return y < x ? ( x = y, 1) : 0;  }
typedef pair <int, int> pii;
typedef long long ll;

const int maxn = 1e3 + 17;
int h, t, r, n, m, d[maxn][maxn], q[maxn * maxn], hdis;
int ch[maxn * 2], ct[maxn * 2], fch[maxn * 2], fct[maxn * 2], par[maxn][maxn];
int mark[maxn][maxn];
vector<pii> st;
void dfs(int x, int y){
    if(x + y > r)  return ;
    if(mark[x][y] == 1)
	cout << "Draw\n", exit(0);
    else if(mark[x][y] == 2)  return ;
    mark[x][y] = 1;
    for(int i = 0; i < n; i++)
	if(x - fch[i] >= 0 && y - fct[i] >= 0)
	    dfs(x + ch[i], y + ct[i]);
    mark[x][y] = 2;
}
void go(int x, int y){
    if(mark[x][y])  return ;
    mark[x][y] = 1;
    if(x + y <= r)
	for(int i = 0; i < n; i++)
	    if(x - fch[i] >= 0 && y - fct[i] >= 0)
		go(x + ch[i], y + ct[i]);
    st.pb({x, y});
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0);    
    cin >> h >> t >> r >> n;
    for(int i = 0; i < n; i++)
	cin >> ch[i] >> ct[i], ch[i] -= i + 1;
    cin >> m;
    iota(fch, fch + n, 1);
    iota(fct + n, fct + n + m, 1);
    for(int i = 0; i < m; i++)
	cin >> ch[i + n] >> ct[i + n], ct[i + n] -= i + 1;
    n += m;
    memset(d, 63, sizeof d);
    d[h][t] = 0;
    int he = 0, ta = 0, ln = 0;
    q[ta++] = h * maxn + t;
    while(he != ta){
	int x = q[he] / maxn, y = q[he++] % maxn;
	if(x + y > r)   continue;
	for(int i = 0; i < n; i++)
	    if(x - fch[i] >= 0 && y - fct[i] >= 0 && smin(d[ x + ch[i] ][ y + ct[i] ], d[x][y] + 1))
		q[ta++] = (x + ch[i]) * maxn + y + ct[i], par[ x + ch[i] ][ y + ct[i] ] = x * maxn + y;
    }
    if(d[0][0] < 1e9)
	return cout << "Ivan\n" << d[0][0] << '\n', 0;
    memset(mark, 0, sizeof mark);
    dfs(h, t);
    cout << "Zmey\n";
    memset(d, -63, sizeof d);
    memset(mark, 0, sizeof mark);
    d[h][t] = 0;
    go(h, t);
    reverse(st.begin(), st.end());
    for(auto v : st){
	if(v.X + v.Y  > r){
	    smax(hdis, d[v.X][v.Y]);  continue;
	}
	for(int i = 0; i < n; i++)
	    if(v.X - fch[i] >= 0 && v.Y - fct[i] >= 0)
		smax(d[v.X + ch[i] ][ v.Y + ct[i] ], d[v.X][v.Y] + 1);
    }
    cout << hdis << '\n';
    return 0;
}