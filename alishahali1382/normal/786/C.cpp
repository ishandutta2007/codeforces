#include <bits/stdc++.h>
#pragma GCC optimize ("O2,unroll-loops")

using namespace std;

const int MAXN = 100010, Z=20*MAXN;

int n, m, k, u, v, x, y, t, a, b;
int A[MAXN], last[MAXN];
int prv[MAXN];
int seg[Z], L[Z], R[Z], ts=1;
int root[MAXN];
vector<int> vec[MAXN];

int Set(int id, int tl, int tr, int pos){
	if (tr<=pos || pos<tl) return id;
	int res=ts++;
	if (tr-tl==1){
		seg[res]=1;
		return res;
	}
	int mid=(tl+tr)>>1;
	L[res]=Set(L[id], tl, mid, pos);
	R[res]=Set(R[id], mid, tr, pos);
	seg[res]=seg[L[res]]+seg[R[res]];
	return res;
}

int BS(int id, int tl, int tr, int k){
	if (tr-tl==1) return tl+(k-seg[id]);
	int mid=(tl+tr)>>1;
	if (seg[L[id]]>=k) return BS(L[id], tl, mid, k);
	return BS(R[id], mid, tr, k-seg[L[id]]);
}

int solve(int k){
	int ans=0;
	for (int curr=1; curr<=n; ans++) curr=BS(root[curr], 0, n+1, k+curr);
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++){
		cin>>A[i];
		prv[i]=last[A[i]];
		last[A[i]]=i;
		vec[prv[i]].push_back(i);
	}
	for (int i=1; i<=n; i++){
		root[i]=root[i-1];
		for (int j:vec[i-1]) root[i]=Set(root[i], 0, n+1, j);
	}
	
	for (int i=1; i<=n; i++) cout<<solve(i)<<' ';
	
	return 0;
}