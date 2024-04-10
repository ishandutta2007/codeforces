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
const int N=550;

int n, m, k, u, v, x, y, t, a, b, ans;
int A[N], W[N], P[N];

int ask(){
	cout<<"? ";
	for (int i=1; i<=m; i++) cout<<A[i];
	cout<<endl;
	int x;
	cin>>x;
	return x;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for (int i=1; i<=m; i++){
		A[i]=1;
		W[i]=ask();
		A[i]=0;
		P[i]=i;
	}
	sort(P+1, P+m+1, [](int i, int j){
		return W[i]<W[j];
	});
	
	A[P[1]]=1;
	ans=W[P[1]];
	for (int i=2; i<=m; i++){
		int id=P[i];
		A[id]=1;
		int val=ask(), w=W[id];
		if (val==ans+w){
			ans+=w;
			continue ;
		}
		A[id]=0;
	}
	cout<<"! "<<ans<<endl;
	
	return 0;
}