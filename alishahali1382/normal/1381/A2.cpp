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
const int MAXN=100010, LOG=20;

int n, m, k, u, v, x, y, t, L, R, X;
int A[MAXN], B[MAXN];
vector<int> out;

void Solve(){
	out.clear();
	cin>>n;
	for (int i=1; i<=n; i++){
		char ch;
		cin>>ch;
		A[i]=(ch-'0');
	}
	for (int i=1; i<=n; i++){
		char ch;
		cin>>ch;
		B[i]=(ch-'0');
	}
	L=1;
	R=n;
	X=0;
	for (int i=n; i; i--){
		int a1, ai;
		if (X) ai=(A[L]^X), a1=(A[R]^X);
		else ai=(A[R]^X), a1=(A[L]^X);
		
//		debug2(i, X)
//		debug2(L, R)
//		cerr<<"\n";
		
		if (ai==B[i]){
			if (X) L++;
			else R--;
			continue ;
		}
		if (a1==B[i]){
			out.pb(1);
			if (X) A[R]^=1;
			else A[L]^=1;
		}
		out.pb(i);
		if (!X) L++;
		else R--;
		X^=1;
	}
	cout<<out.size()<<"\n";
	for (int i:out) cout<<i<<' ';
	cout<<"\n";
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
/*
1
2
01
10

1
5
01011
11100

1
3
110
111

1
10
0110011011
1000110100


*/