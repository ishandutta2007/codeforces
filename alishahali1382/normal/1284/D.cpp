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
const int MAXN = 100010, LOG=18;

struct BAZE{
	int l, r, L, R;
	bool operator <(BAZE X){
		return R<X.R;
	}
} A[MAXN];

int n, m, k, u, v, x, y, t, a, b, ans;
int shit[MAXN];
int spl[MAXN][LOG], spr[MAXN][LOG];

int getl(int l, int r){
	int lg=log2(r-l);
	return max(spl[l][lg], spl[r-(1<<lg)][lg]);
}

int getr(int l, int r){
	int lg=log2(r-l);
	return min(spr[l][lg], spr[r-(1<<lg)][lg]);
}

void solve(){
	sort(A+1, A+n+1);
	for (int i=1; i<=n; i++) shit[i]=A[i].R;
	memset(spl, 0, sizeof(spl));
	memset(spr, 63, sizeof(spr));
	for (int i=1; i<=n; i++) spl[i][0]=A[i].l;
	for (int i=1; i<=n; i++) spr[i][0]=A[i].r;
	for (int j=1; j<LOG; j++) for (int i=1; i+(1<<j)<MAXN; i++){
		spl[i][j]=max(spl[i][j-1], spl[i+(1<<(j-1))][j-1]);
		spr[i][j]=min(spr[i][j-1], spr[i+(1<<(j-1))][j-1]);
	}
	
	for (int i=1; i<=n; i++){
		int l=lower_bound(shit+1, shit+n+1, A[i].L)-shit, r=i;
		if (r<=l) continue ;
		if (getl(l, r)>A[i].r || getr(l, r)<A[i].l){
			cout<<"NO\n";
			exit(0);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++) cin>>A[i].l>>A[i].r>>A[i].L>>A[i].R;
	solve();
	//debug("shit")
	for (int i=1; i<=n; i++) swap(A[i].l, A[i].L), swap(A[i].r, A[i].R);
	solve();
	cout<<"YES\n";
	
	return 0;
}

/*
2
1 3 2 4
3 4 5 5

*/