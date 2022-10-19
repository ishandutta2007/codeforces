#include<bits/stdc++.h>
using namespace std;
int n,t=0,ans=0;
int a[500002],id[500002],num[500002];
vector<int> vec[500002];
set<int> s,s2;
set<int>::iterator it;
struct aaa
{
	int l,r,o;
	inline bool operator < (const aaa &a) const
	{
		return l<a.l;
	}
}tmp,tmpp,tmps;
set<aaa> s1;
set<aaa>::iterator it1,it2;
template<class T>void read(T &x)
{
	x=0;char ch=getchar();
	while(ch<'0' || ch>'9')ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
}
template<class T>void write(T x)
{
	if(x>9)write(x/10);
	putchar((x%10)^48);
}
inline bool cmp(int x,int y)
{
	return a[x]<a[y]? 1:0;
}
inline void del(aaa a)
{
	s1.erase(a),s2.erase(a.r-a.l);
}
inline void ins(aaa a)
{
	s1.insert(a),s2.insert(a.r-a.l);
}
inline void cover(int l,int r,int x)
{
	for(it=s.lower_bound(l);it!=s.end() && (*it)<=r;it=s.erase(it))a[*it]=num[x];
}
inline void update(int l,int r,int lo,int ro,int x)
{
	if(lo)
	{
		if(ro)cover(l,r,x);
		else cover(l,(l+r)>>1,x);
	}
	else if(ro)cover((l+r+1)>>1,r,x);
}
int main()
{
	read(n);
	for(int i=1;i<=n;++i)read(a[i]),s.insert(id[i]=i),s1.insert((aaa){i,i,0});
	sort(id+1,id+n+1,cmp);
	for(int i=1;i<=n;++i)
	{
		if(i==1 || a[id[i]]!=num[t])num[++t]=a[id[i]];
		vec[t].push_back(id[i]);
	}
	for(int i=t;i;ans=max(ans,(*(--(it=s2.end())))>>1),--i)
		for(int j=0,v;j<vec[i].size();++j)
		{
			v=vec[i][j],it1=s1.lower_bound((aaa){v,0,0});
			if(it1==s1.end() || (*it1).l!=v)--it1;
			tmp=(*it1);
			if(it1!=s1.begin())tmpp=(*(--(it2=it1)));
			else tmpp=(aaa){0,0,tmp.o};
			if((++(it2=it1))!=s1.end())tmps=(*it2);
			else tmps=(aaa){n+1,n+1,(tmp.l^tmp.r^tmp.o)&1};
			if(tmp.l==v && tmp.r==v)
			{
				if(!tmpp.l)tmpp.o^=1;
				if(tmps.r>n)tmps.o^=1;
				update(tmpp.l,tmps.r,tmpp.o,(tmps.l^tmps.r^tmps.o)&1,i);
				if(it1!=s1.begin())tmpp=(*(--(it2=it1)));
				else tmpp.o=-1;
				if((++it1)!=s1.end())del(tmps=(*it1));
				else tmps.o=-1;
				if(~tmpp.o)del(tmpp);
				del(tmp),ins((aaa){~tmpp.o? tmpp.l:tmp.l,~tmps.o? tmps.r:tmp.r,~tmpp.o? tmpp.o:1});
			}
			else if(tmp.l==v)
			{
				if(!tmpp.l)tmpp.o^=1;
				update(tmpp.l,tmp.l,tmpp.o,1,i),update(tmp.l+1,tmp.r,1,tmps.o,i);
				if(it1!=s1.begin())del(tmpp=(*(--it1)));
				else tmpp.o=-1;
				del(tmp),ins((aaa){tmp.l+1,tmp.r,tmp.o^1}),ins((aaa){~tmpp.o? tmpp.l:tmp.l,tmp.l,~tmpp.o? tmpp.o:1});
			}
			else if(tmp.r==v)
			{
				if(tmps.r>n)tmps.o^=1;
				update(tmp.l,tmp.r-1,tmp.o,1,i),update(tmp.r,tmps.r,1,(tmps.l^tmps.r^tmps.o)&1,i);
				if((++it1)!=s1.end())del(tmps=(*it1));
				else tmps.o=-1;
				del(tmp),ins((aaa){tmp.l,tmp.r-1,tmp.o}),ins((aaa){tmp.r,~tmps.o? tmps.r:tmp.r,1});
			}
			else update(tmp.l,v-1,tmp.o,1,i),update(v+1,tmp.r,1,tmps.o,i),cover(v,v,i),del(tmp),ins((aaa){tmp.l,v-1,tmp.o}),ins((aaa){v,v,1}),ins((aaa){v+1,tmp.r,1});
		}
	write(ans),putchar('\n');
	for(int i=1;i<=n;++i)write(a[i]),putchar(' ');
	return 0;
}