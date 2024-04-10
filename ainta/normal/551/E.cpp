#include<stdio.h>
#include<algorithm>
using namespace std;
int n, Q, C[510], SZ;
long long S[510], w[510][1010];
struct A{
	long long x;
	int num;
	bool operator<(const A &p)const{
		return x != p.x ? x < p.x : num < p.num;
	}
}D[510][1010];
void init(int a){
	int i;
	for (i = 0; i < C[a]; i++)D[a][i].x = w[a][i], D[a][i].num = i;
	sort(D[a], D[a] + C[a]);
}
void UDT2(int a){
	int i;
	for (i = 0; i < C[a]; i++){
		w[a][i] += S[a];
	}
	S[a] = 0;
}
void UDT(int b, int e, int x){
	int bb = b / 1000, ee = e / 1000, i, r1 = b % 1000, r2 = e % 1000;
	if (bb == ee){
		UDT2(bb);
		for (i = r1; i <= r2; i++)w[bb][i] += x;
		init(bb);
		return;
	}
	for (i = bb + 1; i < ee; i++)S[i] += x;
	UDT2(bb);
	UDT2(ee);
	for (i = r1; i < C[bb]; i++)w[bb][i] += x;
	for (i = 0; i <= r2; i++)w[ee][i] += x;
	init(bb);
	init(ee);
}
int Find(int a, long long x){
	int b = 0, e = C[a] - 1, r = C[a], mid;
	while (b <= e){
		mid = (b + e) >> 1;
		if (D[a][mid].x >= x){
			r = mid;
			e = mid - 1;
		}
		else b = mid + 1;
	}
	if (r == C[a] || D[a][r].x != x)return -1;
	return D[a][r].num;
}
int Do(int a){
	int i, p, b = -1, e, ee;
	for (i = 0; i <= SZ; i++){
		p = Find(i, a - S[i]);
		if (p != -1){
			if (b == -1) b = i * 1000 + p;
			ee = i;
		}
	}
	if (b == -1)return -1;
	for (i = 0; i < C[ee]; i++){
		if (D[ee][i].x == a - S[ee])e = ee * 1000 + D[ee][i].num;
	}
	return e - b;
}
int main(){
	int i, a, b, c, d;
	scanf("%d%d", &n, &Q);
	for (i = 0; i < n; i++){
		scanf("%d", &a);
		w[i / 1000][C[i / 1000]++] = a;
	}
	SZ = (n - 1) / 1000;
	for (i = 0; i <= SZ; i++)init(i);
	while (Q--){
		scanf("%d%d", &a, &b);
		if (a == 1){
			scanf("%d%d", &c, &d);
			UDT(b-1, c-1, d);
			continue;
		}
		if (a == 2){
			printf("%d\n", Do(b));
		}
	}
}