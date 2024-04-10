#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#define SZ 524288
#define pii pair<int,int>
using namespace std;
int n;
struct Rect {
	int bx, by, ex, ey;
}R[101000];
int X[401000], Y[401000], CX, CY;

struct Tree {
	int Mn[SZ + SZ], Mx[SZ + SZ], K[SZ + SZ];
	void Add2(int nd, int x) {
		Mn[nd] += x;
		Mx[nd] += x;
		K[nd] += x;
	}
	void Spread(int nd) {
		Add2(nd * 2, K[nd]);
		Add2(nd * 2 + 1, K[nd]);
		K[nd] = 0;
	}
	void UDT(int nd) {
		Mn[nd] = min(Mn[nd * 2], Mn[nd * 2 + 1]);
		Mx[nd] = max(Mx[nd * 2], Mx[nd * 2 + 1]);
	}
	void Add(int nd, int b, int e, int s, int l, int x) {
		if (s > l)return;
		if (s <= b && e <= l) {
			Add2(nd, x);
			return;
		}
		Spread(nd);
		int m = (b + e) >> 1;
		if (s <= m)Add(nd * 2, b, m, s, l, x);
		if (l > m)Add(nd * 2 + 1, m + 1, e, s, l, x);
		UDT(nd);
	}
	int Least(int nd, int b, int e) {
		if (!Mx[nd])return SZ+1;
		if (b == e)return b;
		int m = (b + e) >> 1;
		Spread(nd);
		if (Mx[nd * 2])return Least(nd * 2, b, m);
		return Least(nd * 2 + 1, m + 1, e);
	}
	int Last(int nd, int b, int e) {
		if (!Mx[nd])return -1;
		if (b == e)return b;
		int m = (b + e) >> 1;
		Spread(nd);
		if (Mx[nd * 2 + 1])return Last(nd * 2 + 1, m + 1, e);
		return Last(nd * 2, b, m);
	}
	int Get0(int nd, int b, int e, int s, int l) {
		if (s>l||b>l||e<s)return -1;
		if (Mn[nd])return -1;
		if (b == e)return b;
		int m = (b + e) >> 1;
		Spread(nd);
		int r;
		if (s <= m) {
			r = Get0(nd * 2, b, m, s, l);
			if (r != -1)return r;
		}
		if (l > m)return Get0(nd * 2 + 1, m + 1, e, s, l);
		return -1;
	}
}ITX,ITY;
void Add(int a, int x){
	ITX.Add(1, 0, SZ - 1, R[a].bx, R[a].ex, x);
	ITY.Add(1, 0, SZ - 1, R[a].by, R[a].ey, x);
}
bool OK(set<pii>&SX, set<pii>&SY) {
	if (SX.size() == 1) {
		Add(SX.begin()->second, -1);
		SX.clear(), SY.clear();
		return true;
	}
	int lx = ITX.Least(1, 0, SZ - 1), rx = ITX.Last(1, 0, SZ - 1);
	int ly = ITY.Least(1, 0, SZ - 1), ry = ITY.Last(1, 0, SZ - 1);
	int tx = ITX.Get0(1, 0, SZ - 1, lx, rx);
	int ty = ITY.Get0(1, 0, SZ - 1, ly, ry);
	if (tx == -1 && ty == -1)return false;
	if (tx != -1) {
		auto it1 = SX.begin(), it2 = SX.end();
		it2--;
		vector<int>TP;
		while (1) {
			int b = R[it1->second].ex, e = R[it2->second].bx;
			if (b > tx) {
				auto it = SX.begin();
				while (R[it->second].ex < tx) {
					TP.push_back(it->second);
					it++;
				}
				break;
			}
			if (e < tx) {
				auto it = SX.end(); it--;
				while (R[it->second].bx > tx) {
					TP.push_back(it->second);
					it--;
				}
				break;
			}
			it1++, it2--;
		}
		for (auto &t : TP) {
			SX.erase({ R[t].bx,t });
			SY.erase({ R[t].by,t });
			Add(t, -1);
		}
		if (!OK(SX, SY))return false;
		SX.clear(), SY.clear();
		for (auto &t : TP) {
			SX.insert({ R[t].bx,t });
			SY.insert({ R[t].by,t });
			Add(t, 1);
		}
		if (!OK(SX, SY))return false;
		return true;
	}
	auto it1 = SY.begin(), it2 = SY.end();
	it2--;
	vector<int>TP;
	while (1) {
		int b = R[it1->second].ey, e = R[it2->second].by;
		if (b > ty) {
			auto it = SY.begin();
			while (R[it->second].ey < ty) {
				TP.push_back(it->second);
				it++;
			}
			break;
		}
		if (e < ty) {
			auto it = SY.end(); it--;
			while (R[it->second].by > ty) {
				TP.push_back(it->second);
				it--;
			}
			break;
		}
		it1++, it2--;
	}
	for (auto &t : TP) {
		SX.erase({ R[t].bx,t });
		SY.erase({ R[t].by,t });
		Add(t, -1);
	}
	if (!OK(SX, SY))return false;
	SX.clear(), SY.clear();
	for (auto &t : TP) {
		SX.insert({ R[t].bx,t });
		SY.insert({ R[t].by,t });
		Add(t, 1);
	}
	if (!OK(SX, SY))return false;
	return true;
}
int main() {
	int i;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d%d%d%d", &R[i].bx, &R[i].by, &R[i].ex, &R[i].ey);
		R[i].bx = R[i].bx * 2 + 1;
		R[i].by = R[i].by * 2 + 1;
		R[i].ex = R[i].ex * 2 - 1;
		R[i].ey = R[i].ey * 2 - 1;
		X[CX++] = R[i].bx;
		X[CX++] = R[i].bx + 1;
		X[CX++] = R[i].ex;
		X[CX++] = R[i].ex + 1;
		Y[CY++] = R[i].by;
		Y[CY++] = R[i].by + 1;
		Y[CY++] = R[i].ey;
		Y[CY++] = R[i].ey + 1;
	}
	sort(X, X + CX);
	sort(Y, Y + CY);
	set<pii>SX, SY;
	for (i = 0; i < n; i++) {
		R[i].bx = lower_bound(X, X + CX, R[i].bx) - X;
		R[i].ex = lower_bound(X, X + CX, R[i].ex) - X;
		R[i].by = lower_bound(Y, Y + CY, R[i].by) - Y;
		R[i].ey = lower_bound(Y, Y + CY, R[i].ey) - Y;
		SX.insert({ R[i].bx,i });
		SY.insert({ R[i].by,i });
		Add(i, 1);
	}
	if (OK(SX, SY))puts("YES");
	else puts("NO");
}