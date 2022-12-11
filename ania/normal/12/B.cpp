#include<cstdio>
#include<algorithm>
using namespace std;

#define fore(i,n) for(int i = 0; i < (n); i++)

int x,q,y;
char t[111],s[111],u[111];

int main()
{
	scanf("%d%s", &x,s);
	/*
	int w = 0;
	while(u[w]) w++;
	int v = 0;
	while(v+1 < w && u[v] == '0') v++;
	fore(i,w-v) s[i] = u[v+i];
	*/
	if(x == 0)
	{
		if(s[1]==0 && s[0] == '0') printf("OK\n");
		else printf("WRONG_ANSWER\n");
		return 0;
	}
	while(x)
	{
		t[q++] = x % 10;
		x /= 10;
	}
	sort(t,t+q);
	int p = 0;
	while(t[p] == 0) p++;
	swap(t[0],t[p]);
	//fore(i,q) printf("%d",t[i]); printf("\n");
	p = 0;
	while(s[p]) p++;
	fore(i,p) s[i] -= '0';
	if(p != q)
	{
		printf("WRONG_ANSWER\n");
		return 0;
	}
	fore(i,q) if(t[i] != s[i])
	{
		printf("WRONG_ANSWER\n");
		return 0;
	}
	printf("OK\n");
}