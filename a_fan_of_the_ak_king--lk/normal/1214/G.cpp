#include<bits/stdc++.h>
using namespace std;
const int N=200005;
const long long M=998244353;
const long long iv2=499122177;
int n,m,q,i,h,l,r;
bitset<2005> a[2005],tmp,ua,ub,c[2005];
struct str{
int s,x;
bool operator <(const str &a)const
{
if(a.s==s)
return a.x>x;
return a.s>s;
}
};
set<str> p;
struct node{
int a,b,c,d;
bool operator <(const node &p)const
{
if(p.a!=a)
return p.a>a;
if(p.b!=b)
return p.b>b;
if(p.c!=c)
return p.c>c;
return p.d>d;
}
};
set<node> ans;
void Add(int x,int y,int t)
{
tmp=a[x]&a[y];
ua=a[x]^tmp;
ub=a[y]^tmp;
if(ua.any()&&ub.any())
{
int a=ua._Find_first();
int b=ub._Find_first();
node w=(node){min(x,y),min(a,b),max(x,y),max(a,b)};
if(t==1)
ans.insert(w);
else
ans.erase(w);
}
}
void Insert(int x)
{
int t=a[x].count();
p.insert((str){t,x});
auto it=p.find((str){t,x});
auto d=it;
auto e=it;
++e;
if(it!=p.begin())
{
--d;
if(e!=p.end())
Add(d->x,e->x,-1);
Add(d->x,it->x,1);
}
if(e!=p.end())
Add(e->x,it->x,1);
}
void Del(int x)
{
int t=a[x].count();
auto it=p.find((str){t,x});
auto d=it;
auto e=it;
++e;
if(it!=p.begin())
{
--d;
if(e!=p.end())
Add(d->x,e->x,1);
Add(d->x,it->x,-1);
}
if(e!=p.end())
Add(e->x,it->x,-1);
p.erase(it);
}
int main()
{
scanf("%d %d %d",&n,&m,&q);
for(i=1;i<=n;++i)
Insert(i);
for(i=1;i<=m;++i)
{
c[i]=c[i-1];
c[i][i]=1;
}
while(q--)
{
scanf("%d %d %d",&h,&l,&r);
Del(h);
a[h]=a[h]^c[r]^c[l-1];
Insert(h);
if(ans.empty())
puts("-1");
else
{
auto it=ans.begin();
printf("%d %d %d %d\n",it->a,it->b,it->c,it->d);
}
}
}