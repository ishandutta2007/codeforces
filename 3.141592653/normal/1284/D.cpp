#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
using std::swap; 
#define PI (acos(-1))
#include<queue>
using std::priority_queue;
#include<map>
using std::map;
#define ll long long
#include<set>
using std::set;
typedef double db;
#include<cstring>
#include<cstdlib>
#define int ll
#include<ctime>
struct pii
{int x,y,Id;};
inline bool operator<(const pii x,const pii y)
{if(x.x^y.x)return x.x<y.x;return x.Id<y.Id;}
const int ntt=998244353;
const int rq=1e9+7;
using std::cin;
using std::cout;
using std::endl;
#define errlog(...) fprintf(stderr,__VA_ARGS__)
#define In(R) (cin>>R)
#define Out(R) (cout<<R)
#define Ln(R) (cout<<R<<endl)
#define IN In
#define OUT Out
#define OUt Out
#define OuT Out
#define LN Ln
#define iN In
#define oUt Out
#define oUT Out
#define lN Ln
#define Lin Ln 
char str[1111111];
int n;
int s1[1111111],s2[1111111],t1[1111111],t2[1111111];
struct segt
{
	segt*s[2];
	int l,r,mx,flg;
	segt(int lR=1,int rR=1e9)
	{l=lR,r=rR,mx=flg=0;s[0]=s[1]=0;}
	void pushd()
	{
		s[0]->flg+=flg,s[0]->mx+=flg;
		s[1]->flg+=flg,s[1]->mx+=flg;
		flg=0;
	}
}*root=new segt();
void modify(int l,int r,int d,segt*p=root)
{
	if(l<=p->l&&p->r<=r)return(void)(p->mx+=d,p->flg+=d);
	int mid=(p->l+p->r)>>1;
	if(!p->s[1])p->s[1]=new segt(mid+1,p->r);
	if(!p->s[0])p->s[0]=new segt(p->l,mid);
	p->pushd();
	//printf("%d %d %d\n",l,r,mid);
	if(mid<r)
	{
		modify(l,r,d,p->s[1]);
	}
	if(mid>=l)
	{
		modify(l,r,d,p->s[0]);
	}
	p->mx=0;
	if(p->s[0])p->mx=std::max(p->s[0]->mx,p->mx);
	if(p->s[1])p->mx=std::max(p->s[1]->mx,p->mx);
	//printf("<%lld %lld>",p->s[0]->mx,p->s[1]->mx);
}
pii A[111111],B[111111];
void Qno()
{
	Ln("NO");
	exit(0);
}
std::multiset<pii>s;
void ers(int x,int d=-1)
{
	//printf("%d\n",d);
	modify(s2[x],t2[x],d);
}
void comp()
{
	register int i;
	for(i=1;i<=n;i++)
		A[i].x=s1[i],A[i].y=t1[i],A[i].Id=i,B[i]=A[i];
	std::sort(A+1,A+n+1);
	root=new segt();
	int top=0;
	while(s.size())s.erase(s.begin());
	for(i=1;i<=n;i++)
	{
		int ii=A[i].Id;
		while(s.size())
		{
			pii p=*s.begin();
			if(p.x>=A[i].x)break;
			s.erase(s.begin());
			ers(p.y),top--;
		}pii p=(pii){A[i].y,A[i].Id,0};
		ers(A[i].Id,1),top++;
		s.insert(p);
		//printf("%lld %lld\n",root->mx,top);
		//
		if(root->mx!=top)Qno();
		
	}
}
void exec()
{
	IN(n);
	register int i;
	for(i=1;i<=n;i++)
		In(s1[i]),In(t1[i]),In(s2[i]),In(t2[i]);
	comp();
	for(i=1;i<=n;i++)
		{
			swap(s1[i],s2[i]);
			swap(t1[i],t2[i]);
		}
	comp();
	Ln("YES");
}
signed main()
{
	std::ios::sync_with_stdio(0);
	int T=1;
	
	//In(T);
	
	while(T--)exec();
}