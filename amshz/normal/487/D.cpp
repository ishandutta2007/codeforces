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
 
const int xn = 1e5 + 10;
const int xm = 10 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e9 + 7;
const int base = 257;

int n, m, q;
char c[xn][xm];
string s;
pii seg[xm][xn << 2];

void change(int id, int l, int r){
	for (int i = 1; i <= m; ++ i){
		int res = i, t = m;
		while (t --){
			if (c[l][res] == '^' || !res || res > m)
				continue;
			if (c[l][res] == '>')
				++ res;
			else
				-- res;
		}
		if (!res || res > m)
			seg[i][id] = {l, res};
		else if (c[l][res] == '^')
			seg[i][id] = {0, res};
		else
			seg[i][id] = {- 1, - 1};
	}
}
void merge(int id, int l, int r){
	for (int i = 1; i <= m; ++ i){
		if (seg[i][id << 1 | 1].A == - 1)
			seg[i][id] = {- 1, - 1};
		else if (seg[i][id << 1 | 1].A)
			seg[i][id] = seg[i][id << 1 | 1];
		else
			seg[i][id] = seg[seg[i][id << 1 | 1].B][id << 1];
	}
}
void build(int id, int l, int r){
	if (r - l == 1){
		change(id, l, r);
		return;
	}
	int mid = l + r >> 1;
	build(id << 1, l, mid);
	build(id << 1 | 1, mid, r);
	merge(id, l, r);
}
void modify(int id, int l, int r, int pos){
	if (r - l == 1){
		change(id, l, r);
		return;
	}
	int mid = l + r >> 1;
	if (pos < mid)
		modify(id << 1, l, mid, pos);
	else
		modify(id << 1 | 1, mid, r, pos);
	merge(id, l, r);
}
pii get(int id, int l, int r, int x, int y){
	if (r - l == 1)
		return seg[y][id];
	int mid = l + r >> 1;
	if (x < mid)
		return get(id << 1, l, mid, x, y);
	pii a = get(id << 1 | 1, mid, r, x, y);
	if (!a.A)
		return seg[a.B][id << 1];
	return a;
}

int main(){
    InTheNameOfGod;
    
	cin >> n >> m >> q;
	for (int i = 1; i <= n; ++ i){
		cin >> s;
		for (int j = 1; j <= m; ++ j)
			c[i][j] = s[j - 1];
	}
	build(1, 1, n + 1);
	while (q --){
		char C, z;
		int x, y;
		cin >> C;
		if (C == 'A'){
			cin >> x >> y;
			pii a = get(1, 1, n + 1, x, y);
			cout << a.A << sep << a.B << endl;
		}
		else{
			cin >> x >> y >> z;
			c[x][y] = z;
			modify(1, 1, n + 1, x);
		}
	}
 
    return 0;
}