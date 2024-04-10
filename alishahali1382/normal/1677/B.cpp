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
const int MAXN=1000010;

int n, m, k, u, v, x, y, t, a, b;
int A[MAXN], B[MAXN];
string S;

int Main(){
	cin>>n>>m>>S;
	for (int i=0; i<=n*m; i++) A[i]=0, B[i]=0;
	
	int p=0;
	int ted=0, last=-inf;
	for (int i=0; i<n; i++){
		ll curr=0;
		for (int j=0; j<m; j++){
			if (S[p++]=='1'){
				if (!B[j]){
					ted++;
					B[j]=1;
				}
				last=p;
			}
			A[j]+=(p-last<m);
			
//			debug2(i, j)
//			debug2(ted, A[j])
			
			cout<<ted+A[j]<<" ";
//			cerr<<"\n";
		}
	}
	
	cout<<"\n";
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
2 2
1100


*/