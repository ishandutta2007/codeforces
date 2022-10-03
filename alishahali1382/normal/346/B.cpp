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
const int MAXN = 110, LOG=20;

int n, m, k, u, v, x, y, a, b, ans;
int f[MAXN];
int nxt[MAXN][26];
int dp[MAXN][MAXN][MAXN];
piii par[MAXN][MAXN][MAXN];
string S, T, virus;

void upd(int a, int b, int c, int aa, int bb, int cc, int tmp){
	if (c==k) return ;
	if (dp[a][b][c]<=dp[aa][bb][cc]+tmp){
		dp[a][b][c]=dp[aa][bb][cc]+tmp;
		par[a][b][c]={{aa, bb}, cc};
	}
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>S>>T>>virus;
	n=S.size(); S="."+S;
	m=T.size(); T="."+T;
	k=virus.size(); virus="#"+virus;
	
	int curr=0;
	for (int i=2; i<=k; i++){
		while (curr && virus[curr+1]!=virus[i]) curr=f[curr];
		f[i]=curr+=(virus[curr+1]==virus[i]);
	}
	//for (int i=1; i<=k; i++) cerr<<f[i]<<" \n"[i==k];
	
	nxt[0][virus[1]-'A']=1;
	for (int i=1; i<=k; i++){	
		for (int j=0; j<26; j++){
			if (i!=k && j==virus[i+1]-'A') nxt[i][j]=i+1;
			else nxt[i][j]=nxt[f[i]][j];
		}
	}
	
	/*
	for (int i=0; i<=k; i++) cerr<<i<<" : "<<nxt[i][0]<<' '<<nxt[i][1]<<endl;
	debug(nxt[1][0])
	return 0;
	*/
	/*
	debug(nxt[0][0])
	debug(nxt[1][1])
	*/
	
	for (int i=1; i<=n; i++) for (int j=1; j<=m; j++){
		for (int x=0; x<k; x++){
			upd(i, j, x, i-1, j, x, 0);
			upd(i, j, x, i, j-1, x, 0);
		}
		if (S[i]==T[j]){
			for (int x=0; x<k; x++) upd(i, j, nxt[x][S[i]-'A'], i-1, j-1, x, 1);
		}
	}
	
	int a=n, b=m, c=0;
	for (int i=1; i<k; i++) if (dp[n][m][i]>dp[n][m][c]) c=i;
	
	//debug(c)
	//debug(dp[a][b][c])
	
	string out="";
	while (a){
		int aa=par[a][b][c].first.first, bb=par[a][b][c].first.second, cc=par[a][b][c].second;
		//cerr<<a<<' '<<b<<' '<<c<<"  -->  "<<aa<<' '<<bb<<' '<<cc<<endl;
		if (aa!=a && bb!=b) out+=S[a];
		a=aa;
		b=bb;
		c=cc;
	}
	reverse(all(out));
	if (out.empty()) out="0";
	cout<<out<<endl;
	
	return 0;
}
/*
AB
AB
AB


*/