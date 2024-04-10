#include<cstdio>
int main()
{
	int N,M;
	char x[50][50];
	int cnt=0;
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++) scanf("%s",&x[i]);
	for(int i=0;i<N-1;i++)
		for(int j=0;j<M-1;j++)
		{
			int t[255];
			t['f']=0; t['a']=0; t['c']=0; t['e']=0;
			t[x[i][j]]++;
			t[x[i][j+1]]++;
			t[x[i+1][j]]++;
			t[x[i+1][j+1]]++;
			if(t['f'] && t['a'] && t['c'] && t['e']) cnt++;
		}
	printf("%d",cnt);
}