#include<stdio.h>
#include<algorithm>
using namespace std;
int n, Q, L, be[401000], Rank[401000], SA[401000], LCP[401000][20], MM[401000];
int Len[201000], BIT[401000], Res[501000];
char p[401000];
struct A{
	int a, b, num;
	bool operator<(const A &p)const{
		return a != p.a ? a < p.a : b < p.b;
	}
}w[401000];
struct Qu{
	int b, e, h, ck, num;
	bool operator<(const Qu &p)const{
		return h < p.h;
	}
}QQ[1010000];
void Suffix_Array(){
	int i, M = 1, cnt;
	for (i = 0; i < L; i++){
		w[i].a = p[i];
		w[i].b = p[i + 1];
		w[i].num = i;
	}
	while (1){
		sort(w, w + L);
		cnt = 0;
		M *= 2;
		for (i = 0; i < L; i++){
			if (i == 0 || w[i].a != w[i - 1].a || w[i].b != w[i - 1].b)cnt++;
			Rank[w[i].num] = cnt;
		}
		if (M >= L)break;
		for (i = 0; i < L; i++){
			w[i].a = Rank[i];
			w[i].num = i;
			if (i + M >= L)w[i].b = 0;
			else w[i].b = Rank[i + M];
		}
	}
	for (i = 0; i < L; i++)SA[Rank[i]] = i;
}
void Make_LCP(){
	int i, x, y, t = 0, j;
	for (i = 0; i < L; i++){
		x = Rank[i];
		if (x == L)continue;
		y = SA[x + 1];
		while (p[i + t] == p[y + t])t++;
		LCP[x][0] = t;
		if (t)t--;
	}
	for (i = 0; i < 18; i++){
		for (j = 0; j < L; j++){
			if (j + (1 << i) >= L)continue;
			LCP[j][i + 1] = min(LCP[j][i], LCP[j + (1 << i)][i]);
		}
	}
}
int Get_LCP(int b, int e){
	int x = MM[e - b];
	return min(LCP[b][x], LCP[e - (1 << x)][x]);
}
void Add(int a){
	while (a <= L){
		BIT[a]++;
		a += (a&-a);
	}
}
int Sum(int a){
	int r = 0;
	while (a){
		r += BIT[a];
		a -= (a&-a);
	}
	return r;
}
int main(){
	int i, j, d, a, b, c, x;
	int bb, ee, b1, e1, mid;
	scanf("%d%d", &n, &Q);
	for (i = 0; i < n; i++){
		be[i] = L;
		scanf("%s", p + L);
		for (j = L; p[j]; j++);
		p[j] = ' ';
		Len[i] = j - L;
		L = j + 1;
	}
	be[n] = L;
	Suffix_Array();
	Make_LCP();
	d = 1, j = 0;
	for (i = 1; i < L; i++){
		if (d * 2 <= i)d *= 2, j++;
		MM[i] = j;
	}
	for (i = 0; i < Q; i++){
		scanf("%d%d%d", &a, &b, &c);
		a--, b--, c--;
		x = Rank[be[c]];
		bb = 0, ee = x - 1, b1 = e1 = x;
		while (bb <= ee){
			mid = (bb + ee) >> 1;
			if (Get_LCP(mid, x) >= Len[c]){
				b1 = mid;
				ee = mid - 1;
			}
			else bb = mid + 1;
		}
		bb = x + 1, ee = L;
		while (bb <= ee){
			mid = (bb + ee) >> 1;
			if (Get_LCP(x, mid) >= Len[c]){
				e1 = mid;
				bb = mid + 1;
			}
			else ee = mid - 1;
		}
		QQ[i].b = b1, QQ[i].e = e1, QQ[i].h = be[a] - 1, QQ[i].ck = -1;
		QQ[i + Q].b = b1, QQ[i + Q].e = e1, QQ[i + Q].h = be[b + 1] - 1, QQ[i + Q].ck = 1;
		QQ[i].num = QQ[i + Q].num = i;
	}
	sort(QQ, QQ + Q + Q);
	int pv = 0;
	for (i = 0; i < Q + Q; i++){
		while (pv < L && pv <= QQ[i].h){
			Add(Rank[pv]);
			pv++;
		}
		Res[QQ[i].num] += (Sum(QQ[i].e) - Sum(QQ[i].b - 1)) * QQ[i].ck;
	}
	for (i = 0; i < Q; i++)printf("%d\n", Res[i]);
	return 0;
}