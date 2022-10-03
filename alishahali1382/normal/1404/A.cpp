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
#define kill(x) return cout<<x<<'\n', 0;

const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod=1000000007;
const int MAXN=300010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
char A[MAXN];
int B[MAXN];

int Solve(){
	cin>>n>>k;
	for (int i=1; i<=n; i++) cin>>A[i];
	int c0=0, c1=0, c2=0;
	for (int i=1; i<=k; i++){
		int tmp=-1;
		for (int j=i; j<=n; j+=k){
			if (A[j]=='?') continue ;
			if (tmp==-1){
				tmp=A[j]-'0';
				continue ;
			}
			if (tmp!=(A[j]-'0')) kill("NO")
		}
		B[i]=tmp;
		if (tmp==0) c0++;
		if (tmp==1) c1++;
		if (tmp==-1) c2++;
	}
	if (c0>k/2 || c1>k/2) kill("NO")
	kill("YES")
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int Test;
	cin>>Test;
	while (Test--) Solve();
	
	return 0;
}