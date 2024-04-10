#include<cstdio>

#define fore(i,n) for(int i = 0; i < (n); i++)

char t[5][5];

int main()
{
	fore(i,3) scanf("%s", t[i]);
	fore(i,3) fore(j,3) if(t[i][j] == 'X' && t[2-i][2-j] != 'X')
	{
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
}