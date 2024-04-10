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
const int MAXN=310, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
char A[MAXN][MAXN];
int ted[3], B[3];

int Solve(){
	cin>>n;
	k=ted[0]=ted[1]=ted[2]=0;
	for (int i=1; i<=n; i++) for (int j=1; j<=n; j++){
		cin>>A[i][j];
		if (A[i][j]=='.') continue ;
		ted[(i+j)%3]++;
		k++;
	}
	iota(B, B+3, 0);
	sort(B, B+3, [](int i, int j){
		return ted[i]>ted[j];
	});
	int bad=0, rev=0;
	for (int i=1; i<=n; i++) for (int j=1; j<=n; j++){
		int typ=(i+j)%3;
		if (A[i][j]=='.' || typ==B[0]) continue ;
		if (typ==B[1]) bad+=(A[i][j]!='X');
		if (typ==B[2]) bad+=(A[i][j]!='O');
	}
	if (bad*3>k) rev=1;
	for (int i=1; i<=n; i++) for (int j=1; j<=n; j++){
		int typ=(i+j)%3;
		if (A[i][j]=='.' || typ==B[0]) continue ;
		if ((typ==B[1]) ^ rev) A[i][j]='X';
		else A[i][j]='O';
	}
	for (int i=1; i<=n; i++){
		for (int j=1; j<=n; j++) cout<<A[i][j];
		cout<<"\n";
	}
	
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