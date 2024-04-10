#include<stdio.h>
#include<algorithm>
using namespace std;
#define SZ 131072
char p[101000], q[101000];
int n, m, oto[101000], Mod = 1000000007, Nxt[101000];
bool v[101000];
struct ST{
	int S, K;
}IT[SZ * 2 + 2];
void KMP(){
	int i, t;
	oto[0] = -1;
	for (i = 1; i <= m; i++){
		t = oto[i - 1];
		while (t != -1 && q[t] != q[i - 1])t = oto[t];
		oto[i] = t + 1;
	}
	t = 0;
	for (i = 0; p[i]; i++){
		while (t != -1 && p[i] != q[t])t = oto[t];
		t++;
		if (t == m){
			v[i - m + 1] = true;
			t = oto[t];
		}
	}
}
void Add2(int node, int x, int b, int e){
	long long t = x;
	t = t*(e - b + 1) % Mod;
	IT[node].S = (IT[node].S + t) % Mod;
	IT[node].K = (IT[node].K + x) % Mod;
}
void Spread(int node, int b, int m, int e){
	Add2(node * 2, IT[node].K, b, m);
	Add2(node * 2 + 1, IT[node].K, m + 1, e);
	IT[node].K = 0;
}
int Sum(int node, int b, int e, int s, int l){
	if (s > l)return 0;
	if (b == s && e == l)return IT[node].S;
	int m = (b + e) >> 1, r = 0;
	Spread(node, b, m, e);
	if (s <= m)r += Sum(node * 2, b, m, s, min(m, l));
	if (l > m)r += Sum(node * 2 + 1, m + 1, e, max(m + 1, s), l);
	return r%Mod;
}
void UDT(int node){
	IT[node].S = (IT[node * 2].S + IT[node * 2 + 1].S) % Mod;
}
void Add(int node, int b, int e, int s, int l, int x){
	if (b == s && e == l){
		Add2(node, x, b, e);
		return;
	}
	int m = (b + e) >> 1;
	Spread(node, b, m, e);
	if (s <= m)Add(node * 2, b, m, s, min(m, l), x);
	if (l > m)Add(node * 2 + 1, m + 1, e, max(m + 1, s), l, x);
	UDT(node);
}
void DP(){
	int i, t, Res = 0;
	for (i = 0; i < n; i++){
		t = Sum(1, 1, SZ, 1, i) + 1;
		if (Nxt[i] != -1)Add(1, 1, SZ, Nxt[i] + m, n, t);
	}
	printf("%d\n", Sum(1, 1, SZ, 1, n));
}
int main()
{
	int i, t = -1;
	scanf("%s%s", p, q);
	for (i = 0; p[i]; i++);
	n = i;
	for (i = 0; q[i]; i++);
	m = i;
	KMP();
	for (i = n - 1; i >= 0; i--){
		if (v[i])t = i;
		Nxt[i] = t;
	}
	DP();
	return 0;
}