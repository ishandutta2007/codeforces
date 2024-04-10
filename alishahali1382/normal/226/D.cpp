#include <bits/stdc++.h>
#if defined(__GNUC__)
#pragma GCC optimize ("Ofast")
#endif
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl;
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl;
#define debugv(v) cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 110, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
int r[MAXN];
int c[MAXN];
int A[MAXN][MAXN];
bool ansr[MAXN];
bool ansc[MAXN];
queue<pii> q;

void upd(int x, int y){
	r[x]-=A[x][y];
	c[y]-=A[x][y];
	A[x][y]=-A[x][y];
	r[x]+=A[x][y];
	c[y]+=A[x][y];
	if (r[x]<0) q.push({0, x});
	if (c[y]<0) q.push({1, y});
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	for (int i=1; i<=n; i++) for (int j=1; j<=m; j++){
		cin>>A[i][j];
		r[i]+=A[i][j];
		c[j]+=A[i][j];
	}
	for (int i=1; i<=n; i++) if (r[i]<0) q.push({0, i});
	for (int i=1; i<=m; i++) if (c[i]<0) q.push({1, i});
	while (!q.empty()){
		int type=q.front().first, x=q.front().second;
		q.pop();
		if (!type){
			if (r[x]>=0) continue ;
			ansr[x]^=1;
			for (int i=1; i<=m; i++) upd(x, i);
			continue ;
		}
		if (c[x]>=0) continue ;
		ansc[x]^=1;
		for (int i=1; i<=n; i++) upd(i, x);
	}
	for (int i=1; i<=n; i++) ans+=ansr[i];
	cout<<ans;
	for (int i=1; i<=n; i++) if (ansr[i]) cout<<' '<<i;
	
	ans=0;
	for (int i=1; i<=m; i++) ans+=ansc[i];
	cout<<'\n'<<ans;
	for (int i=1; i<=m; i++) if (ansc[i]) cout<<' '<<i;
	
	return 0;
}
/*
      ___           ___                            ___           ___           ___           ___           ___           ___
     /\  \         /\__\      ___                 /\  \         /\__\         /\  \         /\__\         /\  \         /\__\      ___
    /::\  \       /:/  /     /\  \               /::\  \       /:/  /        /::\  \       /:/  /        /::\  \       /:/  /     /\  \
   /:/\:\  \     /:/  /      \:\  \             /:/\ \  \     /:/__/        /:/\:\  \     /:/__/        /:/\:\  \     /:/  /      \:\  \
  /::\~\:\  \   /:/  /       /::\__\           _\:\~\ \  \   /::\  \ ___   /::\~\:\  \   /::\  \ ___   /::\~\:\  \   /:/  /       /::\__\
 /:/\:\ \:\__\ /:/__/     __/:/\/__/          /\ \:\ \ \__\ /:/\:\  /\__\ /:/\:\ \:\__\ /:/\:\  /\__\ /:/\:\ \:\__\ /:/__/     __/:/\/__/
 \/__\:\/:/  / \:\  \    /\/:/  /             \:\ \:\ \/__/ \/__\:\/:/  / \/__\:\/:/  / \/__\:\/:/  / \/__\:\/:/  / \:\  \    /\/:/  /
      \::/  /   \:\  \   \::/__/               \:\ \:\__\        \::/  /       \::/  /       \::/  /       \::/  /   \:\  \   \::/__/
      /:/  /     \:\  \   \:\__\                \:\/:/  /        /:/  /        /:/  /        /:/  /        /:/  /     \:\  \   \:\__\
     /:/  /       \:\__\   \/__/                 \::/  /        /:/  /        /:/  /        /:/  /        /:/  /       \:\__\   \/__/
     \/__/         \/__/                          \/__/         \/__/         \/__/         \/__/         \/__/         \/__/
*/