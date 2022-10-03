#include <bits/stdc++.h>
#pragma GCC optimize ("O2")
#pragma GCC optimize ("unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")

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
const int MAXN = 200010, LOG=18;

int n, m, k, u, v, x, y, t, cnt;
int S[MAXN], A[MAXN], N;
int Rank[MAXN][LOG], P[MAXN], pw;
int B[MAXN];
ll ans[MAXN];
int seg[MAXN<<2];
map<int, int> mp;
string sss;

bool cmp(int x, int y){
	if (Rank[x][pw-1]!=Rank[y][pw-1]) return Rank[x][pw-1]<Rank[y][pw-1];
	if (max(x, y)+(1<<(pw-1))>N) return x>y;
	return Rank[x+(1<<(pw-1))][pw-1]<Rank[y+(1<<(pw-1))][pw-1];
}

void BuildShuffixArray(){
	for (int i=1; i<=N; i++) P[i]=i, Rank[i][0]=S[i];
	for (pw=1; pw<LOG; pw++){
		sort(P+1, P+N+1, cmp);
		Rank[P[1]][pw]=1;
		for (int i=2; i<=N; i++) Rank[P[i]][pw]=Rank[P[i-1]][pw] + cmp(P[i-1], P[i]);
	}
}

int Lcp(int x, int y){
	int res=0;
	for (int i=LOG-1; i>=0 && x<=N && y<=N; i--) if (Rank[x][i]==Rank[y][i] && max(x, y)+(1<<i)<=N){
		x+=(1<<i);
		y+=(1<<i);
		res|=(1<<i);
	}
	return res;
}

void add(int x){
	if (!x) return ;
	if (!mp[x]) cnt++;
	mp[x]++;
}

void rem(int x){
	if (!x) return ;
	mp[x]--;
	if (!mp[x]) cnt--;
}

void Maximize(int id, int tl, int tr, int l, int r, int val){
	//if (id==1) cerr<<"Maximize "<<l<<' '<<r<<"  "<<val<<endl;
	if (tr<=l || r<=tl) return ;
	if (l<=tl && tr<=r){
		seg[id]=max(seg[id], val);
		return ;
	}
	int mid=(tl+tr)>>1;
	Maximize(id<<1, tl, mid, l, r, val);
	Maximize(id<<1 | 1, mid, tr, l, r, val);
}

void dfs(int id, int tl, int tr){
	if (tr-tl==1){
		B[tl]=seg[id];
		return ;
	}
	seg[id<<1]=max(seg[id<<1], seg[id]);
	seg[id<<1 | 1]=max(seg[id<<1 | 1], seg[id]);
	int mid=(tl+tr)>>1;
	dfs(id<<1, tl, mid);
	dfs(id<<1 | 1, mid, tr);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>k;
	if (k==1){
		for (int i=1; i<=n; i++){
			cin>>sss;
			cout<<1ll*sss.size()*(sss.size()+1)/2<<' ';
		}
		return 0;
	}
	for (int i=1; i<=n; i++){
		cin>>sss;
		for (char ch:sss){
			S[++N]=ch-'a'+1;
			A[N]=i;
		}
		S[++N]=i+30;
	}
	
	//cerr<<"S : ";for (int i=1; i<=N; i++) cerr<<S[i]<<' ';cerr<<'\n';
	//debug(N)
	
	BuildShuffixArray();
	
	//cerr<<"P : ";for (int i=1; i<=N-n; i++) cerr<<P[i]<<' ';cerr<<'\n';
	
	
	//return 0;
	
	int j=1;
	for (int i=1; i<=N-n; i++){
		add(A[P[i]]);
		while (cnt>=k){
			Maximize(1, 1, N+1, j, i+1, Lcp(P[j], P[i]));
			rem(A[P[j++]]);
			if (cnt<k){
				add(A[P[--j]]);
				break ;
			}
		}
		//if (cnt>=k) debug2(j, i)
		if (cnt>=k) Maximize(1, 1, N+1, j, i+1, Lcp(P[j], P[i]));
	}
	dfs(1, 1, N+1);
	for (int i=1; i<=N; i++) ans[A[P[i]]]+=B[i];
	for (int i=1; i<=n; i++) cout<<ans[i]<<' ';
	
	return 0;
}
/*
3 3
aaa
aaaa
aaaaa

3 3
aa
aaa
aaaa

3 3
a
aa
aaa



*/