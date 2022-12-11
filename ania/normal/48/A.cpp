#include<cstdio>

int A,B,C;
char a[33], b[33], c[33];
int h[333];

bool win(int x, int y, int z)
{
	x += 2;
	x %= 3;
	if(x == y && x == z) return 1;
	return 0;
}

int main()
{
	h['r'] = 0;
	h['p'] = 1;
	h['s'] = 2;
	scanf("%s%s%s", a, b, c);
	A = h[a[0]];
	B = h[b[0]];
	C = h[c[0]];
	if(win(A,B,C)) printf("F\n");
	else if(win(B,A,C)) printf("M\n");
	else if(win(C,A,B)) printf("S\n");
	else printf("?\n");
}