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
#define getbit(x, y) (((x)>>(y))&1)

const int inf=1000000010;
const ll INF=1000000000000001000LL;
const int mod=998244353;
const int MAXN=500010;

int n, m, k, u, v, x, y, t, a, b, ans;
int A[MAXN], g[MAXN];
ll dp[MAXN];
int mark[MAXN];
string S;

int Main(){
	cin>>n>>S;
	int R=0, B=0;
	for (char ch:S){
		R+=(ch=='R');
		B+=(ch=='B');
	}
	int grundy=0;
	int len=0;
	for (int i=0; i<n; i++){
		if (i!=0 && S[i]==S[i-1]){
			grundy^=g[len];
			len=0;
		}
		len++;
	}
	grundy^=g[len];
	if (grundy!=0){
		if (R>=B) cout<<"Alice\n";
		else cout<<"Bob\n";
	}
	else{
		if (R>B) cout<<"Alice\n";
		else cout<<"Bob\n";
	}
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	
	for (int i=2; i<MAXN; i++){
		if (i>=100){
			g[i]=g[i-34];
			continue ;
		}
		for (int j=0; i-j-2>=j; j++){
			mark[g[j]^g[i-j-2]]=i;
		}
		while (mark[g[i]]==i) g[i]++;
	}
//	for (int i=0; i<=35; i++) cerr<<g[i]<<", ";cerr<<"\n";
//	for (int i=0; i<=35; i++) debug2(i, g[i])
//	return 0;
	
	int T=1;
	cin>>T;
	while (T--) Main();
	
	return 0;
}
/*

*/