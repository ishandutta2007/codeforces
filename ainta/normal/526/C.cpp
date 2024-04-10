#include<stdio.h>
#include<algorithm>
using namespace std;
int C;
struct A{
	long long a, b;
}p, q;
long long Res, T;
int main(){
	int i;
	scanf("%d%lld%lld%lld%lld", &C, &p.a, &q.a, &p.b, &q.b);
	Res = 0;
	if (p.a*q.b > q.a*p.b){
		swap(p, q);
	}
	if (q.b <= 100000){
		for (i = 0; i*p.b <= C && i <= q.b; i++){
			T = i*p.a + ((C - i*p.b) / q.b)*q.a;
			Res = max(Res, T);
		}
	}
	else{
		for (i = 0; i*q.b <= C; i++){
			T = i*q.a + ((C - i*q.b) / p.b) * p.a;
			Res = max(Res, T);
		}
	}
	printf("%lld\n", Res);
}