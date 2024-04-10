#include<bits/stdc++.h>
using namespace std;
int n,a,b,c,mx,ans=0;
multiset<int,greater<int> > s;
multiset<int,greater<int> >::iterator it;
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline bool del(int x)
{
	it=s.lower_bound(x);
	if(it==s.end())return 0;
	s.erase(it);return 1;
}
int main()
{
	read(n),read(a),read(b),read(c);
	if(a>b)swap(a,b);
	if(a>c)swap(a,c);
	if(b>c)swap(b,c);
	for(int i=1,x;i<=n;++i)
	{
		read(x),s.insert(x);
		if(x>a+b+c)return 0&puts("-1");
	}
	while(!s.empty())
	{
		mx=(*s.begin());
		if(c>=mx)
		{
			del(c);
			if(del(b))del(a);
			else del(a+b);
		}
		else if(a+b>=mx)del(a+b),del(c);
		else if(a+c>=mx)del(a+c),del(b);
		else if(b+c>=mx)del(b+c),del(a);
		else del(a+b+c);
		++ans;
	}
	return 0&printf("%d",ans);
}