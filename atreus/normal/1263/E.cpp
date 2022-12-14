#include <bits/stdc++.h>
using namespace std;
#define mxm first
#define mnm second
typedef long long ll;
 
const int maxn = 1e6 + 5;
 
pair<int, int> seg[4 * maxn];
int lazy[4 * maxn];
int a[maxn];
 
void propagate(int, int, int);
 
void add(int id, int L, int R, int l, int r, int val){
	if (r <= L or R <= l)
		return;
	if (l <= L and R <= r){
		seg[id].mxm += val;
		seg[id].mnm += val;
		lazy[id] += val;
		return;
	}
	propagate(id, L, R);
	int mid = (L + R) >> 1;
	add(2 * id + 0, L, mid, l, r, val);
	add(2 * id + 1, mid, R, l, r, val);
	seg[id].mxm = max(seg[2 * id + 0].mxm, seg[2 * id + 1].mxm);
	seg[id].mnm = min(seg[2 * id + 0].mnm, seg[2 * id + 1].mnm);
}
 
void propagate(int id, int L, int R){
	if (lazy[id] == 0)
		return;
	int mid = (L + R) >> 1;
	add(2 * id + 0, L, mid, L, mid, lazy[id]);
	add(2 * id + 1, mid, R, mid, R, lazy[id]);
	lazy[id] = 0;
}
 
int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	string s;
	cin >> s;
	int ptr = 0, tot = 0;
	for (int i = 0; i < n; i++){
		if (s[i] == 'L')
			ptr = max(ptr - 1, 0);
		else if (s[i] == 'R')
			ptr ++;
		else if (s[i] == '('){
			if (a[ptr] != 1)
				add(1, 0, n, ptr, n, +1 - a[ptr]);
			tot += +1 - a[ptr];
			a[ptr] = +1;
		}
		else if (s[i] == ')'){
			if (a[ptr] != -1)
				add(1, 0, n, ptr, n, -1 - a[ptr]);
			tot += -1 - a[ptr];
			a[ptr] = -1;
		}
		else{
			if (a[ptr] != 0)
				add(1, 0, n, ptr, n, +0 - a[ptr]);
			tot += +0 - a[ptr];
			a[ptr] = +0;
		}
		if (tot != 0 or seg[1].mnm < 0){
			cout << "-1 ";
			continue;
		}
		else
			cout << seg[1].mxm << " ";
	}
	cout << '\n';
}