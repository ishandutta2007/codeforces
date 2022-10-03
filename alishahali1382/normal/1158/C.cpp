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
const int MAXN = 500010, LOG=20;

int n, m, k, u, v, x, y, t, a, b;
int nxt[MAXN];
int deg[MAXN];
int ans[MAXN];
queue<int> q;
vector<int> topol;
vector<int> G[MAXN];
stack<int> stk;
vector<int> vec[MAXN];
bool instk[MAXN];

void addedge(int u, int v){
	G[u].pb(v);
	deg[v]++;
}

int solve(){
	topol.clear();
	cin>>n;
	for (int i=1; i<=n+1; i++){
		vec[i].clear();
		G[i].clear();
		deg[i]=0;
		instk[i]=0;
	}
	while (!stk.empty()) stk.pop();
	for (int i=1; i<=n; i++){
		cin>>nxt[i];
		vec[nxt[i]].pb(i);
		if (nxt[i]!=-1) addedge(i, nxt[i]);
	}
	for (int i=1; i<=n+1; i++){
		for (int j:vec[i]) while (instk[j]){
			int t=stk.top();
			stk.pop();
			instk[t]=0;
			if (nxt[t]!=-1 && nxt[t]>i) kill(-1);
			addedge(t, i);
		}
		if (!stk.empty()) addedge(i, stk.top());
		stk.push(i);
		instk[i]=1;
	}
	
	// topol sort
	for (int i=1; i<=n+1; i++) if (!deg[i]) q.push(i);
	while (!q.empty()){
		int v=q.front();
		q.pop();
		if (v<=n) topol.pb(v);
		for (int i:G[v]) if (!(--deg[i])) q.push(i);
	}
	// ----------
	
	if (topol.size()!=n) kill(-1);
	
	//cerr<<"\n----------------\n";
	for (int i=1; i<=n; i++) ans[topol[i-1]]=i;
	for (int i=1; i<=n; i++) cout<<ans[i]<<' ';
	cout<<'\n';
	//cerr<<"-----------------\n\n";
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int T;
	cin>>T;
	while (T--) solve();
	
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