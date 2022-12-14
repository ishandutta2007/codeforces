#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ll;

const int maxn = 2e5 + 10;
const int inf = 1e8;

struct node{
	int a;
	int ab;
	int abc;
	int bc;
	int c;
	int b;
	int lazy;
	void debug(){
		cout << a << " " << ab << " " << abc << " " << bc << " " << c << endl;
		cout << "anddddd " << b << endl;
	}
};

node seg[4 * maxn];

void propagate(int, int, int);

void change(int id, int L, int R, int l, int r, int val){
	if (L == l and R == r){
		seg[id].a += val;
		seg[id].ab -= val;
		seg[id].abc += 0;
		seg[id].bc -= val;
		seg[id].c += val;
		seg[id].b += val;
		seg[id].lazy += val;
		return;
	}
	propagate(id, L, R);
	int mid = (L + R) >> 1;
	if (l < mid)
		change(2 * id + 0, L, mid, l, min(mid, r), val);
	if (mid < r)
		change(2 * id + 1, mid, R, max(l, mid), r, val);
	
	seg[id].a = max(seg[2 * id + 0].a, seg[2 * id + 1].a);
	seg[id].ab = max(max(seg[2 * id + 0].ab, seg[2 * id + 1].ab), seg[2 * id + 0].a - 2 * seg[2 * id + 1].b);
	seg[id].abc = max(max(seg[2 * id + 0].abc, seg[2 * id + 1].abc),
				max(seg[2 * id + 0].ab + seg[2 * id + 1].c, seg[2 * id + 0].a + seg[2 * id + 1].bc));
	seg[id].bc = max(max(seg[2 * id + 0].bc, seg[2 * id + 1].bc), -2 * seg[2 * id + 0].b + seg[2 * id + 1].c);
	seg[id].c = max(seg[2 * id + 0].c, seg[2 * id + 1].c);
	seg[id].b = min(seg[2 * id + 0].b, seg[2 * id + 1].b);
}

void propagate(int id, int L, int R){
	if (seg[id].lazy == 0)
		return;
	int mid = (L + R) >> 1;
	change(2 * id + 0, L, mid, L, mid, seg[id].lazy);
	change(2 * id + 1, mid, R, mid, R, seg[id].lazy);
	seg[id].lazy = 0;
}

int a[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n, q;
	cin >> n >> q;
	string s;
	cin >> s;
	n = 2 * n - 2;
	for (int i = 1; i <= n; i++)
		a[i] = a[i - 1] + (s[i - 1] == '(') - (s[i - 1] == ')');
	n ++;
	for (int i = 0; i < n; i++)
		change(1, 0, n, i, i + 1, a[i]);
	cout << seg[1].abc << '\n';
	while (q --){
		int a, b;
		cin >> a >> b;
		if (s[a - 1] == s[b - 1]){
			cout << seg[1].abc << '\n';
			continue;
		}
		if (a > b)
			swap(a, b);
		if (s[a - 1] == '(')
			change(1, 0, n, a, b, -2);
		else
			change(1, 0, n, a, b, +2);
		swap(s[a - 1], s[b - 1]);
		cout << seg[1].abc << '\n';
	}
}