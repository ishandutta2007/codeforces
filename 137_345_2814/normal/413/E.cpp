#include<cstdio>
#include<algorithm>
using namespace std;
#define N 200007
#define ff first.first
#define fs first.second
#define sf second.first
#define ss second.second
int n,m,a,b;
char s[2][N]; 
struct segment_tree{
	int l,r,ans[2][2];
}e[N*4];
inline int Min(int a,int b){return a>b?b:a;}
void pushup(int x)
{
	for(int i=0;i<=1;i++)
	for(int j=0;j<=1;j++)
	e[x].ans[i][j]=Min(1e8,Min(e[x<<1].ans[i][0]+e[x<<1|1].ans[0][j],e[x<<1].ans[i][1]+e[x<<1|1].ans[1][j]))+1;
}
void build(int x,int l,int r)
{
	e[x].l=l;e[x].r=r;
	if(l==r)
	{
		if(s[0][l]=='.')e[x].ans[0][0]=0;else e[x].ans[0][0]=0x1f3f3f3f;
		if(s[1][l]=='.')e[x].ans[1][1]=0;else e[x].ans[1][1]=0x1f3f3f3f;
		if(s[0][l]=='.'&&s[1][l]=='.')e[x].ans[0][1]=e[x].ans[1][0]=1;else e[x].ans[0][1]=e[x].ans[1][0]=0x1f3f3f40;
		return;
	}
	int mid=(e[x].l+e[x].r)>>1;
	build(x<<1,l,mid);
	build(x<<1|1,mid+1,r);
	pushup(x);
}
pair<pair<int,int>,pair<int,int> > query(int x,int l,int r)
{
	if(e[x].l==l&&e[x].r==r)
	return make_pair(make_pair(e[x].ans[0][0],e[x].ans[0][1]),make_pair(e[x].ans[1][0],e[x].ans[1][1]));
	int mid=(e[x].l+e[x].r)>>1;
	if(mid>=r)return query(x<<1,l,r);
	else if(mid<l)return query(x<<1|1,l,r);
	else
	{
		pair<pair<int,int>,pair<int,int> > s1=query(x<<1,l,mid),s2=query(x<<1|1,mid+1,r),s3;
		s3.ff=Min(Min(s1.ff+s2.ff,s1.fs+s2.sf)+1,1e8);
		s3.fs=Min(Min(s1.ff+s2.fs,s1.fs+s2.ss)+1,1e8);
		s3.sf=Min(Min(s1.sf+s2.ff,s1.ss+s2.sf)+1,1e8);
		s3.ss=Min(Min(s1.sf+s2.fs,s1.ss+s2.ss)+1,1e8);
		return s3;
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	scanf("%s%s",s[0]+1,s[1]+1);
	build(1,1,n);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&a,&b);
		int tmpa=(a-1)%n+1,tmpb=(b-1)%n+1,tmpc=a>tmpa,tmpd=b>tmpb;
		if(tmpa>tmpb)swap(tmpa,tmpb),swap(tmpc,tmpd);
		pair<pair<int,int>,pair<int,int> >s=query(1,tmpa,tmpb);
		pair<int,int> s1=tmpc?s.second:s.first;
		int s2=tmpd?s1.second:s1.first;
		if(s2>1e7)s2=-1;
		printf("%d\n",s2);
	}
}