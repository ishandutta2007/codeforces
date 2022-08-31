#pragma warning(disable:4996)
#include<stdio.h>
int st[100010], n;
int main()
{
	int i, a, top = 0, Res = 0, t;
	scanf("%d", &n);
	for (i = 1; i <= n; i++){
		scanf("%d", &a);
		while (top && st[top] < a){
			t = (st[top] ^ a);
			if (Res < t)Res = t;
			top--;
		}
		if (top){
			t = (st[top] ^ a);
			if (Res < t)Res = t;
		}
		st[++top] = a;
	}
	printf("%d\n", Res);
}