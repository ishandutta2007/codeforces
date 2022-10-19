#include<cstdio>
int n,Test_num;bool t;int x[100002];
int main()
{
	scanf("%d",&Test_num);
	while(Test_num--)
	{
		t=0,scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d",&x[i]);
		for(int i=1;i<=n;++i)if(x[i]!=1)t=1;
		for(int i=1;i<=n && x[i]==1;++i)t^=1;
		puts(t? "First":"Second");
	}
	return 0;
}