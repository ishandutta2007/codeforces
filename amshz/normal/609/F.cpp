# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef double ld;
typedef pair <int, int> pii;
 
# define F first
# define S second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const int md = 1e9;
const int xn = 2e5 + 10;
const int xm = 1e6 + 10;
const int SQ = 550;
const int sq = 1e3 + 10;
const int inf = 1e9 + 10;
 
 
ll power(ll a, ll b){return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));}
ll jaam(int a, int b){return (a + b) % md;}
ll menha(int a, int b){return (a - b + md) % md;}
ll zarb(int a, int b){return (1LL * a * b) % md;}
 

int n, m, X[xn], Mn[xn], Min[xn], Tong[xn], P[xn];
pair <pii, pii> A[xn];
pii C[xn];
unordered_map <int, int> Mp;
set <pii> st;


void Update(int L, int R, int x){
	for (int i = L; i <= R;){
		if (i % SQ == 0 && i + SQ - 1 <= R) Mn[i / SQ] = min(Mn[i / SQ], x), i += SQ;
		else Min[i] = min(Min[i], x), i ++;
	}
}
pii BS(int x, int d){
	pii ans;
	int L = -1, R = m + 1, Mid;
	while (R - L > 1){
		Mid = (L + R) / 2;
		if (A[Mid].first.F <= x + d) L = Mid;
		else R = Mid;
	}
	ans.S = L;
	L = -1, R = m + 1, Mid;
	while (R - L > 1){
		Mid = (L + R) / 2;
		if (A[Mid].first.F < x) L = Mid;
		else R = Mid;
	}
	ans.F = R;
	return ans;
}
void Solve(int ind){
	if (min(Mn[ind / SQ], Min[ind]) == inf){
		st.insert({A[ind].first.F, ind});
		return;
	}
	int pnt = Mp[min(Mn[ind / SQ], Min[ind])];
	C[pnt].F ++, C[pnt].S += A[ind].first.S;
	Tong[pnt] += A[ind].first.S;
	pii BZ = BS(X[pnt], Tong[pnt]);
	int l = BZ.first, r = BZ.second;
	Update(l, r, X[pnt]);
	if (st.size() == 0) return;
	pii mx = *(prev(st.end()));
	if (mx.first < X[pnt]) return;
	pii x = *st.lower_bound({X[pnt], 0});
	if (x.F > X[pnt] + Tong[pnt]) return;
	st.erase(x), Solve(x.second);
}
void Build(){
	for (int i = 0; i < 2e5; i ++) Mn[i] = Min[i] = inf;
	sort(A, A + m);
	for (int i = 0; i < m; i ++) P[A[i].second.F] = i;
	for (int i = 0; i < n; i ++){
		C[i].second = Tong[i];
		Mp[X[i]] = i;
		pii BZ = BS(X[i], Tong[i]);
		int l = BZ.first, r = BZ.second;
		Update(l, r, X[i]);
	}
} 
int main(){
	fast_io;
	
	cin >> n >> m;
	for (int i = 0; i < n; i ++) cin >> X[i] >> Tong[i];
	for (int i = 0; i < m; i ++) cin >> A[i].first.F >> A[i].first.S, A[i].second.F = i;
	Build();
	for (int i = 0; i < m; i ++) Solve(P[i]);
	for (int i = 0; i < n; i ++) cout << C[i].first << sep << C[i].second << endl;
	
	return 0;
}