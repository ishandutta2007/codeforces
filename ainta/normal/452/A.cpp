#pragma warning(disable:4996)
#include<stdio.h>
char p[8][10] =
{
	"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"
};
int L[8] = { 8, 7, 7, 6, 7, 7, 7, 7 };
int Len;
char q[10];
int main()
{
	int i, j;
	scanf("%d", &Len);
	scanf("%s", q);
	for (i = 0; i < 8; i++){
		if (L[i] != Len)continue;
		for (j = 0; j < Len; j++){
			if (p[i][j] != q[j] && q[j] != '.')break;
		}
		if (j == Len){
			printf("%s\n", p[i]);
		}
	}
}