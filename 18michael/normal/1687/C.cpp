#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,m,p,Test_num;
LL a[200002];
vector<int> vec[200002];
set<int> st;
set<int>::iterator it;
queue<int> q,ept;
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
int main()
{
	read(Test_num);
	while(Test_num--)
	{
		read(n),read(m),st.clear(),q=ept,vec[0].clear(),q.push(0);
		for(int i=1;i<=n;++i)read(a[i]),vec[i].clear();
		for(int i=1,x;i<=n;++i)
		{
			read(x),a[i]-=x,a[i]+=a[i-1];
			if(a[i])st.insert(i);
			else q.push(i);
		}
		for(int i=1,x,y;i<=m;++i)read(x),read(y),vec[x-1].push_back(y),vec[y].push_back(x-1);
		for(;!q.empty();)
		{
			p=q.front(),q.pop();
			//printf("p:%d\n",p);
			for(int i=0,s,e;i<vec[p].size();++i)
				if(!st.count(vec[p][i]))
				{
					s=min(p,vec[p][i]),e=max(p,vec[p][i]);
					//printf(" %d ~ %d\n",s,e);
					for(it=st.lower_bound(s);it!=st.end() && (*it)<=e;it=st.erase(it))q.push(*it);
				}
		}
		puts(st.empty()? "YES":"NO");
	}
	return 0;
}
/*
3
5 2
1 5 4 2 3
3 2 5 4 1
1 3
2 5

5 2
1 5 4 2 3
3 2 4 5 1
1 2
2 4

5 2
4 3 5 1 2
3 4 5 2 1
1 4
4 5
*/