#include<stdio.h>
#include<algorithm>
#include<vector>
#define SZ 131072
using namespace std;
int n, m, K, Q, pv[101000], IT[SZ+SZ+1];
vector<int>E[101000];
bool chk[201000];
struct point{
	int x, y;
	bool operator <(const point &p)const{
		return y < p.y;
	}
}w[201000];
struct Query{
	int x1, x2, y1, y2, num;
	bool operator<(const Query &p)const{
		return y1 < p.y1;
	}
}P[201000];
void Push(int x, int y){
	x += SZ;
	IT[x] = y;
	while (x != 1){
		x >>= 1;
		IT[x] = max(IT[x * 2], IT[x * 2 + 1]);
	}
}
int Max(int b, int e){
	b += SZ, e += SZ;
	int r = 0;
	while (b <= e){
		r = max(r, IT[b]);
		r = max(r, IT[e]);
		b = (b + 1) >> 1, e = (e - 1) >> 1;
	}
	return r;
}
void Do(){
	int i, pv2 = 1;
	for (i = 1; i <= 100000; i++){
		E[i].clear();
		pv[i] = 0;
		Push(i, 101000);
	}
	sort(w + 1, w + K + 1);
	sort(P + 1, P + Q + 1);
	for (i = 1; i <= K; i++){
		if (!E[w[i].x].size()){
			Push(w[i].x, w[i].y);
		}
		E[w[i].x].push_back(w[i].y);
	}
	for (i = 1; i <= Q; i++){
		while (pv2 <= K && w[pv2].y < P[i].y1){
			pv[w[pv2].x]++;
			if (pv[w[pv2].x] == E[w[pv2].x].size()) Push(w[pv2].x, 101000);
			else Push(w[pv2].x, E[w[pv2].x][pv[w[pv2].x]]);
			pv2++;
		}
		if (Max(P[i].x1, P[i].x2) <= P[i].y2)chk[P[i].num] = true;
	}
}
int main()
{
	int i;
	scanf("%d%d%d%d", &n, &m, &K, &Q);
	for (i = 1; i <= K; i++){
		scanf("%d%d", &w[i].x, &w[i].y);
	}
	for (i = 1; i <= Q; i++){
		scanf("%d%d%d%d", &P[i].x1, &P[i].y1, &P[i].x2, &P[i].y2);
		P[i].num = i;
	}
	Do();
	for (i = 1; i <= K; i++)swap(w[i].x, w[i].y);
	for (i = 1; i <= Q; i++){
		swap(P[i].x1, P[i].y1);
		swap(P[i].x2, P[i].y2);
	}
	Do();
	for (i = 1; i <= Q; i++){
		if (chk[i])printf("YES\n");
		else printf("NO\n");
	}
}