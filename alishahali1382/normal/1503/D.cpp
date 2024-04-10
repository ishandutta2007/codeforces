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
const ll INF=1000000000000001000LL;
const int mod=1000000007;
const int MAXN=400010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
int bad[MAXN], match[MAXN], mark[MAXN];
int A[MAXN], B[MAXN];
int ted, cost;
int l, r;

void putdown(int i){ // put i in B down
	r--;
	B[r]=i;
	A[r]=match[i];
	mark[i]=mark[match[i]]=1;
	ted++;
	cost+=(bad[i]);
}
void putup(int i){ // put i in B up
	l++;
	B[l]=i;
	A[l]=match[i];
	mark[i]=mark[match[i]]=1;
	ted++;
	cost+=(bad[i]);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++){
		cin>>x>>y;
		bad[x]=1;
		match[x]=y;
		match[y]=x;
	}
	A[n+1]=B[0]=inf;
	int i=1, j=2*n;
	ted=0, cost=0;
	l=0; r=n+1;
	while (i<=j){
		if (mark[i]){
			i++;
			continue ;
		}
		if (mark[j]){
			j--;
			continue ;
		}
		bool okiA=(A[l]<i && i<A[r]);
		bool okjA=(A[l]<j && j<A[r]);
		bool okiB=(B[r]<i && i<B[l]);
		bool okjB=(B[r]<j && j<B[l]);
//		debug2(i, j)
//		debug2(okiA, okiB)
		if (!okiA && !okiB) kill(-1)
		if (!okjA && !okjB) kill(-1)
		if (!okiA){
			putdown(i);
			continue ;
		}
		if (!okiB){
			putup(match[i]);
			continue ;
		}
		if (!okjA){
			putup(j);
			continue ;
		}
		if (!okjB){
			putdown(match[j]);
			continue ;
		}
		ans+=min(cost, ted-cost);
		ted=cost=0;
		putup(j);
	}
	ans+=min(cost, ted-cost);
	for (int i=1; i<n; i++) if (A[i]>A[i+1] || B[i]<B[i+1]) kill(-1)
	cout<<ans<<"\n";
	
	return 0;
}