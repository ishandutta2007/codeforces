#include<bits/stdc++.h>

char cl[11][11][11][11][11];


int main()
{
	cl[1][0][0][1][0]='a';
	cl[1][1][0][2][0]='b';
	cl[2][0][0][1][1]='c';
	cl[2][1][0][1][2]='d';
	cl[1][1][0][1][1]='e';
	cl[2][1][0][2][1]='f';
	cl[2][2][0][2][2]='g';
	cl[1][2][0][2][1]='h';
	//cl[1][1][0][1][1]='i';
	cl[1][2][0][1][2]='j';
	cl[1][0][1][2][0]='k';
	cl[1][1][1][3][0]='l';
	cl[2][0][1][2][1]='m';
	cl[2][1][1][2][2]='n';
	cl[1][1][1][2][1]='o';
	cl[2][1][1][3][1]='p';
	cl[2][2][1][3][2]='q';
	cl[1][2][1][3][1]='r';
	//cl[1][1][1][2][1]='s';
	cl[1][2][1][2][2]='t';
	cl[1][0][2][2][1]='u';
	cl[1][1][2][3][1]='v';
	cl[1][2][1][1][3]='w';
	cl[2][0][2][2][2]='x';
	cl[2][1][2][2][3]='y';
	cl[1][1][2][2][2]='z';
	
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b,c,d,e;
		scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
		printf("%c",cl[a][b][c][d][e]);
	}
}
/*
Happy April Fool's Day !!!11 
*/