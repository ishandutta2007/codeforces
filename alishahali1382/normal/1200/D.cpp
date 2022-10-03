#include <bits/stdc++.h>
#pragma GCC optimize ("O2")
#pragma GCC optimize ("unroll-loops")

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
const int MAXN = 2010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
int A[MAXN][MAXN];
int ps1[MAXN][MAXN];
int ps2[MAXN][MAXN];
char ch;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>k;
	for (int i=1; i<=n; i++) for (int j=1; j<=n; j++){
		cin>>ch;
		A[i][j]=(ch=='B');
	}
	for (int i=1; i<=n; i++){
		int l=n+1, r=0;
		for (int j=1; j<=n; j++) if (A[i][j]) l=min(l, j), r=max(r, j);
		if (!r) ps1[1][1]++;
		else if (r<=l+k-1){
			ps1[max(1, i-k+1)][max(1, r-k+1)]++;
			ps1[max(1, i-k+1)][l+1]--;
			
			ps1[i+1][max(1, r-k+1)]--;
			ps1[i+1][l+1]++;
		}
	}
	for (int i=1; i<=n; i++) for (int j=1; j<=n; j++) ps1[i][j]+=ps1[i][j-1];
	for (int i=1; i<=n; i++) for (int j=1; j<=n; j++) ps1[i][j]+=ps1[i-1][j];
	
	for (int i=1; i<=n; i++) for (int j=i+1; j<=n; j++) swap(A[i][j], A[j][i]);
	
	for (int i=1; i<=n; i++){
		int l=n+1, r=0;
		for (int j=1; j<=n; j++) if (A[i][j]) l=min(l, j), r=max(r, j);
		if (!r) ps2[1][1]++;
		else if (r<=l+k-1){
			ps2[max(1, i-k+1)][max(1, r-k+1)]++;
			ps2[max(1, i-k+1)][l+1]--;
			
			ps2[i+1][max(1, r-k+1)]--;
			ps2[i+1][l+1]++;
		}
	}
	for (int i=1; i<=n; i++) for (int j=1; j<=n; j++) ps2[i][j]+=ps2[i][j-1];
	for (int i=1; i<=n; i++) for (int j=1; j<=n; j++) ps2[i][j]+=ps2[i-1][j];
	
	for (int i=1; i<=n; i++) for (int j=i+1; j<=n; j++) swap(ps2[i][j], ps2[j][i]);
	
	
	for (int i=1; i<=n; i++) for (int j=1; j<=n; j++) ans=max(ans, ps1[i][j]+ps2[i][j]);//, cerr<<ps1[i][j]+ps2[i][j]<<" \n"[j==n];
	cout<<ans<<'\n';
	
	return 0;
}