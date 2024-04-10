#include<cstdio>
char a[8][9];
int p[256];
int main()
{
	p['Q']=9;
	p['R']=5;
	p['B']=3;
	p['N']=3;
	p['P']=1;
	p['q']=-9;
	p['r']=-5;
	p['b']=-3;
	p['n']=-3;
	p['p']=-1;
	for(int i=0;i<8;i++)
		scanf("%s",&a[i]);
	int ans=0;
	for(int i=0;i<8;i++)
		for(int j=0;j<8;j++)
			ans+=p[a[i][j]];
	if(ans>0) puts("White");
	else if(!ans) puts("Draw");
	else puts("Black");
}