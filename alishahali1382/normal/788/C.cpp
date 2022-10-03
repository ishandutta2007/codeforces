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
const int MAXN = 2010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
int dist[MAXN];
bool A[MAXN];
queue<int> Q;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>k;
	while (k--) cin>>x, A[x]=1;
	
	memset(dist, 63, sizeof(dist));
	dist[0]=0;
	Q.push(0);
	while (Q.size()){
		int v=Q.front();
		Q.pop();
		for (int i=0; i<=1000; i++) if (A[i]){
			int x=v+i-n;
			if (x==0) kill(dist[v]+1)
			if (x<0 || x>=MAXN || dist[x]<=dist[v]+1) continue ;
			dist[x]=dist[v]+1;
			Q.push(x);
		}
	}
	kill(-1)
	
	return 0;
}