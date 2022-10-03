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

int n, m, k, u, v, x, y, t, a, b, ans;
int A[MAXN];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n;
	if (n==1){
		// why?
		cout<<"1\n";
		cout<<"1 1\n";
		return 0;
	}
	t=n/3;
	if (n%3){
		k=2*t+1;
		cout<<k<<"\n";
		for (int i=1; i<=t+1; i++) cout<<i<<" "<<t+2-i<<"\n";
		for (int i=1; i<=t; i++) cout<<i+(t+1)<<" "<<t+1-i+(t+1)<<"\n";
		return 0;
	}
	k=2*t;
	cout<<k<<"\n";
	for (int i=1; i<=t; i++) cout<<i<<" "<<t+1-i<<"\n";
	for (int i=1; i<=t-1; i++) cout<<i+(t)<<" "<<t-i+(t)<<"\n";
	cout<<k<<" "<<k<<"\n";
	
	return 0;
}