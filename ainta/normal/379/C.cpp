#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
using namespace std;
struct A{
	int a, b;
	bool operator <(const A &p)const{
		return a < p.a;
	}
}w[301000];
int n, r[301000];
int main(){
	int i;
	scanf("%d", &n);
	for (i = 0; i < n; i++){
		scanf("%d", &w[i].a);
		w[i].b = i;
	}
	sort(w, w + n);
	r[w[0].b] = w[0].a;
	for (i = 1; i < n; i++){
		if (w[i].a <= w[i - 1].a)w[i].a = w[i - 1].a + 1;
		r[w[i].b] = w[i].a;
	}
	for (i = 0; i < n; i++){
		printf("%d ", r[i]);
	}
}