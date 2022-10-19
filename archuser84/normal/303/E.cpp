///
///    Hashire sori yo 
///    Kaze no you ni  
///    Tsukimihara wo  
///    PADORU PADORU   
///

#include <bits/stdc++.h>
#define Loop(x,l,r) for(ll x = ll(l); x < ll(r); ++x)
#define LoopR(x,l,r) for(ll x = ll(r)-1; x >= ll(l); --x)
#define Kill(x) exit((cout << (x) << '\n', 0))
typedef long long ll;
typedef std::pair<int,int> pii;
using namespace std;

#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2")

const int N = 83;
int l[N], r[N];
vector<int> cmp;
double ans[N][N];
int X;
int n;

double p0(int i, int x=X){
	if(cmp[x] <= l[i]) return 0;
	if(r[i] <= cmp[x]) return 1;
	return (double)(cmp[x]-l[i])/(r[i]-l[i]);
}
double p1(int i, int x=X){
	if(cmp[x] <= l[i] && r[i] <= cmp[x+1]) return 1;
	if(cmp[x+1] <= l[i] || r[i] <= cmp[x]) return 0;
	if(l[i] <= cmp[x] && cmp[x+1] <= r[i]) return double(cmp[x+1]-cmp[x])/(r[i]-l[i]);
	if(cmp[x] <= l[i]) return (double)(cmp[x+1]-l[i])/(r[i]-l[i]);
	else return (double)(r[i]-cmp[x])/(r[i]-l[i]);
}
double p2(int i, int x=X){
	if(r[i] <= cmp[x+1]) return 0;
	if(cmp[x+1] <= l[i]) return 1;
	return (double)(r[i]-cmp[x+1])/(r[i]-l[i]);
}

double dp[N][N][N]; int dpi; //dp[i][j][k] = i ta, j ta ghabl, k ta vasat

void up(int i){
	auto p0 = ::p0(i), p1 = ::p1(i), p2 = ::p2(i);
	Loop(j,0,dpi+2) Loop(k,0,dpi+2-j) dp[dpi+1][j][k] = 0;
	Loop(j,0,dpi+1) Loop(k,0,dpi+1-j){
		dp[dpi+1][j+1][k] += p0*dp[dpi][j][k];
		dp[dpi+1][j][k+1] += p1*dp[dpi][j][k];
		dp[dpi+1][j][k]   += p2*dp[dpi][j][k];
	}
	++dpi;
}

void calc(int i){
	auto p = p1(i);
	Loop(j,0,dpi+1) Loop(k,0,dpi+1-j) {
		ans[i][j] += p*dp[dpi][j][k]/(k+1);
		ans[i][j+k+1] -= p*dp[dpi][j][k]/(k+1);
	}
}

vector<int> t[N<<2];

void add(int l, int r, int x, int i=0, int b=0, int e=n){
	if(l >= r) return;
	if(l <= b && e <= r) {t[i].push_back(x); return;}
	if(r <= b || e <= l) return;
	add(l,r,x,2*i+1,b,(b+e)/2);
	add(l,r,x,2*i+2,(b+e)/2,e);
}

void dfs(int i=0, int b=0, int e=n){
	for(int x : t[i]) up(x);
	if(e-b == 1) {calc(b); dpi -= t[i].size(); return;}
	dfs(2*i+1,b,(b+e)/2);
	dfs(2*i+2,(b+e)/2,e);
	dpi -= t[i].size();
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);
	cin >> n;
	Loop(i,0,n){
		cin >> l[i] >> r[i];
		cmp.push_back(l[i]);
		cmp.push_back(r[i]);
	}
	sort(cmp.begin(), cmp.end());
	cmp.resize(unique(cmp.begin(), cmp.end()) - cmp.begin());
	Loop(i,0,n) {add(0, i, i); add(i+1, n, i);}
	dp[0][0][0]=1;
	for(X = 0; X < cmp.size()-1; ++X) dfs();
	cout << fixed << setprecision(9);
	Loop(i,0,n){
		double sum = 0;
		Loop(j,0,n)
			sum += ans[i][j],
			cout << sum << ' ';
		cout << '\n';
	}
}