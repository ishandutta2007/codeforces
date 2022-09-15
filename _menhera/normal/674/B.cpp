#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int n, k, a, b, c, d;
	scanf("%d%d%d%d%d%d",&n,&k,&a,&b,&c,&d);
	int A=a, B=b, C=c, D=d;
	bool bs=false, as=false;
	if(a==b || c==d)
	{
		puts("-1");
		return 0;
	}
	if(a==d)
	{
		bs = true;
		C^=D^=C^=D;
	}
	else if(b==c && a!=d)
	{
		A^=B^=A^=B;
		as=true;
	}
	else if(b==d && a!=c)
	{
		as=bs=true;
		C^=D^=C^=D;
		A^=B^=A^=B;
	}
	
	if(A!=C)
	{
		if(k<=n || n==4)
		{
			puts("-1");
			return 0;
		}
		printf("%d ", a);
		printf("%d ", c);
		for(int i=1; i<=n; i++)
			if(i!=a && i!=b && i!=c && i!=d) printf("%d ",i);
		printf("%d ", d);
		printf("%d", b);
		puts("");
		printf("%d ", c);
		printf("%d ", a);
		for(int i=1; i<=n; i++)
			if(i!=a && i!=b && i!=c && i!=d) printf("%d ",i);
		printf("%d ", b);
		printf("%d", d);
		return 0;
	}
	//A==C
	if(B==D)
	{
		printf("%d ",a);
		for(int i=1; i<=n;i++)
			if(i!=a && i!=b) printf("%d ",i);
		printf("%d ",b);
		puts("");
		if(a!=c)
		{
			printf("%d ",c);
			for(int i=n; i>=1;i--)
				if(i!=a && i!=b) printf("%d ",i);
			printf("%d ",d);
		}
		else
		{
			printf("%d ",c);
			for(int i=1; i<=n;i++)
				if(i!=a && i!=b) printf("%d ",i);	
			printf("%d ",d);
		}
		return 0;		
	}
	vector<int> xx;
	vector<int> yy;	
	xx.push_back(A);
	yy.push_back(A);
	for(int i=1; i<=n; i++)
		if(i!=A && i!=B && i!=D ) xx.push_back(i),yy.push_back(i);
	xx.push_back(D); xx.push_back(B);
	yy.push_back(B); yy.push_back(D);
	if(as) reverse(xx.begin(),xx.end());
	if(bs) reverse(yy.begin(),yy.end());
	for(int i=0; i<xx.size(); i++) printf("%d ",xx[i]);
	puts("");
	for(int i=0; i<xx.size(); i++) printf("%d ",yy[i]);
	return 0;
}