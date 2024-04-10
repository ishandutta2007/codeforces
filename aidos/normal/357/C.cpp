#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#define pb push_back
#define ll long long
#define mp make_pair
#define ff first
#define sc second
#define pii pair<int,int>
#define pis pair<int, string>
#define psi pair<string, int>
#define MAXN 300010
using namespace std;
int v[4*MAXN], n, m, d[MAXN], lx, rx;
void Set(int l, int r, int x, int w = 1, int ql = 0, int qr = n-1){
	if(l>r) return;
	if(l == ql && qr == r){
		if(v[w] == -1){
			v[w] = x;
		}
	}
	else {
		if(v[w] == -1) {
			int mid = (ql + qr) >> 1;
			Set(l, min(r, mid), x, 2*w, ql, mid);
			Set(max(l, mid+1), r, x, 2*w+1, mid+1, qr);
		}
	}
}
void child(int w, int x){
	if(x!=-1){
		if(v[2*w] == -1) v[2*w] = x;
		if(v[2*w+1] == -1) v[2*w+1] = x;
	}	
}
int get(int f, int w =1,int l = 0, int r = n-1){
	if(l == r) return v[w];
	else {
		int mid = (l+r) >> 1;
		child(w, v[w]);
		if(mid>=f) return get(f, 2*w, l, mid);
		else return get(f, 2*w+1, mid+1, r);
	}
}
int main () {  
	int l, r, x, y;
	memset(v, -1, sizeof(v));
	memset(d, -1, sizeof(d));
	cin >> n >> m;
	for(int i =0; i<m; i++){
		scanf("%d%d%d", &lx, &rx, &x);
		lx--;
		rx--;
		Set(lx, x-2, x-1);
		Set(x, rx, x-1);
		y=x-1;
	}
	for(int i = 0; i<n; i++){
		if(i == y) printf("0 ");
		else printf("%d ", get(i) + 1);
	}
    return 0;
}