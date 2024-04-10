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
#define debugv(v) {cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;}
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod=1000000007;
const int MAXN=200010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, shit;
int A[MAXN], B[MAXN], P[MAXN];
int L[MAXN], R[MAXN];
//bool mark[MAXN], mark2[MAXN];
vector<pii> vec[MAXN];
vector<int> path, G[MAXN];
set<int> mark, mark2;
priority_queue<pii, vector<pii>, greater<pii>> pq;

void dfs(int node){
	mark2.insert(A[node]);
	mark.erase(A[node]);
	path.pb(node);
	
	while (1){
		auto it=mark2.lower_bound(L[node]);
		if (it==mark2.end() || *it>R[node]) break ;
		int v=P[*it];
		if (v==node){
			it++;
			if (it==mark2.end() || *it>R[node]) break ;
		}
		v=P[*it];
		
		if (1){
			vector<int> vec;
			while (path.back()!=v){
				vec.pb(path.back());
				path.pop_back();
			}
			vec.pb(v);
			reverse(all(vec));
			//debugv(vec)
			int len=vec.size();
			for (int i=0; i<len; i++) B[vec[i]]=A[vec[(i+1)%len]];
			
			
			cout<<"NO\n";
			for (int i=1; i<=n; i++) cout<<A[i]<<" \n"[i==n];
			for (int i=1; i<=n; i++) cout<<B[i]<<" \n"[i==n];
			exit(0);
		}
	}
	while (1){
		auto it=mark.lower_bound(L[node]);
		if (it==mark.end() || *it>R[node]) break ;
		int v=P[*it];
		dfs(v);
	}
	
	mark2.erase(A[node]);
	path.pop_back();
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++){
		cin>>L[i]>>R[i];
		vec[L[i]].pb({R[i], i});
	}
	for (int i=1; i<=n; i++){
		for (pii p:vec[i]) pq.push(p);
		pii p=pq.top();
		pq.pop();
		A[p.second]=i;
	}
	for (int i=1; i<=n; i++) P[A[i]]=i;
	
	for (int i=1; i<=n; i++){
		B[i]=A[i];/*
		for (int j=L[i]; j<=R[i] && shit<=2*n; j++){
			int u=P[j], v=i;
			if (u==v) continue ;
			
			G[u].pb(v);
			shit++;
		}*/
	}
	for (int i=1; i<=n; i++) mark.insert(i);
	for (int i=1; i<=n; i++) if (mark.count(i)) dfs(P[i]);
	
	cout<<"YES\n";
	for (int i=1; i<=n; i++) cout<<A[i]<<' ';cout<<'\n';
	
	return 0;
}