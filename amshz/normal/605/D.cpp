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
 
const int xn = 1e5 + 10;
const int xm = - 20 + 10;
const int SQ = 320;
const int sq = 320 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e9 + 7;
const int TM = 3;
const int base = 257;

int n, dist[xn], par[xn], ord[xn], mx[xn << 2], ptr[2], mn[xn << 2], res;
ppp a[xn];
queue <int> q;
vector <int> seg[xn << 2], ans;

bool cmp(int i, int j){ return a[i] < a[j];}

void build(int id, int l, int r){
	if (r - l == 1){
		seg[id].push_back(ord[l]);
		mx[id] = mn[id] = a[ord[l]].A.A;
		return;
	}
	int mid = l + r >> 1;
	build(id << 1, l, mid);
	build(id << 1 | 1, mid, r);
	ptr[0] = ptr[1] = 0;
	while (ptr[0] < mid - l || ptr[1] < r - mid){
		if (ptr[1] == r - mid) seg[id].push_back(seg[id << 1][ptr[0] ++]);
		else if (ptr[0] == mid - l) seg[id].push_back(seg[id << 1 | 1][ptr[1] ++]);
		else if (a[seg[id << 1][ptr[0]]].A.B > a[seg[id << 1 | 1][ptr[1]]].A.B)
		seg[id].push_back(seg[id << 1][ptr[0] ++]);
		else seg[id].push_back(seg[id << 1 | 1][ptr[1] ++]);
	}
	mx[id] = max(mx[id << 1], mx[id << 1 | 1]);
	mn[id] = min(mn[id << 1], mn[id << 1 | 1]);
}
void get(int id, int l, int r, int ind){
	if (mn[id] > a[ind].B.A) return;
	if (mx[id] <= a[ind].B.A){
		while (seg[id].size()){
			if (a[seg[id].back()].A.B > a[ind].B.B) break;
			if (dist[seg[id].back()] == - 1){
				dist[seg[id].back()] = dist[ind] + 1;
				q.push(seg[id].back());
				par[seg[id].back()] = ind;
			}
			seg[id].pop_back();
		}
		return;
	}
	int mid = l + r >> 1;
	get(id << 1, l, mid, ind);
	get(id << 1 | 1, mid, r, ind);
}

int main(){
    InTheNameOfGod;
    
    cin >> n, ++ n;
    for (int i = 1; i < n; ++ i){
    	cin >> a[i].A.A >> a[i].A.B >> a[i].B.A >> a[i].B.B;
    	dist[i] = - 1;
    	ord[i] = i;
	}
	sort(ord, ord + n, cmp);
	build(1, 0, n);
	q.push(0);
	while (q.size()){
		int v = q.front();
		q.pop();
		get(1, 0, n, v);
	}
	cout << dist[n - 1] << endl;
	if (dist[n - 1] == - 1) return 0;
	res = n - 1;
	while (res){
		ans.push_back(res);
		res = par[res];
	}
	reverse(all(ans));
	for (int x : ans) cout << x << sep;
	cout << endl;

    return 0;
}