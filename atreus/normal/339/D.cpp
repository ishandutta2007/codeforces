#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <time.h>
#include <set>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#define F first
#define S second
#define MP make_pair
#define PB push_back
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7, maxn = 2e5 + 100;
int seg[4 * maxn], a[maxn];

void change (int id, int L, int R, int isxor, int idx, int val){
	if (L + 1 == R){
		seg[id] = val;
		return;
	}
	int mid = (L + R) / 2;
	if (idx < mid){
		seg[id] = seg[id * 2 + 1];
		change (id * 2 + 0, L, mid, !isxor, idx, val);
		if (isxor)
			seg[id] ^= seg[id * 2 + 0];
		else
			seg[id] |= seg[id * 2 + 0];
	}
	else {
		seg[id] = seg[id * 2 + 0];
		change (id * 2 + 1, mid, R, !isxor, idx, val);
		if (isxor)
			seg[id] ^= seg[id * 2 + 1];
		else
			seg[id] |= seg[id * 2 + 1];
	}
}

void build (int id, int L, int R, bool isxor){
	if (L + 1 == R){
		seg[id] = a[L];
		return;
	}
	int mid = (L + R) / 2;
	build (id * 2 + 0, L, mid, !isxor);
	build (id * 2 + 1, mid, R, !isxor);
	if (isxor)
		seg[id] = (seg[id * 2] ^ seg[id * 2 + 1]);
	else
		seg[id] = (seg[id * 2] | seg[id * 2 + 1]);
}

int main(){
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= (1 << n); i++)
		cin >> a[i];
	build (1, 1, (1 << n) + 1, !(n % 2));
	for (int i = 1; i <= q; i++){
		int p, b;
		cin >> p >> b;
		change (1, 1, (1 << n) + 1, !(n % 2), p, b);
		a[p] = b;
		cout << seg[1] << endl;
	}
}