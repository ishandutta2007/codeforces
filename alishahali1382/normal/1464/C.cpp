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

ll n, m, k, u, v, x, y, t, a, b, ans;
ll A[26];
string S;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>k>>S;
	k-=(1<<(S[n-1]-'a'));
	k+=(1<<(S[n-2]-'a'));
	for (int i=0; i<n-2; i++) A[S[i]-'a']++;
	for (int i=25; ~i; i--){
		while (A[i] && k<=-(1ll<<i)) k+=(1ll<<i), A[i]--;
		while (A[i] && k>=+(1ll<<i)) k-=(1ll<<i), A[i]--;
		A[i]&=1;
		if (k<0) k+=(A[i]<<i);
		else k-=(A[i]<<i);
	}
	if (!k) kill("Yes")
	kill("No")
	
	return 0;
}