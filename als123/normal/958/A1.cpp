#include<set>
#include<map>
#include<deque>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<complex>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;

const int maxn = 20;

int n;
int a[maxn][maxn],c[maxn][maxn];
int b[maxn][maxn];

bool Check()
{
	int ok=1;
	for(int i=1;i<=n&&ok;i++) for(int j=1;j<=n&&ok;j++)
		ok&=a[i][j]==b[i][j];
	return ok;
}
void Copy()
{
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) a[i][j]=c[i][j];
}
void Rotate()
{
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
		c[n-j+1][i]=a[i][j];
	Copy();
}
void rev1()
{
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
		c[i][n-j+1]=a[i][j];
	Copy();
}
void rev2()
{
	for(int j=1;j<=n;j++) for(int i=1;i<=n;i++)
		c[n-i+1][j]=a[i][j];
	Copy();
}

char str[maxn];

int main()
{
	//freopen("tmp.in","r",stdin);
	//freopen("tmp.out","w",stdout);
	
	scanf("%d",&n);
	for(int i=1;i<=n;i++) 
	{
		scanf("%s",str+1);
		for(int j=1;j<=n;j++) a[i][j]=str[j]=='X'?1:0;
	}
	for(int i=1;i<=n;i++) 
	{
		scanf("%s",str+1);
		for(int j=1;j<=n;j++) b[i][j]=str[j]=='X'?1:0;
	}
	
	for(int i=0;i<4;i++)
	{
		Rotate();
		if(Check()) return puts("Yes"),0;
	}
	rev1();
	for(int i=0;i<4;i++)
	{
		Rotate();
		if(Check()) return puts("Yes"),0;
	}
	rev2();
	for(int i=0;i<4;i++)
	{
		Rotate();
		if(Check()) return puts("Yes"),0;
	}
	puts("No");
	
    return 0;
}