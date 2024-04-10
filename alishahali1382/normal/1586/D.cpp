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

const int inf=1000000010;
const ll INF=1000000000000001000LL;
const int mod=1000000007;
const int MAXN=300010, LOG=20;

int n, m, mx, k, u, v, x, y, t, a, b, ans;
int A[MAXN], B[MAXN], shit[MAXN];

int ask(){
	cout<<"? ";
	for (int i=1; i<=n; i++) cout<<B[i]<<" ";
	cout<<endl;
	int x;
	cin>>x;
	return x;
}
void found(){
	cout<<"! ";
	for (int i=1; i<=n; i++) cout<<A[i]<<" ";
	cout<<endl;
	exit(0);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	mx=n;
	while (mx){
		int last=n;
		while (A[last]) last--;
		vector<pii> vec={{last, 0}};
		int x=1;
		while (x<n){
			for (int i=1; i<=n; i++) if (!A[i]) B[i]=1;
			B[last]=x+1;
			int k=ask();
			if (!k) break ;
			vec.pb({k, x});
			x++;
		}
		mx-=SZ(vec);
		for (pii p:vec){
			int i=p.first, j=p.second;
			A[i]=mx+j+1;
			B[i]=n;
		}
	}
	found();
	
	return 0;
}