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
const int MAXN = 1000010, SQ=330;

ll n, m, k, u, v, x, y, t, a, b, val;
int A[MAXN];
int cnt[MAXN*2];
ll ans[MAXN];
piii Q[MAXN];

bool cmp(piii p, piii q){
	int a=p.first.first/SQ, b=q.first.first/SQ;
	if (a==b) return p.first.second<q.first.second^(a&1);
	return a<b;
}

void Add(int x){
	val+=cnt[x^k];
	cnt[x]++;
}

void Rem(int x){
	cnt[x]--;
	val-=cnt[x^k];
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m>>k;
	for (int i=1; i<=n; i++) cin>>A[i], A[i]^=A[i-1];
	for (int i=1; i<=m; i++){
		cin>>a>>b;
		Q[i]={{a-1, b+1}, i};
	}
	sort(Q+1, Q+m+1, cmp);
	int L=0, R=0;
	for (int i=1; i<=m; i++){
		int l=Q[i].first.first, r=Q[i].first.second;
		while (l<L) Add(A[--L]);
		while (R<r) Add(A[R++]);
		while (L<l) Rem(A[L++]);
		while (r<R) Rem(A[--R]);
		ans[Q[i].second]=val;
	}
	
	for (int i=1; i<=m; i++) cout<<ans[i]<<'\n';
	
	return 0;
}