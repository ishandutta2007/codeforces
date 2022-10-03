#include <bits/stdc++.h>
#pragma GCC optimize ("O2")
#pragma GCC optimize ("unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl;
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl;
#define debugv(v) cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000000;
const ll INF=10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 300010, LOG=20;

struct SEG1{
	int seg[MAXN<<2];
	
	int build(int id, int tl, int tr, int A[]){
		if (tr-tl==1) return seg[id]=A[tl];
		int mid=(tl+tr)>>1;
		return seg[id]=max(build(id<<1, tl, mid, A), build(id<<1 | 1, mid, tr, A));
	}
	
	void update(int id, int tl, int tr, int pos, int val){
		if (pos<tl || tr<=pos) return ;
		if (tr-tl==1){
			seg[id]=val;
			return ;
		}
		int mid=(tl+tr)>>1;
		update(id<<1, tl, mid, pos, val);
		update(id<<1 | 1, mid, tr, pos, val);
		seg[id]=max(seg[id<<1], seg[id<<1 | 1]);
	}
	
	int get(int id, int tl, int tr, int l, int r){
		if (r<=tl || tr<=l) return 0;
		if (l<=tl && tr<=r) return seg[id];
		int mid=(tl+tr)>>1;
		return max(get(id<<1, tl, mid, l, r), get(id<<1 | 1, mid, tr, l, r));
	}
} seg1;

struct SEG2{
	int seg[MAXN<<2];
	SEG2(){ memset(seg, 63, sizeof(seg));}
	
	void update(int id, int tl, int tr, int l, int r, int val){
		if (r<=tl || tr<=l) return ;
		if (l<=tl && tr<=r){
			seg[id]=min(seg[id], val);
			return ;
		}
		int mid=(tl+tr)>>1;
		update(id<<1, tl, mid, l, r, val);
		update(id<<1 | 1, mid, tr, l, r, val);
	}
	
	int get(int id, int tl, int tr, int pos){
		if (tr-tl==1) return seg[id];
		seg[id<<1]=min(seg[id<<1], seg[id]);
		seg[id<<1 | 1]=min(seg[id<<1 | 1], seg[id]);
		int mid=(tl+tr)>>1;
		if (pos<mid) return get(id<<1, tl, mid, pos);
		return get(id<<1 | 1, mid, tr, pos);
	}
	
	void dfs(int id, int tl, int tr, int A[]){
		if (tr-tl==1){
			A[tl]=seg[id];
			return ;
		}
		seg[id<<1]=min(seg[id<<1], seg[id]);
		seg[id<<1 | 1]=min(seg[id<<1 | 1], seg[id]);
		int mid=(tl+tr)>>1;
		dfs(id<<1, tl, mid, A);
		dfs(id<<1 | 1, mid, tr, A);
	}
} seg2;

int n, m, k, u, v, x, y, t, l, r, ans;
int A[MAXN];
bool mark[MAXN];
int T[MAXN], L[MAXN], R[MAXN], X[MAXN], Y[MAXN];
map<int, vector<int>> mp;
map<int, int> mpp;
vector<pii> V;

int f(int x){
	return (1<<(31-__builtin_clz(x)))-1;
}

void go(int pos){
	int num=A[pos];
	A[pos]=0;
	for (int i=30; i>=0; i--) if ((ans&(1<<i))==0 && (A[pos]|(1<<i))<=num) A[pos]|=(1<<i), ans|=(1<<i);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	debug(f(1061109567))
	cin>>n>>m;
	for (int i=1; i<=m; i++){
		cin>>T[i];
		if (T[i]==2){
			cin>>X[i]>>Y[i];
			seg1.update(1, 1, n+1, X[i], Y[i]);
			if (!mark[X[i]]){
				mark[X[i]]=1;
				V.pb({X[i], seg2.get(1, 1, n+1, X[i])});
			}
			continue ;
		}
		cin>>L[i]>>R[i]>>X[i];
		int mx=seg1.get(1, 1, n+1, L[i], R[i]+1);
		if (mx>X[i]) kill("NO")
		if (mx<X[i]) /*vec.pb(i), */mpp[X[i]]=i;
		seg2.update(1, 1, n+1, L[i], R[i]+1, X[i]);
	}
	seg2.dfs(1, 1, n+1, A);
	for (pii p:V) A[p.first]=p.second;
	
	//if (n==100 && m==300000) kill(A[90])
	
	seg1.build(1, 1, n+1, A);
	for (int i=1; i<=m; i++){
		if (T[i]==2) seg1.update(1, 1, n+1, X[i], Y[i]);
		else if (seg1.get(1, 1, n+1, L[i], R[i]+1)!=X[i]) kill("NO")
	}
	
	//cerr<<"A : ";for (int i=1; i<=n; i++) cerr<<A[i]<<" \n"[i==n];
	
	for (int i=1; i<=n; i++) mp[A[i]=min(A[i], inf)].pb(i);
	for (auto it:mp) if (it.first && mpp.count(it.first)){
		int l=L[mpp[it.first]], r=R[mpp[it.first]];
		bool flag=0;
		for (int i:it.second){
			if (l<=i && i<=r){
				if (!flag) flag=1;
				else A[i]=f(A[i]);
			}
			else A[i]=f(A[i]);
			ans|=A[i];
		}
	}
	
	for (auto it:mp) if (it.first && !mpp.count(it.first)) for (int i:it.second) go(i);
	
	
	cout<<"YES\n";
	for (int i=1; i<=n; i++) cout<<A[i]<<" \n"[i==n];
	debug(ans)
	
	return 0;
}
/*

*/