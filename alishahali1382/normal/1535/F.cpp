#include <bits/stdc++.h>
#pragma GCC optimize ("O2,unroll-loops")

using namespace std;
typedef long long ll;
#define all(x) x.begin(), x.end()
#define pb push_back

const int MAXN=200010, LOG=18, SGM=26;

ll out, ans;
int n, m, k, u, v, x, y, t, a, b;
map<vector<int>, vector<string>> fuck;
int TR[MAXN][SGM], ts;
int par[LOG][MAXN];
int inc[MAXN], dest[MAXN];
vector<int> vec[MAXN];
string S[MAXN];

inline int Lcp(string &x, string &y){
	int res=0;
	while (res<m && x[res]==y[res]) res++;
	return res;
}
int Count(vector<int> &vec, int l, int r){ // [l...r)
	return lower_bound(all(vec), r)-lower_bound(all(vec), l);
}
int GetPar(int v, int k){
	for (int i=0; (1<<i)<=k; i++) if (k&(1<<i)) v=par[i][v];
	return v;
}
ll Solve(){
	if (m==1) return 1ll*n*(n-1)/2;
	sort(S, S+n);
	ll res=0;
	ts=0;
	memset(TR[0], 0, sizeof(TR[0]));
	vec[0].clear();
	for (int i=0; i<n; i++){
		vec[0].pb(i);
		int v=0;
		for (int j=m-1; ~j; j--){
			int c=S[i][j]-'a';
			if (!TR[v][c]){
				TR[v][c]=++ts;
				par[0][ts]=v;
				vec[ts].clear();
				memset(TR[ts], 0, sizeof(TR[ts]));
			}
			v=TR[v][c];
			vec[v].pb(i);
		}
		dest[i]=v;
	}
	for (int i=1; i<=ts; i++) sort(all(vec[i]));
	for (int j=1; j<LOG; ++j) for (int i=1; i<=ts; i++) par[j][i]=par[j-1][par[j-1][i]];
	for (int i=0; i<n; i++){
		inc[m-1]=m-1;
		for (int j=m-2; ~j; j--){
			if (S[i][j]<=S[i][j+1]) inc[j]=inc[j+1];
			else inc[j]=j;
		}
		int l=i+1;
		for (int lcp=m-1; ~lcp; lcp--){
			int dwn=l-1, up=n;
			while (up-dwn>1){
				int mid=(dwn+up)>>1;
				int tmp=Lcp(S[i], S[mid]);
				if (tmp<lcp) up=mid;
				else dwn=mid;
			}
			int r=up;
			if (l==r) continue ;
			res+=Count(vec[GetPar(dest[i], inc[lcp]+1)], l, r);
			l=r;
		}
	}
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=0; i<n; i++){
		cin>>S[i];
		vector<int> shit(26, 0);
		for (char ch:S[i]) shit[ch-'a']++;
		fuck[shit].pb(S[i]);
	}
	m=S[0].size();
	out=1337ll*n*(n-1)/2;
	for (auto p:fuck){
		n=0;
		for (string s:p.second) S[n++]=s;
		out-=1337ll*n*(n-1)/2;
		out+=2ll*n*(n-1)/2;
		ans+=Solve();
	}
	cout<<out-ans<<"\n";
	
	return 0;
}