#include<stdio.h>
#include<algorithm>
#include<unordered_map>
#define SZ 524288
using namespace std;
int n, K, S[310000], w[301000], Num[1001000];
unordered_map<int, int>Map[301000];
__int64 Res;
int cnt, cc;
int IT[SZ + SZ][2];
int Max(int b, int e){
	b += SZ, e += SZ;
	int r = -1, x;
	while (b <= e){
		if (r < IT[b][0]){
			r = IT[b][0], x = IT[b][1];
		}
		if (r < IT[e][0]){
			r = IT[e][0], x = IT[e][1];
		}
		b = (b + 1) >> 1;
		e = (e - 1) >> 1;
	}
	return x;
}
void Do(int b, int e){
	cnt++;
	if (b == e){
		++cc;
		Num[cnt] = cc;
		Map[cc][S[b]] = 1;
		return;
	}
	int i, x, c1, c2, c = cnt;
	x = Max(b + 1, e);
	c1 = cnt + 1;
	Do(b, x - 1);
	c2 = cnt + 1;
	Do(x, e);
	if (x - b < e - x + 1){
		for (i = b; i <= x - 1; i++){
			Res += Map[Num[c2]][(S[i] + w[x])%K];
		}
		for (i = b; i <= x - 1; i++){
			Map[Num[c2]][S[i]]++;
		}
		Map[Num[c1]].clear();
		Num[c] = Num[c2];
	}
	else{
		for (i = x; i <= e; i++){
			Res += Map[Num[c1]][(S[i] + K - (w[x]%K)) % K];
		}
		for (i = x; i <= e; i++){
			Map[Num[c1]][S[i]]++;
		}
		Map[Num[c2]].clear();
		Num[c] = Num[c1];
	}
}
void Ins(int a, int b){
	IT[a + SZ][0] = b;
	IT[a + SZ][1] = a;
	a += SZ;
	while (a != 1){
		a >>= 1;
		if (IT[a * 2][0] < IT[a * 2 + 1][0]){
			IT[a][0] = IT[a * 2 + 1][0];
			IT[a][1] = IT[a * 2 + 1][1];
		}
		else{
			IT[a][0] = IT[a * 2][0];
			IT[a][1] = IT[a * 2][1];
		}
	}
}
int main(){
	int i;
	scanf("%d%d", &n, &K);
	for (i = 1; i <= n; i++){
		scanf("%d", &w[i]);
		Ins(i, w[i]);
		S[i] = (S[i - 1] + w[i]) % K;
	}
	Do(0, n);
	printf("%I64d\n", Res - n);
}