#include <bits/stdc++.h>
#pragma GCC optimize ("O2,unroll-loops")

using namespace std;
typedef pair<int, int> pii;
const int inf=1000000010;
const int MAXN = 200010, LOG=18;

int n, m, k, u, v, x, y, t, a, b;
long long ans;
int A[MAXN];
int par[MAXN], comp;
pii dp[1<<LOG];
vector<int> vec[MAXN];

int get(int x){
	if (par[x]==x) return x;
	return par[x]=get(par[x]);
}

void join(int x, int y, int w){
	x=get(x);
	y=get(y);
	if (x==y) return ;
	comp--;
	ans+=w;
	par[y]=x;
}

inline pii combine(pii i, pii j){
	if (i.first<j.first) swap(i, j);
	if (get(i.first)!=get(j.first) && j.first>i.second) swap(i.second, j.first);
	if (get(i.first)!=get(j.second) && j.second>i.second) swap(i.second, j.second);
	return i;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n;
	for (int i=1; i<=n; i++) cin>>A[i], ans-=A[i];
	A[0]=-inf;
	sort(A+1, A+n+2);
	iota(par, par+n+2, 0);
	comp=n+1;
	while (comp>1){
		memset(dp, 0, sizeof(dp));
		for (int i=1; i<=n+1; i++) dp[A[i]]=combine(dp[A[i]], pii(i, 0));
		for (int j=0; j<LOG; j++) for (int i=(1<<LOG)-1; ~i; i--) if (i&(1<<j)) dp[i]=combine(dp[i], dp[i^(1<<j)]);
		for (int i=1; i<=n+1; i++) vec[get(i)].push_back(i);
		for (int i=1; i<=n+1; i++) if (par[i]==i){
			pii e={-inf, -1};
			for (int x:vec[i]){
				int tmp=(1<<LOG)-1-A[x];
				if (get(dp[tmp].first)==i) e=max(e, pii(A[dp[tmp].second]+A[x], dp[tmp].second));
				else e=max(e, pii(A[dp[tmp].first]+A[x], dp[tmp].first));
			}
			join(i, e.second, e.first);
			vec[i].clear();
		}
	}
	cout<<ans<<'\n';
	
	return 0;
}