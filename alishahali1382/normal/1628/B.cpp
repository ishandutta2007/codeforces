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
const int mod=1000000007;
const int MAXN=300010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
int A[MAXN];
string S[MAXN];
map<string, int> shit;

int Main(){
	shit.clear();
	cin>>n;
	for (int i=1; i<=n; i++) cin>>S[i];
	for (int i=1; i<=n; i++) if (S[i][0]==S[i].back()) kill("YES")
	for (int i=1; i<=n; i++){
		shit[S[i]]=1;
		string T=S[i];
		reverse(all(T));
		if (shit[T]) kill("YES")
		if (SZ(S[i])==2){
			for (char c='a'; c<='z'; c++) if (shit[T+c]) kill("YES")
		}
		else{
			assert(SZ(S[i])==3);
			T.pop_back();
			if (shit[T]) kill("YES");
		}
	}
	kill("NO")
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while (T--) Main();
	
	return 0;
}
/*
1
2
ab
bad

*/