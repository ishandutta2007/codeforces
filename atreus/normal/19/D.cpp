#include <cstring>
#include <algorithm>
#include <map>
#include <stack>
#include <cassert>
#include <cmath>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <vector>
#include <iostream>
#include <set>
#define MP make_pair
#define F first
#define PB push_back
#define S second
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 5;
pair <int, int> p[maxn];
int n, seg[4 * maxn], x[maxn], y[maxn];
char s[maxn];

int get (int id, int L, int R, int l, int r, int myy){
	if (p[seg[id]].S <= myy)
		return 0;

	if (L + 1 == R){
		if (p[seg[id]].S > myy)
			return seg[id];
		return 0;
	}

	int mid = (L + R) / 2;
	if (mid > l){
		int qop = get (2 * id + 0, L, mid, l, min (mid, r), myy);
		if (p[qop].S > myy)
			return qop;
	}
	if (mid < r){
		int qop = get (2 * id + 1, mid, R, max (l, mid), r, myy);
		if (p[qop].S > myy)
			return qop;
	}
	return 0;
}

void change (int id, int L, int R, int idx, int val){
	if (L + 1 == R){
		if (val == -1)
			seg[id] = 0;
		else
			seg[id] = idx;
		return;
	}
	int mid = (L + R) / 2;
	if (mid > idx)
		change (2 * id + 0, L, mid, idx, val);
	else
		change (2 * id + 1, mid, R, idx, val);

	if (p[seg[2 * id + 0]].S > p[seg[2 * id + 1]].S)
		seg[id] = seg[2 * id + 0];
	else
		seg[id] = seg[2 * id + 1];
}

int main(){
	scanf ("%d", &n);
	for (int i = 1; i <= n; i++){
		char c[10];
		scanf ("%s%d%d", &c, x + i, y + i);
		if (c[0] == 'a')
			s[i] = 'a';
		else if (c[0] == 'r')
			s[i] = 'r';
		else
			s[i] = 'f';
		p[i] = MP (x[i], y[i]);
	}
	sort (p + 1, p + n + 1);
	p[0] = MP (-1, -1);
	for (int i = 1; i <= n; i++){
		if (s[i] == 'a'){
			int idx = lower_bound (p + 1, p + n + 1, MP (x[i], y[i])) - p;
			change (1, 1, maxn, idx, y[i]);
		}
		else if (s[i] == 'r'){
			int idx = lower_bound (p + 1, p + n + 1, MP (x[i], y[i])) - p;
			change (1, 1, maxn, idx, -1);
		}
		else {
			int idx = lower_bound (p + 1, p + n + 1, MP (x[i] + 1, -1)) - p;
			int ans = 0;
			if (idx != -1)
				ans = get (1, 1, maxn, idx, maxn, y[i]);
			if (ans == 0){
				printf ("-1\n");
				continue;
			}
			printf ("%d %d\n", p[ans].F, p[ans].S);
		}
	}
}