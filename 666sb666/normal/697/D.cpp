#include<cstdio>
#include<cstring>
inline void read(int&x)
{
    x=0;
    char ch=getchar();
    while(ch>'9'||ch<'0')ch=getchar();
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
}
char ch[10];
inline void write(int k)
{
	int num=0;
	while(k)ch[++num]=k%10,k/=10;
	while(num)putchar(ch[num--]+'0');
}
const int maxn=100001;
struct E
{
	int to,next;
}edge[maxn<<1];
int n,p[maxn],head[maxn],dep[maxn],size[maxn],tot;
void dfs(int u,int fa)
{
	dep[u]=dep[fa]+1,size[u]=1;
	for(int i=head[u];i!=-1;i=edge[i].next)if(edge[i].to!=fa)
	{
		dfs(edge[i].to,u);
		size[u]+=size[edge[i].to];
	}
}
int main()
{
	read(n);
	memset(head,-1,sizeof(head));
	for(int i=2;i<=n;i++)
	{
		read(p[i]);
		edge[++tot]=(E){i,head[p[i]]};
		head[p[i]]=tot;
		edge[++tot]=(E){p[i],head[i]};
		head[i]=tot;
	}
	dep[0]=-1;
	dfs(1,0);
	for(int i=1;i<=n;i++)
	{
		int ans=n-size[i]-dep[i];
		write((ans>>1)+dep[i]+1);
		putchar('.');
		if(ans&1)putchar('5');
		else putchar('0');
		putchar(' ');
	}
	return 0;
}