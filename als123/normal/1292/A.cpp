#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int N=100005;
int n,q; 
int cnt=0;
bool in[2][N];
int check (int y)
{
	if (in[0][y]==false) return false;
	if (in[1][y]||in[1][y+1]||in[1][y-1]) return true;
	return false;
}
void Ins (int x,int y)
{
	if (x==0)
	{
		cnt-=check(y);
		in[x][y]^=1;
		cnt+=check(y);
	}
	else
	{
		int tot1=check(y)+check(y-1)+check(y+1);
		in[x][y]^=1;
		int tot2=check(y)+check(y-1)+check(y+1);
		cnt=cnt-tot1+tot2;
	}
}
int main()
{
	memset(in,false,sizeof(in));
	scanf("%d%d",&n,&q);
	while (q--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		x--;Ins(x,y);
		if (cnt>0) printf("No\n");
		else printf("Yes\n");
	}
	return 0;
}