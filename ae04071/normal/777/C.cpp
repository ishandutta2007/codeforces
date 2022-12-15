#include <stdio.h>
#include <algorithm>
#include <vector>

std::vector<std::vector<int>> arr;
std::vector<int> idx;
int n,m,k;
int tree[1000001];

int Update(int node, int st, int fi, int idx, int val ){
	if(fi<idx||st>idx) return tree[node];
	else if(st==idx && fi==idx) {
		tree[node]=std::max(tree[node], val);
		return tree[node];
	}
	else
		return tree[node]=std::max(Update(node*2,st,(st+fi)/2,idx,val),Update(node*2+1,(st+fi)/2+1,fi,idx,val));
}
int Find(int node, int st, int fi, int le, int ri) {
	if(fi<le||st>ri) return 0;
	else if(le<=st&&fi<=ri) return tree[node];
	else return std::max(Find(node*2,st,(st+fi)/2,le,ri), Find(node*2+1,(st+fi)/2+1,fi,le,ri));
}

int main(){
	scanf("%d %d",&n,&m);
	arr.resize(n);
	for(int i=0;i<n;i++) {
		arr[i].resize(m);
		for(int j=0;j<m;j++) {
			scanf("%d",&arr[i][j]);
		}
	}

	for(int j=0;j<m;j++) {
		int st=0;
		for(int i=1;i<n;i++) {
			if(arr[i-1][j]>arr[i][j]) {
				Update(1,0,n-1, st, i-1);
				st=i;
			}
		}
		Update(1,0,n-1,st,n-1);
	}

	int l, r;
	scanf("%d",&k);
	while(k--) {
		scanf("%d %d",&l,&r);
		l--; r--;

		int idx=Find(1,0,n-1,0,l);
		if(idx>=r) printf("Yes\n");
		else printf("No\n");
	}

	return 0;
}