#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 17, lg = 32;
int n, q;
double iman[maxn << 2];
struct lz{
	double a, b;
	lz() : a(1), b(0) {}
	lz(double x, double y) : a(x), b(y) {}
}  sina[maxn << 2];

lz& operator += (lz &a, const lz &b){
	a.a *= b.a;
	a.b *= b.a;
	a.b += b.b;
	return a;
}
void arpa(int l = 0, int r = n, int id = 1){
	if(l + 1 == r){
		int x;
		cin >> x;
		iman[id] = x;
		return ;
	}
	int mid = l + r >> 1;
	arpa(l, mid, id << 1);
	arpa(mid, r, id << 1 | 1);
	iman[id] = iman[id << 1] + iman[id << 1 | 1];
}
void sadra(int id, int l, int r){
	int mid = l + r >> 1;
	lz &x = sina[id];
	iman[id << 1] = iman[id << 1] * x.a + x.b * (mid - l);
	iman[id << 1 | 1] = iman[id << 1 | 1] * x.a + x.b * (r - mid);
	sina[id << 1] += sina[id];
	sina[id << 1 | 1] += sina[id];
	sina[id] = lz();
}
void majid(int s, int e, lz x, int l = 0, int r = n, int id = 1){
	if(s <= l && r <= e){
		iman[id] = iman[id] * x.a + x.b * (r - l);
		sina[id] += x;
		return ;
	}
	if(e <= l || r <= s)
		return ;
	int mid = l + r >> 1;
	sadra(id, l, r);
	majid(s, e, x, l, mid, id << 1);
	majid(s, e, x, mid, r, id << 1 | 1);
	iman[id] = iman[id << 1] + iman[id << 1 | 1];
}
double hamid(int s, int e, int l = 0, int r = n, int id = 1){
	if(s <= l && r <= e)
		return iman[id];
	if(e <= l || r <= s)
		return 0;
	int mid = l + r >> 1;
	sadra(id, l, r);
	return hamid(s, e, l, mid, id << 1) + hamid(s, e, mid, r, id << 1 | 1);
}
int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	cout << fixed << setprecision(5);
	cin >> n >> q;
	arpa();
	while(q--){
		int t, l, r, x, y;
		cin >> t >> l >> r;
		l--;
		if(t == 1){
			cin >> x >> y;
			x--;
			double a = hamid(l, r) / (r - l), b = hamid(x, y) / (y - x);
			majid(l, r, lz({(double) (r - l - 1) / (r - l), b / (r - l)}));
			majid(x, y, lz({(double) (y - x - 1) / (y - x), a / (y - x)}));
		}
		else
			cout << hamid(l, r) << '\n';
	}
  return 0;
}