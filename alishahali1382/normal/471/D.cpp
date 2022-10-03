#include <bits/stdc++.h>
#pragma GCC optimize ("O2")

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
const int MAXN = 200010, LOG=20;

int n, m, k, u, v, x, y, a, b, ans;
int kmp1[MAXN];
int kmp2[MAXN];
int A[MAXN];
int B[MAXN];
int S[MAXN];
int T[MAXN];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	if (m==1) kill(n);
	for (int i=1; i<=n; i++) cin>>A[i];
	for (int i=1; i<n; i++) S[i]=A[i+1]-A[i];
	for (int i=1; i<=m; i++) cin>>B[i];
	for (int i=1; i<m; i++) T[i]=B[i+1]-B[i];
	/*
	for (int i=1; i<m; i++) cerr<<T[i]<<" \n"[i==m-1];
	for (int i=1; i<n; i++) cerr<<S[i]<<" \n"[i==n-1];
	debug("shit")
	*/
	int k=0;
	for (int i=2; i<m; i++){
		while (k && T[k+1]!=T[i]) k=kmp1[k];
		kmp1[i]=k+=(T[k+1]==T[i]);
	}
	k=0;
	for (int i=1; i<n; i++){
		if (k==m-1) k=kmp1[k];
		while (k && T[k+1]!=S[i]) k=kmp1[k];
		if (k<m-1 && T[k+1]==S[i]) k++;
		kmp2[i]=k;
		ans+=(k==m-1);
	}
	
	cout<<ans<<'\n';
	
	return 0;
}