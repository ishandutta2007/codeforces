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
const int MAXN = 7010, LOG=20;

ll n, m, k, u, v, x, y, t, a, b, ans;
ll A[MAXN];
ll B[MAXN];
int cnt[MAXN];
bool mark[MAXN];

bool win(int i, int j){
	return A[i]&(~A[j]);
}

void Add(int i, int x){
	for (int j=1; j<=n; j++) if (win(j, i)) cnt[j]+=x;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++) cin>>A[i];
	for (int i=1; i<=n; i++) cin>>B[i], ans+=B[i];
	
	for (int i=1; i<=n; i++) Add(i, 1);
	//for (int i=1; i<=n; i++) for (int j=1; j<=n; j++) cerr<<win(i, j)<<" \n"[j==n];
	
	//for (int i=1; i<=n; i++) debug2(i, cnt[i])
	//return 0;
	
	int t=n;
	while (1){
		int v=-1;
		for (int i=1; i<=n; i++) if (cnt[i]==t-1) v=i;
		if (v==-1) break ;
		Add(v, -1);
		ans-=B[v];
		t--;
	}
	kill(ans)
	
	
	return 0;
}