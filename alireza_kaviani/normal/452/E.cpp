#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define all(x)      (x).begin(),(x).end()
#define X           first
#define Y           second
#define sep         ' '
#define endl        '\n'
#define SZ(x)       ll(x.size())

const ll MAXN = 3e5 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int n , step , Rank[LOG][MAXN] , lcp[MAXN] , cnt[3][MAXN] , sz[MAXN] , par[MAXN];
ll cur , ans[MAXN];
string s1 , s2 , s3 , s;
vector<pii> Q[MAXN];

int cmp(int x , int y){
	if(Rank[step][x] != Rank[step][y])	return Rank[step][x] < Rank[step][y];
	if(x + (1 << step) >= n)	return 1;
	if(y + (1 << step) >= n)	return 0;
	return Rank[step][x + (1 << step)] < Rank[step][y + (1 << step)];
}

int LCP(int x , int y){
	int ans = 0;
	for(int i = LOG - 1 ; i >= 0 ; i--){
		if(Rank[i][x] == Rank[i][y]){
			ans += (1 << i);
			x += (1 << i);
			y += (1 << i);
		}
	}
	return ans;
}

void buildSA(){
	vector<int> vec;
	for(int i = 0 ; i < n ; i++){
		Rank[0][i] = s[i];
		vec.push_back(i);
	}
	for(int i = 1 ; i < LOG ; i++){
		sort(all(vec) , cmp);
		Rank[i][vec[0]] = 1;
		for(int j = 1 ; j < SZ(vec) ; j++){
			Rank[i][vec[j]] = Rank[i][vec[j - 1]] + cmp(vec[j - 1] , vec[j]);
		}
		step++;
	}
	sort(all(vec) , cmp);
	for(int i = 0 ; i + 1 < SZ(vec) ; i++){
		Q[LCP(vec[i] , vec[i + 1])].push_back({vec[i] , vec[i + 1]});
	}
}

int Find(int v){
	return (par[v] == -1 ? v : par[v] = Find(par[v]));
}

void Union(int v , int u){
	v = Find(v); u = Find(u);
	if(v == u)	return;
	if(sz[v] < sz[u])	swap(v , u);
	par[u] = v;
	sz[v] += sz[u];
	cur -= 1ll * cnt[0][v] * cnt[1][v] * cnt[2][v];
	cur -= 1ll * cnt[0][u] * cnt[1][u] * cnt[2][u];
	for(int i = 0 ; i < 3 ; i++)	cnt[i][v] += cnt[i][u];
	cur += 1ll * cnt[0][v] * cnt[1][v] * cnt[2][v];
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	fill(par , par + MAXN , -1);
	fill(sz , sz + MAXN , 1);

	cin >> s1 >> s2 >> s3;
	s = s1 + "0" + s2 + "1" + s3;
	n = s.size();
	for(int i = 0 ; i < s1.size() ; i++){
		cnt[0][i] = 1;
	}
	for(int i = s1.size() + 1 ; i <= s1.size() + s2.size() ; i++){
		cnt[1][i] = 1;
	}
	for(int i = s1.size() + s2.size() + 2 ; i < n ; i++){
		cnt[2][i] = 1;
	}

	buildSA();
	for(int i = n ; i >= 1 ; i--){
		for(pii j : Q[i]){
			Union(j.X , j.Y);
		}
		ans[i] = cur;
	}
	for(int i = 1 ; i <= min({SZ(s1) , SZ(s2) , SZ(s3)}) ; i++){
		cout << ans[i] % MOD << sep;
	}

    return 0;
}
/*

*/