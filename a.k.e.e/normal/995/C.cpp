#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back
const int MAXN=200005,LIMIT=1500000;

int n,c[MAXN],pa[MAXN];
struct Data
{
	int x,y,id;
	void rev(){x=-x;y=-y;c[id]=-c[id];}
	bool operator <(const Data &b)const{return y<b.y;}
};
vector<Data> v[2];
int ch[MAXN][2];
void play(int u)
{
	if(u<=n)return;
	c[ch[u][0]]*=c[u];
	c[ch[u][1]]*=c[u];
	play(ch[u][0]);
	play(ch[u][1]);
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    scanf("%d",&n);
    for(int i=1;i<=2*n;i++)c[i]=1;
    for(int i=1;i<=n;i++)
    {
    	Data d;
    	scanf("%d%d",&d.x,&d.y);
    	d.id=i;
    	if(d.x<0)d.rev();
    	if(d.y<0)v[0].pb(d);
    	else v[1].pb(d);
    }
    int cur=n;
    while(1)
    {
    	Data d;d.id=++cur;
    	Data a,b;
    	if(v[0].size()>=2)
    	{
    		a=v[0].back();v[0].pop_back();
    		b=v[0].back();v[0].pop_back();
    	}
    	else if(v[1].size()>=2)
    	{
    		a=v[1].back();v[1].pop_back();
    		b=v[1].back();v[1].pop_back();
    	}
    	else break;
		b.rev();
		ch[d.id][0]=a.id;ch[d.id][1]=b.id;
		d.x=a.x+b.x;d.y=a.y+b.y;
		if(d.x<0)d.rev();
		if(d.y<0)v[0].pb(d);
		else v[1].pb(d);
    }
    if(v[0].size() && v[1].size())
    {
    	Data a=v[0][0],b=v[1][0];
    	int x=a.x+b.x,y=a.y+b.y;
    	if(1ll*x*x+1ll*y*y>1ll*LIMIT*LIMIT)b.rev();
    }
    if(v[0].size())play(v[0][0].id);
    if(v[1].size())play(v[1][0].id);
    for(int i=1;i<=n;i++)
    	printf("%d ",c[i]);
    return 0;
}