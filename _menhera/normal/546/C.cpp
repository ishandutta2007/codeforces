#include<cstdio>
#include<queue>
using namespace std;
#define MAX (1*2*3*4*5*6*7*8*9*10*11+100)
int main()
{
	int N;
	scanf("%d",&N);
	queue<int> A,B;
	int a,b;
	scanf("%d",&a);
	for(int i=0;i<a;i++)
	{
		int t;
		scanf("%d",&t);
		A.push(t);
	}
	scanf("%d",&b);
	for(int i=0;i<b;i++)
	{
		int t;
		scanf("%d",&t);
		B.push(t);
	}
	int cnt=0;
	while(cnt<MAX && !A.empty() && !B.empty() )
	{
		cnt++;
		int av=A.front();
		int bv=B.front();
		A.pop();
		B.pop();
		if(av<bv)
		{
			B.push(av);
			B.push(bv);
		}
		else
		{
			A.push(bv);
			A.push(av);
		}
	}
	if(cnt>=MAX)
	{
		puts("-1");
		return 0;
	}
	printf("%d",cnt);
	if(A.empty()) printf(" 2");
	else printf(" 1");
}