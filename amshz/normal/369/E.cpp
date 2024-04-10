# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <pii, pii> ppp;
 
# define A first
# define B second
# define endl '\n'
# define sep ' '
# define pb push_back
# define InTheNameOfGod ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e9 + 7;
const int xn = 1e6 + 10;
const int xm = 3e5 + 10;
const int SQ = 450;
const int sq = 1e3 + 10;
const int inf = 1e6 + 1;
const ll INF = 1e18 + 10;
 
ll power(ll a, ll b) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));}
ll zarb(ll a, ll b){return (a * b + 10 * md) % md;}
ll jaam(ll a, ll b){return (a + b + 10 * md) % md;}
 
int n, m, Seg[xn * 4], S, ans[xm];
pii num[xm], A[xm];
vector <pii> vec[xm];
vector <int> Q[xm];

void Update(int id, int L, int R, int index){
	if (R - L == 1){
		Seg[id] ++;
		return;
	}
	int Mid = (L + R) / 2;
	if (index < Mid) Update(id * 2, L, Mid, index);
	else Update(id * 2 + 1, Mid, R, index);
	Seg[id] = Seg[id * 2] + Seg[id * 2 + 1];
}
int Get(int id, int L, int R, int Ql, int Qr){
	if (Qr <= L || R <= Ql) return 0;
	if (Ql <= L && R <= Qr) return Seg[id];
	int Mid = (L + R) / 2;
	return Get(id * 2, L, Mid, Ql, Qr) + Get(id * 2 + 1, Mid, R, Ql, Qr);
}
 
int main(){
	InTheNameOfGod;
	
	cin >> n >> m;
	for (int i = 0; i < n; i ++) cin >> num[i].A >> num[i].B;
	sort(num, num + n);
	for (int i = 0; i < m; i ++){
		int x, y;
		cin >> x;
		for (int j = 0; j < x; j ++) cin >> y, vec[i].push_back({y, S ++});
		vec[i].push_back({inf, 0});
		for (int j = 0; j < x; j ++){
			int a = vec[i][j].A, b = vec[i][j + 1].A;
			int L = -1, R = n, Mid;
			while (R - L > 1){
				Mid = (L + R) / 2;
				if (num[Mid].A <= a) L = Mid;
				else R = Mid;
			}
			if (L == -1) continue;
			A[vec[i][j].B] = {a, b};
			Q[L].push_back(vec[i][j].B);
		}
	}
	
	for (int i = 0; i < n; i ++){
		Update(1, 0, xn, num[i].B);
		for (int ind : Q[i]) ans[ind] = Get(1, 0, xn, A[ind].A, A[ind].B);
	}
	for (int i = 0; i < m; i ++){
		int s = 0;
		for (int j = 0; j < vec[i].size() - 1; j ++) s += ans[vec[i][j].B];
		cout << s << endl;
	}
 	
	return 0;
}