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
const int MAXN=300010;

int n, m, k, u, v, x, y, t, a, b, c, ans;
vector<int> A[MAXN];

bool is_ok(int i){
	for (int j=1; j<m; j++) if (A[i][j]<A[i][j-1]) return 0;
	return 1;
}

int Main(){
	cin>>n>>m;
	for (int i=0; i<n; i++){
		A[i].resize(m);
		for (int j=0; j<m; j++) cin>>A[i][j];
	}
	x=y=-1;
	for (int i=0; i<n && x==-1; i++){
		int l=-1, r=-1;
		for (int j=1; j<m; j++){
			if (A[i][j]<A[i][j-1]){
				if (l==-1) l=j-1;
				r=j;
			}
		}
		if (l!=-1){
			while (l && A[i][l-1]==A[i][l]) l--;
			while (r+1<m && A[i][r+1]==A[i][r]) r++;
//			debug2(l, r)
			x=l;
			y=r;
		}
	}
	if (x==-1) x=y=0;
	for (int i=0; i<n; i++){
		swap(A[i][x], A[i][y]);
		if (!is_ok(i)) kill(-1)
	}
	cout<<x+1<<" "<<y+1<<"\n";
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while (T--) Main();
	
	return 0;
}
/*
1
2 3
6 2 1
5 4 3


*/