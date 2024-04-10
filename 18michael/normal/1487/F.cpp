#include<cstdio>
#include<cstring>
#define inf 0x7f7f7f7f
int l,Test_num,mxc,mxx;
char ch[53];
int f[53][53][511][2];
inline int min(int a,int b)
{
	return a<b? a:b;
}
inline int dp(int pos,int c,int x,int delta)
{
	if(pos==l)return c? inf:0;if(c>mxc || c<-mxc || x>mxx || x<-mxx)return inf;
	if(!(~f[pos][c+mxc][x+mxx][(delta==1)]))f[pos][c+mxc][x+mxx][(delta==1)]=min(dp(pos,c,x+delta,delta)+l-pos,min(dp(pos+1,c*10+ch[pos+1]-x,x,1),dp(pos+1,c*10+ch[pos+1]-x,x,-1)));
	return f[pos][c+mxc][x+mxx][(delta==1)];
}
int main()
{
	scanf("%s",ch+2),l=strlen(ch+2)+1,ch[1]=0,mxx=5*l,mxc=mxx/10+1;
	for(int i=2;i<=l;++i)ch[i]^=48;
	memset(f,-1,sizeof(f)),printf("%d",dp(0,0,0,1));
	return 0;
}