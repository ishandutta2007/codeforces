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

const int inf=1000000010;
const ll INF=1000000000000001000LL;
const int mod=1000000007;
const int MAXN=200010, SQ=1000;

int n, m, k, u, v, x, y, t, a, b, ans, D;
int X[MAXN], Y[MAXN], day[MAXN];
int ps[MAXN*2];
int lazy[SQ][SQ];

void Add(int d, int x, int y, int w){
	y+=x;
	if (y<SQ){
		d%=y;
		while (x--){
			lazy[y][d]+=w;
			d++;
			if (d==y) d=0;
		}
		return ;
	}
	while (1ll*d+x<D) d+=y;
	while (d<=m){
		ps[max(D, d)]+=w;
		d+=x;
		if (d>m) break ;
		ps[d]-=w;
		d+=y-x;
	}
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	for (int i=1; i<=n; i++){
		cin>>X[i]>>Y[i];
//		Add(0, X[i], Y[i], +1);
	}
	int tot=0;
	for (int i=1; i<=m; i++){
		D=i;
		cin>>t>>k;
		if (t==1){
			tot++;
			Add(day[k]=i, X[k], Y[k], +1);
		}
		else{
			tot--;
			Add(day[k], X[k], Y[k], -1);
		}
		ps[i]+=ps[i-1];
		
		ans=ps[i];
		for (int j=2; j<SQ; j++) ans+=lazy[j][i%j];
//		debug2(ps[i], ans)
		cout<<tot-ans<<"\n";
	}
	
	return 0;
}