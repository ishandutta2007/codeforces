#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<unordered_set>
#define SZ 252144
#define pii pair<int, int>
#define vit vector<int>::iterator
#define X first
#define Y second
using namespace std;
int n, m, K, sx1 = -1, sy1 = -1, CX, CY, IT[2][SZ * 2 + 2];
unordered_set<long long> Set, Set2;
pii w[800010];
vector<int> w1[220000], w2[220000];
struct SegY{
	int x, y1, y2;
	bool operator< (const SegY &p)const{
		return x != p.x ? x < p.x : y1 < p.y1;
	}
} Y2[1410000];
struct SegX{
	int y, x1, x2;
	bool operator< (const SegX &p)const{
		return y != p.y ? y < p.y : x1 < p.x1;
	}
} X2[1410000];
struct order{
	int x, y, p;
	bool operator <(const order &p)const{
		return x < p.x;
	}
}ord[1810000];
vector<SegX>XX;
vector<SegY>YY;
long long Gap(int a, int b){
	return ((long long)a << 20) + b;
}
void Ins(int sx, int sy){
	int x1, x2, y1, y2;
	x1 = sx + sy, y1 = sx - sy + (m / 2 + 1) * 2;
	x2 = sx1 + sy1, y2 = sx1 - sy1 + (m / 2 + 1) * 2;
	if (x1 == x2){
		SegY tp;
		tp.x = x1, tp.y1 = min(y1, y2), tp.y2 = max(y1, y2);
		YY.push_back(tp);
	}
	else{
		SegX tp;
		tp.y = y1, tp.x1 = min(x1, x2), tp.x2 = max(x1, x2);
		XX.push_back(tp);
	}
}
void Do(int sx, int sy, int dir){
	vit it;
	sx1 = sx, sy1 = sy;
	if (Set2.find(Gap(sx, sy * 5 + dir)) != Set2.end())return;
	Set2.insert(Gap(sx, sy * 5 + dir));
	int x, y, c1 = 0, c2 = 0;
	if (dir == 1){
		it = lower_bound(w1[sx + sy].begin(), w1[sx + sy].end(), sx);
		it--;
		x = *it, y = sx + sy - x;
		if (Set.find(Gap(x, y - 1)) != Set.end()){
			c1 = 1;
		}
		if (Set.find(Gap(x + 1, y)) != Set.end()){
			c2 = 1;
		}
		Ins(x + 1, y - 1);
		if (!c1 && !c2){
			Do(x + 1, y - 1, 4);
		}
		else if (c1 == 0 && c2 == 1){
			Do(x, y - 1, 2);
		}
		else if (c1 == 1 && c2 == 0){
			Do(x + 1, y, 3);
		}
		else{
			Do(x + 1, y - 1, 4);
		}
		return;
	}
	if (dir == 2){
		it = lower_bound(w2[sx - sy + m + 2].begin(), w2[sx - sy + m + 2].end(), sx);
		it--;
		x = *it, y = x - sx + sy;
		if (Set.find(Gap(x, y + 1)) != Set.end()){
			c1 = 1;
		}
		if (Set.find(Gap(x + 1, y)) != Set.end()){
			c2 = 1;
		}
		Ins(x + 1, y + 1);
		if (!c1 && !c2){
			Do(x + 1, y + 1, 3);
		}
		else if (c1 == 0 && c2 == 1){
			Do(x, y + 1, 1);
		}
		else if (c1 == 1 && c2 == 0){
			Do(x + 1, y, 4);
		}
		else{
			Do(x + 1, y + 1, 3);
		}
		return;
	}
	if (dir == 3){
		it = lower_bound(w2[sx - sy + m + 2].begin(), w2[sx - sy + m + 2].end(), sx);
		x = *it, y = x - sx + sy;
		if (Set.find(Gap(x, y - 1)) != Set.end()){
			c1 = 1;
		}
		if (Set.find(Gap(x - 1, y)) != Set.end()){
			c2 = 1;
		}
		Ins(x - 1, y - 1);
		if (!c1 && !c2){
			Do(x - 1, y - 1, 2);
		}
		else if (c1 == 0 && c2 == 1){
			Do(x, y - 1, 4);
		}
		else if (c1 == 1 && c2 == 0){
			Do(x - 1, y, 1);
		}
		else{
			Do(x - 1, y - 1, 2);
		}
		return;
	}
	if (dir == 4){
		it = lower_bound(w1[sx + sy].begin(), w1[sx + sy].end(), sx);
		x = *it, y = sx + sy - x;
		if (Set.find(Gap(x, y + 1)) != Set.end()){
			c1 = 1;
		}
		if (Set.find(Gap(x - 1, y)) != Set.end()){
			c2 = 1;
		}
		Ins(x - 1, y + 1);
		if (!c1 && !c2){
			Do(x - 1, y + 1, 1);
		}
		else if (c1 == 0 && c2 == 1){
			Do(x, y + 1, 3);
		}
		else if (c1 == 1 && c2 == 0){
			Do(x - 1, y, 2);
		}
		else{
			Do(x - 1, y + 1, 1);
		}
		return;
	}
}
void Pro()
{
	int be, ed, i, sz = XX.size();
	for (i = 0; i != sz; i++){
		if (!i || XX[i].y != XX[i - 1].y){
			if (i){
				X2[CX].y = XX[i - 1].y;
				X2[CX].x1 = be, X2[CX].x2 = ed;
				CX++;
			}
			be = XX[i].x1;
			ed = XX[i].x2;
			continue;
		}
		if (ed < XX[i].x1){
			X2[CX].y = XX[i - 1].y;
			X2[CX].x1 = be, X2[CX].x2 = ed;
			CX++;
			be = XX[i].x1, ed = XX[i].x2;
		}
		else ed = max(ed,XX[i].x2);
	}
	if (sz){
		X2[CX].y = XX[i - 1].y;
		X2[CX].x1 = be, X2[CX].x2 = ed;
		CX++;
	}
	sz = YY.size();
	for (i = 0; i != sz; i++){
		if (!i || YY[i].x != YY[i - 1].x){
			if (i){
				Y2[CY].x = YY[i - 1].x;
				Y2[CY].y1 = be, Y2[CY].y2 = ed;
				CY++;
			}
			be = YY[i].y1;
			ed = YY[i].y2;
			continue;
		}
		if (ed < YY[i].y1){
			Y2[CY].x = YY[i - 1].x;
			Y2[CY].y1 = be, Y2[CY].y2 = ed;
			CY++;
			be = YY[i].y1, ed = YY[i].y2;
		}
		else ed = max(ed, YY[i].y2);
	}
	if (sz){
		Y2[CY].x = YY[i - 1].x;
		Y2[CY].y1 = be, Y2[CY].y2 = ed;
		CY++;
	}
}
long long Res = 0;
void Insert(int ck, int a, int b){
	a += SZ;
	while (a){
		IT[ck][a] += b;
		a >>= 1;
	}
}
int Ans(int ck, int b, int e){
	b += SZ, e += SZ;
	int r = 0;
	while (b <= e){
		if (b & 1)r += IT[ck][b];
		if (!(e & 1))r += IT[ck][e];
		b = (b + 1) >> 1, e = (e - 1) >> 1;
	}
	return r;
}
int main()
{
	int i, c, sx, sy, dir, pv;
	char pp[4];
	scanf("%d%d%d", &n, &m, &K);
	for (i = 0; i < K; i++){
		scanf("%d%d", &w[i].X, &w[i].Y);
	}
	for (i = 0; i <= m + 1; i++){
		w[K].X = 0, w[K].Y = i; K++;
		w[K].X = n + 1, w[K].Y = i; K++;
	}
	for (i = 1; i <= n; i++){
		w[K].X = i, w[K].Y = 0; K++;
		w[K].X = i, w[K].Y = m + 1; K++;
	}
	sort(w, w + K);
	for (i = 0; i < K; i++){
		Set.insert(Gap(w[i].X, w[i].Y));
		w1[w[i].X + w[i].Y].push_back(w[i].X);
		w2[w[i].X - w[i].Y + m + 2].push_back(w[i].X);
	}
	scanf("%d%d", &sx, &sy);
	scanf("%s", pp);
	if (pp[0] == 'N'){
		if (pp[1] == 'E')dir = 1;
		else dir = 2;
	}
	if (pp[0] == 'S'){
		if (pp[1] == 'E')dir = 3;
		else dir = 4;
	}
	Do(sx, sy, dir);
	if (!XX.empty())sort(XX.begin(), XX.end());
	if (!YY.empty())sort(YY.begin(), YY.end());
	Pro();
	for (i = 0; i < CX; i++){
		Res += (X2[i].x2 - X2[i].x1) / 2 + 1;
		ord[i].x = X2[i].x1, ord[CX + i].x = X2[i].x2 + 1;
		ord[i].y = ord[CX + i].y = X2[i].y;
		ord[i].p = 1, ord[CX + i].p = -1;
	}
	for (i = 0; i < CY; i++){
		Res += (Y2[i].y2 - Y2[i].y1) / 2 + 1;
	}
	sort(ord, ord + CX * 2);
	pv = 0;
	for (i = 0; i < CY; i++){
		while (ord[pv].x <= Y2[i].x && pv < CX * 2){
			Insert(ord[pv].y % 2, ord[pv].y, ord[pv].p);
			pv++;
		}
		Res -= Ans(Y2[i].y1 % 2, Y2[i].y1, Y2[i].y2);
	}
	printf("%lld\n", Res);
	return 0;
}