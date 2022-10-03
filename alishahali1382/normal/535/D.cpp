#include <bits/stdc++.h>
#pragma GCC optimize ("O2")
#pragma GCC optimize ("unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl;
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl;
#define debugv(v) cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 1000010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans=1;
int ps[MAXN];
int f[MAXN];
int Y[MAXN];
bool good[MAXN];
string S;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m>>S;
	k=S.size();
	for (int i=1; i<=m; i++){
		cin>>Y[i];
		ps[Y[i]]++;
		ps[Y[i]+k]--;
	}
	
	int curr=0;
	for (int i=1; i<k; i++){
		while (curr && S[curr]!=S[i]) curr=f[curr];
		f[i+1]=curr+=(S[curr]==S[i]);
	}
	for (curr=k; curr; curr=f[curr]) good[curr]=1;
	for (int i=1; i<m; i++) if (Y[i+1]-Y[i]<k && !good[k-(Y[i+1]-Y[i])]) kill(0)
	for (int i=1; i<=n; i++) if (!(ps[i]+=ps[i-1])) ans=ans*26ll%mod;
	cout<<ans<<'\n';
	
	return 0;
}