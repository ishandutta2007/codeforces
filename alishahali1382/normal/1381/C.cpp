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

int n, m, k, u, v, x, y, t, a, b, shit;
int A[MAXN], B[MAXN];
vector<int> vec[MAXN];
priority_queue<pii> pq;

int Solve(){
	while (pq.size()) pq.pop();
	cin>>n>>x>>y;
	int z=y-x, t=n-y;
	for (int i=1; i<=n+1; i++) vec[i].clear();
	for (int i=1; i<=n; i++) cin>>B[i], vec[B[i]].pb(i);
	for (int i=1; i<=n+1; i++){
		if (vec[i].size()) pq.push({vec[i].size(), i});
		else shit=i;
	}
	for (int i=0; i<x; i++){
		pii p=pq.top();
		pq.pop();
		int col=p.second;
		A[vec[col].back()]=col;
		vec[col].pop_back();
		if (--p.first) pq.push(p);
	}
	// ---------------------------
	while (z>1){
		if (z==3 && pq.size()>=3){
			pii c1=pq.top();pq.pop();
			pii c2=pq.top();pq.pop();
			pii c3=pq.top();pq.pop();
			A[vec[c1.second].back()]=c2.second;
			A[vec[c2.second].back()]=c3.second;
			A[vec[c3.second].back()]=c1.second;
			vec[c1.second].pop_back();
			vec[c2.second].pop_back();
			vec[c3.second].pop_back();
			z-=3;
			if (--c1.first) pq.push(c1);
			if (--c2.first) pq.push(c2);
			if (--c3.first) pq.push(c3);
		}
		else if (z>=2 && pq.size()>=2){
			pii p1=pq.top();pq.pop();
			pii p2=pq.top();pq.pop();
			A[vec[p1.second].back()]=p2.second;
			A[vec[p2.second].back()]=p1.second;
			vec[p1.second].pop_back();
			vec[p2.second].pop_back();
			if (--p1.first) pq.push(p1);
			if (--p2.first) pq.push(p2);
			z-=2;
		}
		else{
			break ;
		}
	}
	// ----------------------------
	
	for (int i=n-y; i; i--){
		pii p=pq.top();
		pq.pop();
		int col=p.second;
		if (pq.size() && z){
			pii pp=pq.top();pq.pop();			
			z--;
			int col2=pp.second;
			A[vec[col2].back()]=shit;
			A[vec[col].back()]=col2;
			vec[col2].pop_back();
			vec[col].pop_back();
			if (--pp.first) pq.push(pp);
			if (--p.first) pq.push(p);
		}
		else{
			A[vec[col].back()]=shit;
			vec[col].pop_back();
			if (--p.first) pq.push(p);
		}
	}
	if (pq.size()) kill("NO")
	
	cout<<"YES\n";
	for (int i=1; i<=n; i++) cout<<A[i]<<" \n"[i==n];
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
be careful:  y=2 x=1     y-x=1

7
5 2 4
3 1 1 2 5
5 3 4
1 1 2 1 2
4 0 4
5 5 3 3
4 1 4
2 3 2 3
6 1 2
3 2 1 1 1 1
6 2 4
3 3 2 1 1 1
6 2 6
1 1 3 2 1 1

1
4 0 4
5 5 3 3

1
6 1 2
3 2 1 1 1 1

1
5 2 4
3 1 1 2 5

*/