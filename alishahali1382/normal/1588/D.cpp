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
#define get(x, y) (((x)>>(y))&1)

const int inf=1000000010;
const ll INF=1000000000000001000LL;
const int mod=1000000007;
const int N=10, SGM=52;

int n, m, k, u, v, x, y, t, a, b, ans;
int A[N][2*SGM+10], sz[N];
int pos[N][SGM][2];
int dp[2*SGM+10][1<<(N-1)];
pii par[2*SGM+10][1<<(N-1)];

inline int char_to_int(char c){
	if ('A'<=c && c<='Z') return c-'A';
	return c-'a'+26;
}
inline char int_to_char(int x){
	if (x<26) return 'A'+x;
	return 'a'+x-26;
}
inline void upd(int i, int j, int ii, int jj){
	if (dp[i][j]<dp[ii][jj]+1){
		dp[i][j]=dp[ii][jj]+1;
		par[i][j]={ii, jj};
	}
}
void Solve(){
	memset(A, 0, sizeof(A));
	memset(pos, 0, sizeof(pos));
	memset(sz, 0, sizeof(sz));
	memset(dp, 0, sizeof(dp));
	memset(par, 0, sizeof(par));
	cin>>n;
	for (int i=0; i<n; i++){
		string S;
		cin>>S;
		for (char c:S){
			A[i][++sz[i]]=char_to_int(c);
			if (pos[i][A[i][sz[i]]][0]) pos[i][A[i][sz[i]]][1]=sz[i];
			else pos[i][A[i][sz[i]]][0]=sz[i];
		}
		for (int j=0; j<SGM; j++) for (int jj:{0, 1}) if (!pos[i][j][jj]) pos[i][j][jj]=sz[i]+1;
	}
	n--;
	ans=0;
	int cur_i=0, cur_mask=0;
	for (int i=1; i<=sz[n]; i++){
		for (int mask=0; mask<(1<<n); mask++){
			int bad=0, c=A[n][i];
			for (int j=0; j<n; j++)
				if (pos[j][c][get(mask, j)]>sz[j]) bad=1;
			if (bad) continue ;
			dp[i][mask]=1;
			for (int ii=1; ii<i; ii++){
				int mask2=0, cc=A[n][ii], bad=0;
				if (!dp[ii][0]) continue ;
				for (int j=0; j<n && !bad; j++){
					int p=pos[j][c][get(mask, j)];
					if (pos[j][cc][1]<p) mask2|=(1<<j);
					else if (pos[j][cc][0]>=p) bad=1;
				}
				if (!bad) upd(i, mask, ii, mask2);
			}
			if (ans<dp[i][mask]){
				ans=dp[i][mask];
				cur_i=i;
				cur_mask=mask;
			}
		}
	}
	string S;
	while (cur_i){
		if (A[n][cur_i]<26) S+=char(A[n][cur_i]+'A');
		else S+=char(A[n][cur_i]-26+'a');
		pii p=par[cur_i][cur_mask];
		cur_i=p.first;
		cur_mask=p.second;
	}
//	debug(S)
	reverse(all(S));
	cout<<ans<<"\n"<<S<<"\n";
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while (T--) Solve();
	
	return 0;
}
/*
1
2
ABC
CBA

1
2
bacab
defed

1
3
abcde
aBcDe
ace

1
2
codeforces
technocup

*/