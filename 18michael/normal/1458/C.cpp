#include<cstdio>
int n,m,Test_num;
int a[1002][1002],b[1002][1002];
char s[100002];
struct aaa
{
	int a,b;
}v[3];
inline void swap(aaa &a,aaa &b)
{
	aaa c=a;a=b,b=c;
}
int main()
{
	scanf("%d",&Test_num);
	while(Test_num--)
	{
		scanf("%d%d",&n,&m),v[v[0].a=0].b=v[v[1].a=1].b=v[v[2].a=2].b=0;
		for(int i=0;i<n;++i)for(int j=0;j<n;++j)scanf("%d",&a[i][j]),--a[i][j];
		scanf("%s",s);
		for(int i=0;i<m;++i)
		{
			if(s[i]=='R')++v[1].b;
			else if(s[i]=='L')--v[1].b;
			else if(s[i]=='D')++v[0].b;
			else if(s[i]=='U')--v[0].b;
			else if(s[i]=='I')swap(v[1],v[2]);
			else swap(v[0],v[2]);
		}
		for(int i=0,x,y,z;i<n;++i)
			for(int j=0;j<n;++j)
			{
				if((x=(((v[0].a? (v[0].a==1? j:a[i][j]):i)+v[0].b)%n))<0)x+=n;
				if((y=(((v[1].a? (v[1].a==1? j:a[i][j]):i)+v[1].b)%n))<0)y+=n;
				if((z=(((v[2].a? (v[2].a==1? j:a[i][j]):i)+v[2].b)%n))<0)z+=n;
				b[x][y]=z;
			}
		for(int i=0;i<n;++i)for(int j=0;j<n;++j)printf("%d%c",b[i][j]+1,j==n-1? '\n':' ');
		puts("");
	}
	return 0;
}