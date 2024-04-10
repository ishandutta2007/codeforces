#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
using namespace std;
struct order{
	int a, num;
	bool operator <(const order &p)const{
		return a < p.a;
	}
}ord[100010];
int n, w[100010];
int BIT[2][100010];
long long K, S;
void Ins(int pv, int a, int b){
	while (a <= n){
		BIT[pv][a] += b;
		a += (a&-a);
	}
}
int Sum(int pv, int a){
	int r = 0;
	while (a){
		r += BIT[pv][a];
		a -= (a&-a);
	}
	return r;
}
int Sum2(int pv, int a, int b){
	return Sum(pv, b) - Sum(pv, a - 1);
}
int main()
{
	int i, cnt = 0, t, pv;
	long long Res = 0;
	scanf("%d%lld", &n, &K);
	for (i = 1; i <= n; i++){
		scanf("%d", &ord[i].a);
		ord[i].num = i;
	}
	sort(ord + 1, ord + n + 1);
	for (i = 1; i <= n; i++){
		if (i == 1 || ord[i].a != ord[i - 1].a)cnt++;
		w[ord[i].num] = cnt;
	}
	for (i = n; i >= 1; i--){
		t = Sum2(1, 1, w[i] - 1);
		if (S + t > K)break;
		S += t;
		Ins(1, w[i], 1);
	}
	pv = i + 1;
	for (i = 1; i <= n; i++){
		S += Sum2(0, w[i] + 1, n);
		S += Sum2(1, 1, w[i] - 1);
		Ins(0, w[i], 1);
		while (pv <= n && (pv == i || S > K)){
			S -= Sum2(0, w[pv] + 1, n);
			S -= Sum2(1, 1, w[pv] - 1);
			Ins(1, w[pv], -1);
			pv++;
		}
		Res += n + 1 - pv;
	}
	printf("%lld\n", Res);
}