#include <bits/stdc++.h>
#pragma GCC optimize ("O2,unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl;
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl;
#define debugv(v) {cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;}
#define all(x) x.begin(), x.end()
#define pb push_back
#define SZ(x) ((int)x.size())
#define kill(x) return cout<<x<<'\n', 0;
#define getbit(x, y) (((x)>>(y))&1)

const int inf=1000000010;
const ll INF=1000000000000001000LL;
const int mod=1000000007;
const int MAXN=100010, M=5;
typedef array<int, M> arr;

int n, m, k, u, v, x, y, t, a, b, sz;
int A[MAXN][M], W[MAXN];
pair<int, arr> AA[MAXN];
arr B[MAXN<<M], C[MAXN][1<<M];
int pos[MAXN][1<<M];
int cnt[MAXN<<M];

int Check(int val){
	memset(cnt, 0, sizeof(cnt));
	int res=0;
	int j=0;
	for (int i=n; i; i--){
		while (j<n && W[j+1]+W[i]<=val){
			j++;
			for (int mask=1; mask<(1<<m); mask++)
				cnt[pos[j][mask]]++;
		}
		res+=j;
		for (int mask=1; mask<(1<<m); mask++){
			int tmp=cnt[pos[i][mask]];
			if (__builtin_popcount(mask)&1) tmp=-tmp;
			res+=tmp;
		}
		if (res>0) return 1;
	}
	return (res>0);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	
	cin>>n>>m;
	for (int i=1; i<=n; i++){
		vector<int> vec(m);
		for (int j=0; j<m; j++) cin>>vec[j];
		sort(all(vec));
		for (int j=0; j<m; j++) AA[i].second[j]=vec[j];
		cin>>AA[i].first;
	}
	sort(AA+1, AA+n+1);
	for (int i=1; i<=n; i++){
		for (int j=0; j<m; j++) A[i][j]=AA[i].second[j];
		W[i]=AA[i].first;
	}
	// shit input done
	
	for (int i=1; i<=n; i++){
		for (int mask=1; mask<(1<<m); mask++){
			int p=0;
			for (int j=0; j<m; j++) if (getbit(mask, j)) C[i][mask][p++]=A[i][j];
			B[sz++]=C[i][mask];
		}
	}
	sort(B, B+sz);
	sz=unique(B, B+sz)-B;
	
	for (int i=1; i<=n; i++){
		for (int mask=1; mask<(1<<m); mask++){
			pos[i][mask]=lower_bound(B, B+sz, C[i][mask])-B;
		}
	}
	
	ll dwn=0, up=2*inf;
	while (up-dwn>1){
		ll mid=(dwn+up)>>1;
		if (Check(mid)) up=mid;
		else dwn=mid;
	}
	if (up==2*inf) cout<<"-1\n";
	else cout<<up<<"\n";
	
	return 0;
}