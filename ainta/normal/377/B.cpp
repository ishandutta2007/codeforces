#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
using namespace std;
int n, m, s, B, E, M, res[101000], pp[101000], cnt;
struct bug{
	int a, x;
	bool operator <(const bug &p)const{
		return a < p.a;
	}
}a[101000];
struct Student{
	int b, c, x;
	bool operator <(const Student &p)const{
		return b < p.b;
	}
}w[101000];
struct Heap{
	int a, b;
	bool operator <(const Heap &p)const{
		return a!=p.a?a>p.a:b<p.b;
	}
}heap[101000], tp;
int main(){
	int i, pv, top, SS, R = 0;
	scanf("%d%d%d", &n, &m, &s);
	for (i = 0; i < m; i++){
		scanf("%d", &a[i].a);
		a[i].x = i;
	}
	sort(a, a + m);
	for (i = 0; i < n; i++){
		scanf("%d", &w[i].b);
		w[i].x = i + 1;
	}
	for (i = 0; i < n; i++){
		scanf("%d", &w[i].c);
	}
	sort(w, w + n);
	B = 1, E = m;
	while (B <= E){
		M = (B + E + 1) >> 1;
		pv = n - 1;
		top = 0;
		SS = 0;
		cnt = 0;
		for (i = m - 1; i >= 0;i-=M){
			while (w[pv].b>=a[i].a){
				tp.a = w[pv].c, tp.b = w[pv].x;
				heap[top++] = tp;
				push_heap(heap, heap + top);
				pv--;
			}
			if (!top){
				SS = s + 1;
				break;
			}
			SS += heap[0].a;
			pp[cnt++] = heap[0].b;
			pop_heap(heap, heap + top);
			top--;
			if (SS > s)break;
		}
		if (SS > s)B = M + 1;
		else{
			R = M, E = M - 1;
			cnt = 0;
			for (i = m - 1; i >= 0; i--){
				res[a[i].x] = pp[cnt / M];
				cnt++;
			}
		}
	}
	if (!R)printf("NO\n");
	else{
		printf("YES\n");
		for (i = 0; i < m; i++){
			printf("%d ", res[i]);
		}
	}
	return 0;
}