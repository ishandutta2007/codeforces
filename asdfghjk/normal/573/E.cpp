#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=400005;
int n,a[N],ch[N][2],size[N],root,cnt,i,lt,rt,mid;
ll st[N],d[N],val[N],ans=-(1ll<<60);
void pushdown(int o)
{
	val[o]+=st[o]+d[o]*size[ch[o][0]];
	st[ch[o][0]]+=st[o],st[ch[o][1]]+=st[o]+d[o]*(size[ch[o][0]]+1);
	d[ch[o][0]]+=d[o],d[ch[o][1]]+=d[o];
	d[o]=st[o]=0;
}
void maintain(int o)
{
	size[o]=size[ch[o][0]]+size[ch[o][1]]+1;
}
void rotate(int &o,int d)
{
	int k=ch[o][d];
	ch[o][d]=ch[k][d^1];
	ch[k][d^1]=o;
	maintain(o);
	maintain(k);
	o=k;
}
int cmp(int o,int x)
{
	if(x==size[ch[o][0]]+1)
		return -1;
	return x>size[ch[o][0]]+1;
}
void splay(int &o,int x)
{
	pushdown(o);
	int k1=cmp(o,x);
	if(k1==-1)
		return;
	if(k1==1)
		x-=size[ch[o][0]]+1;
	pushdown(ch[o][k1]);
	int k2=cmp(ch[o][k1],x);
	if(k2!=-1)
	{
		if(k2==1)
			x-=size[ch[ch[o][k1]][0]]+1;
		splay(ch[ch[o][k1]][k2],x);
		if(k1==k2)
			rotate(o,k1);
		else
			rotate(ch[o][k1],k2);
	}
	rotate(o,k1);
}
ll cirno(int x)
{
	splay(root,x);
	return val[root];
}
void work(int o)
{
	if(!o)
		return;
	pushdown(o);
	ans=max(ans,val[o]);
	work(ch[o][0]);
	work(ch[o][1]);
}
int main()
{
	scanf("%d",&n);
	ch[1][1]=2;
	size[1]=2,size[2]=1;
	val[2]=-(1ll<<60);
	root=1;
	cnt=2;
	for(i=1;i<=n;++i)
	{
		scanf("%d",a+i);
		lt=1,rt=i;
		while(lt<rt)
		{
			mid=lt+rt>>1;
			if(cirno(mid+1)>=cirno(mid)+1ll*mid*a[i])
				lt=mid+1;
			else
				rt=mid;
		}
		++cnt;
		val[cnt]=cirno(lt)+1ll*lt*a[i];
		size[cnt]=1;
		splay(root,lt);
		if(size[ch[root][1]]>1)
		{
			splay(ch[root][1],size[ch[root][1]]);
			d[ch[ch[root][1]][0]]+=a[i];
			st[ch[ch[root][1]][0]]+=1ll*a[i]*(lt+1);
		}
		splay(ch[root][1],1);
		pushdown(root);
		pushdown(ch[root][1]);
		ch[ch[root][1]][0]=cnt;
		maintain(ch[root][1]);
		maintain(root);
	}
	work(root);
	printf("%lld",ans);
	return 0;
}