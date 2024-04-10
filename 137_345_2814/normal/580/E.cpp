#include<cstdio>
using namespace std;
#define ll unsigned long long
#define N 400500
ll pw[N],pw2[N],ch=17,mod=1e9+9;
char s[N];
int n,m,a,b,c,d;
struct st{int l,r,lazy;ll h;}e[N*4];
void pushup(int x){e[x].h=((e[x<<1].h*pw[e[x<<1|1].r-e[x<<1|1].l+1]+e[x<<1|1].h)%mod+mod)%mod;}
void pushdown(int x){if(e[x].lazy+1)e[x<<1].lazy=e[x<<1|1].lazy=e[x].lazy,e[x<<1].h=pw2[e[x<<1].r-e[x<<1].l]*e[x].lazy%mod,e[x<<1|1].h=pw2[e[x<<1|1].r-e[x<<1|1].l]*e[x].lazy%mod,e[x].lazy=-1;}
void build(int x,int l,int r)
{
	e[x].l=l;e[x].r=r;e[x].lazy=-1;
	if(l==r){e[x].h=s[l]-'0'+1;return;}
	int mid=(e[x].l+e[x].r)>>1;
	build(x<<1,l,mid);build(x<<1|1,mid+1,r);pushup(x);
}
void add(int x,int l,int r,int a)
{
	if(e[x].l==l&&e[x].r==r)
	{
		e[x].lazy=a;
		e[x].h=pw2[e[x].r-e[x].l]*a%mod;
		return;
	}
	pushdown(x);
	int mid=(e[x].l+e[x].r)>>1;
	if(mid>=r)add(x<<1,l,r,a);
	else if(mid<l)add(x<<1|1,l,r,a);
	else add(x<<1,l,mid,a),add(x<<1|1,mid+1,r,a);
	pushup(x);
}
ll que(int x,int l,int r)
{
	if(l>r)return 0;
	if(e[x].l==l&&e[x].r==r)
	return e[x].h;
	pushdown(x);
	int mid=(e[x].l+e[x].r)>>1;
	if(mid>=r)return que(x<<1,l,r);
	else if(mid<l)return que(x<<1|1,l,r);
	else return (que(x<<1,l,mid)*pw[r-mid]+que(x<<1|1,mid+1,r))%mod;
}
int main()
{
	scanf("%d%d%d",&n,&m,&a),m+=a;
	scanf("%s",s+1);pw[0]=pw2[0]=1;
	for(int i=1;i<=n;i++)pw[i]=pw[i-1]*ch%mod,pw2[i]=(pw2[i-1]*ch+1)%mod;
	build(1,1,n);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d%d",&a,&b,&c,&d);
		if(a==1)
		add(1,b,c,d+1);
		else
		printf("%s\n",que(1,b,c-d)==que(1,b+d,c)?"YES":"NO");
	}
}