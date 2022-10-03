#include <bits/stdc++.h>
#pragma GCC optimize ("O2,unroll-loops")

using namespace std;
#define all(x) x.begin(), x.end()
#define pb push_back
const int MAXN=100010, SQ=1200, NSQ=MAXN/SQ+1;

int n, m, k, u, v, x, y, t, a, b, ans;
int A[MAXN], typ[MAXN], Q[MAXN][2];
int cnt[NSQ][MAXN*2], C[NSQ][MAXN];
vector<int> comp;

inline void add(int id, int x){
	cnt[id][x]++;
	C[id][cnt[id][x]]++;
}
inline void rem(int id, int x){
	C[id][cnt[id][x]]--;
	cnt[id][x]--;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n;
	for (int i=0; i<n; i++) cin>>A[i], comp.pb(A[i]);
	cin>>m;
	for (int i=1; i<=m; i++){
		cin>>typ[i]>>Q[i][0]>>Q[i][1];
		if (typ[i]==1) comp.pb(Q[i][0]);
	}
	sort(all(comp));
	comp.resize(unique(all(comp))-comp.begin());
	for (int i=0; i<n; i++) A[i]=lower_bound(all(comp), A[i])-comp.begin();
	for (int i=1; i<=m; i++) if (typ[i]==1)
		Q[i][0]=lower_bound(all(comp), Q[i][0])-comp.begin();
	
	for (int id=0; SQ*id<n; id++){
		int tl=id*SQ;
		for (int i=0; i<tl; i++) add(id, A[i]); // :(
	}
	
	for (int i=1; i<=m; i++){
		if (typ[i]==1){
			x=Q[i][1], y=Q[i][0];
			x--;
			for (int j=x/SQ+1; j*SQ<n; j++) rem(j, A[x]), add(j, y);
			A[x]=y;
			continue ; 
		}
		x=Q[i][0], y=Q[i][1];
		y--;
		if (x==1){
			cout<<comp[A[y]]<<"\n";
			continue ;
		}
		int id=y/SQ, tl=id*SQ;
		for (int j=tl; j<=y; j++) add(id, A[j]);
		int ted=cnt[id][A[y]];
		if (x%2==0) cout<<ted<<"\n";
		else cout<<C[id][ted]<<"\n";
		for (int j=tl; j<=y; j++) rem(id, A[j]);
	}
	
	
	return 0;
}