#include<bits/stdc++.h>
using namespace std;
int n,las,now,Test_num,ok;
int a[100002],nx[100002],la[100002];
vector<int> v;queue<int> q;
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline int gcd(int a,int b)
{
	return b? gcd(b,a%b):a;
}
int main()
{
	read(Test_num);
	while(Test_num--)
	{
		read(n),ok=1,v.clear();
		for(int i=1;i<=n;++i)read(a[i]),nx[i]=(i%n)+1,la[i]=(i+n-2)%n+1,q.push(nx[i]);
		while(!q.empty())
		{
			now=q.front(),q.pop();
			//printf("%d %d\n",now,q.size());
			if(gcd(a[now],a[la[now]])==1)
			{
				//printf("vpb(%d)\n",now);
				v.push_back(now),nx[la[now]]=nx[now],la[nx[now]]=la[now];
				if(v.size()==n)break;
				if(!q.empty() && q.front()==nx[now])q.pop();
				if(now!=nx[now])q.push(nx[now]);
			}
		}
		printf("%d",v.size());
		for(int i=0;i<v.size();++i)printf(" %d",v[i]);
		puts("");
	}
	return 0;
}