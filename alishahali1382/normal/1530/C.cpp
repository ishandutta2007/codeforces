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

int n, m, k, u, v, x, y, t, a, b, ans;
int A[MAXN], B[MAXN];

struct SHIT{
	int sum=0;
	priority_queue<int> mn;
	priority_queue<int, vector<int>, greater<int>> mx;
	void Add(int x){
		if (mx.empty() || mx.top()>x) mn.push(x);
		else mx.push(x), sum+=x;
	}
	int Get(int k){
		while (SZ(mx)>k){
			int x=mx.top();
			mx.pop();
			mn.push(x);
			sum-=x;
		}
		while (SZ(mx)<k){
			int x=mn.top();
			mn.pop();
			mx.push(x);
			sum+=x;
		}
		return sum;
	}
	void clr(){
		while (mn.size()) mn.pop();
		while (mx.size()) mx.pop();
		sum=0;
	}
} X, Y;

int Solve(){
	int sum=0;
	X.clr();
	Y.clr();
	cin>>n;
	for (int i=1; i<=n; i++) cin>>A[i], X.Add(A[i]);
	for (int i=1; i<=n; i++) cin>>B[i], Y.Add(B[i]);
//	sort(A+1, A+n+1);
//	reverse(A+1, A+n+1);
//	sort(B+1, B+n+1);
//	reverse(B+1, B+n+1);
//	for (int i=1; i<=n-n/4; i++) sum+=B[i]-A[i];
	
	int ans=0;
	while (X.Get(n-n/4)<Y.Get(n-n/4)){
//		debug(X.Get(n-n/4))
//		debug(Y.Get(n-n/4))
//		cerr<<"\n";
		ans++;
		n++;
		X.Add(100);
		Y.Add(0);
	}
	
	kill(ans)
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int T;
	cin>>T;
	while (T--) Solve();
	
	return 0;
}
/*
1
4
10 20 30 40
100 100 100 100

*/