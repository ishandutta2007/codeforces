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
const int xn = 1e5 + 10;
const int xm = 1e6 + 10;
const int SQ = 450;
const int sq = 1e3 + 10;
const int inf = 1e9 + 10;
 
 
ll power(ll a, ll b){return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));}
ll jaam(int a, int b){return (a + b) % md;}
ll menha(int a, int b){return (a - b + md) % md;}
ll zarb(int a, int b){return (1LL * a * b) % md;}
 
 
int n, m, ans[xn], cnt[xn], num[xn], ted, ted2, ptr, Query[xn];
pii Q[xn];
vector <int> B[xn];
 
void Solve(int ind){
	memset(cnt, 0, sizeof cnt);
	ted = 0;
	for (int i = ind; i < n; i ++){
		if (cnt[num[i]] == num[i]) ted --;
		cnt[num[i]] ++;
		if (cnt[num[i]] == num[i]) ted ++;
		while (ptr < m && Q[Query[ptr]].S == i){
			int j = Query[ptr];
			ted2 = ted;
			for (int k = ind; k < Q[j].F; k ++){
				if (cnt[num[k]] == num[k]) ted --;
				cnt[num[k]] --;
				if (cnt[num[k]] == num[k]) ted ++;
			}
			ans[j] = ted;
			for (int k = ind; k < Q[j].F; k ++) cnt[num[k]] ++;
			ted = ted2;
			ptr ++;
			if (ptr == m) return;
		}
	}
}

bool cmp(int i, int j){
	if (Q[i].F / SQ != Q[j].F / SQ) return Q[i].F / SQ < Q[j].F / SQ;
	return Q[i].S < Q[j].S;
}
 
int main(){
	fast_io;
	
	cin >> n >> m;
	for (int i = 0; i < n; i ++) cin >> num[i];
	for (int i = 0; i < n; i ++) num[i] = min(num[i], 100001);
	for (int i = 0; i < m; i ++){
		cin >> Q[i].F >> Q[i].S;
		Q[i].F --, Q[i].S --;
		Query[i] = i;
	}
	sort(Query, Query + m, cmp);
	for (int i = 0; i < n; i += SQ) Solve(i);
	for (int i = 0; i < m; i ++) cout << ans[i] << endl;
	
	return 0;
}