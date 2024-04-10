#include<bits/stdc++.h> 
using namespace std; 
typedef long long ll;
typedef long double ld;
const int maxn = 1e5 + 10;
const int SQRT = 340;
const ll inf = 1e18;

int a[maxn], b[maxn];
vector<int> t[maxn];

ll dp[maxn];

struct Line{
	ll a;
	ll b;
	Line(ll a_ = 0, ll b_ = 0){
		a = a_, b = b_;
	}
	ll gety(ll x){
		return a * x + b;
	}
};

ld intersect(Line f, Line s){
	return (f.b - s.b) / (s.a - f.a);
}


struct Hull{
	vector<Line> L;
	Hull(){
	}
	Hull(vector<Line> &d){
		L.clear();
		for (auto t : d){
			if (!L.empty() and L.back().a == t.a){
				if (L.back().b <= t.b)
					continue;
				L.pop_back();
			}
			while (L.size() >= 2){
				int sz = (int)L.size();
				Line prepre = L[sz - 2], pre = L[sz - 1];
				if (intersect(prepre, pre) >= intersect(pre, t))
					L.pop_back();
				else
					break;
			}
			L.push_back(t);
		}
	}
	ll get(ll x){
		if (L.empty())
			return inf;
		int lo = -1, hi = (int)L.size() - 1;
		while (hi - lo > 1){
			int mid = (lo + hi) >> 1;
			if (intersect(L[mid], L[mid+1]) < x)
				lo = mid;
			else
				hi = mid;
		}
		return L[hi].gety(x);
	}
} hull[SQRT + 10];

vector<Line> lines[SQRT + 10];
Line d[maxn];

void dfs(int v, int par = -1){
	static int time = 0;
	int st = time ++;
	dp[v] = 0;
	for (auto u : t[v]){
		if (u == par)
			continue;
		dp[v] = inf;
		dfs(u, v);
	}
	int ft = time;
	int L = st, R = ft, block = st/SQRT;
	L ++;
	while (L < R){
		if (L % SQRT != 0 or R < L + SQRT)
			dp[v] = min(dp[v], d[L ++].gety(a[v]));
		else
			dp[v] = min(dp[v], hull[L/SQRT].get(a[v])), L += SQRT;
	}
	Line me = Line(b[v], dp[v]);
	d[st] = me;
	lines[block].push_back(me);
	int ptr = (int)lines[block].size() - 1;
	while (ptr > 0 and lines[block][ptr].a > lines[block][ptr-1].a){
		swap(lines[block][ptr-1], lines[block][ptr]);
		ptr --;
	}
	hull[block] = Hull(lines[block]);
}

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int v = 1; v <= n; v++)
		cin >> a[v];
	for (int v = 1; v <= n; v++)
		cin >> b[v];
	for (int i = 1; i <= n - 1; i++){
		int v, u;
		cin >> v >> u;
		t[v].push_back(u);
		t[u].push_back(v);
	}
	dfs(1);
	for (int i = 1; i <= n; i++)
		cout << dp[i] << " \n"[i == n];
}