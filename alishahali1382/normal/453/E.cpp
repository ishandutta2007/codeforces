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
const int MAXN = 100010, LOG=20;

ll n, m, k, u, v, x, y, t, l, r, ans;
ll S[MAXN], M[MAXN], R[MAXN], D[MAXN];
int Mn[MAXN<<2], Mx[MAXN<<2], lazy[MAXN<<2];
vector<pii> seg[MAXN<<2];
vector<ll> ps1[MAXN<<2], ps2[MAXN<<2];

void Build(int id, int tl, int tr){
	if (tr-tl==1){
		seg[id].pb({D[tl], tl});
		ps1[id].pb(0);
		ps1[id].pb(R[tl]);
		ps2[id].pb(M[tl]);
		ps2[id].pb(0);
		return ;
	}
	int mid=(tl+tr)>>1;
	Build(id<<1, tl, mid);
	Build(id<<1 | 1, mid, tr);
	seg[id].resize(tr-tl);
	ps1[id].resize(tr-tl+1, 0);
	ps2[id].resize(tr-tl+1, 0);
	merge(all(seg[id<<1]), all(seg[id<<1 | 1]), seg[id].begin());
	ps1[id][0]=ps2[id][tr-tl]=0;
	for (int i=0; i<tr-tl; i++) ps1[id][i+1]=ps1[id][i]+M[seg[id][i].second];
	for (int i=tr-tl; i; i--) ps2[id][i-1]=ps2[id][i]+R[seg[id][i-1].second];
}

void add_lazy(int id, int val){
	lazy[id]=Mn[id]=Mx[id]=val;
}

void shift(int id){
	if (!lazy[id]) return ;
	add_lazy(id<<1, lazy[id]);
	add_lazy(id<<1 | 1, lazy[id]);
	lazy[id]=0;
}

void query(int id, int tl, int tr, int l, int r, int t){
	//debug2(tl, tr)
	if (tr<=l || r<=tl) return ;
	if (l<=tl && tr<=r && Mn[id]==Mx[id] && (Mn[id]!=-1 || tr-tl==1)){
		ll time=t-Mn[id];
		int shit=(Mn[id]==-1);
		add_lazy(id, t);
		if (tr-tl==1){
			time-=shit;
			//debug(time)
			ans+=min(M[tl], S[tl]+R[tl]*time);
			//debug(tl)
			S[tl]=0;
			return ;
		}
		int pos=upper_bound(all(seg[id]), pii(time, inf+1))-seg[id].begin();
		//debug2(time, pos)
		ans+=ps1[id][pos];
		ans+=ps2[id][pos]*time;
		return ;
	}
	shift(id);
	int mid=(tl+tr)>>1;
	query(id<<1, tl, mid, l, r, t);
	query(id<<1 | 1, mid, tr, l, r, t);
	Mn[id]=min(Mn[id<<1], Mn[id<<1 | 1]);
	Mx[id]=max(Mx[id<<1], Mx[id<<1 | 1]);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	memset(Mn, -1, sizeof(Mn));
	memset(Mx, -1, sizeof(Mx));
	cin>>n;
	for (int i=1; i<=n; i++) cin>>S[i]>>M[i]>>R[i], D[i]=(R[i]?(M[i]+R[i]-1)/R[i]:inf);
	Build(1, 1, n+1);
	/*
	for (pii p:seg[1]) debugp(p)
	debugv(ps1[1])
	debugv(ps2[1])
	*/
	cin>>m;
	while (m--){
		cin>>t>>l>>r;
		ans=0;
		query(1, 1, n+1, l, r+1, t);
		cout<<ans<<'\n';
	}
	
	
	return 0;
}
/*
7
0 4 2
0 3 0
0 96 7
0 25 9
0 90 4
0 93 5
0 87 3
3
0 1 7
3 3 4
10 1 7


7
0 4 2
0 3 0
0 96 7
0 25 9
0 90 4
0 93 5
0 87 3
2
3 3 4
10 1 7



ans:
46
198

*/