#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include<bits/stdc++.h>
#define Mx 2000002
#define LL long long
using namespace std;
int n,t=0;LL s,e;
int a[1000002],rt[1000002];
typedef pair<LL,LL> P;
set<P> st;
set<P>::iterator it;
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline void getroot(int x)
{
	if(x==rt[x])return ;
	getroot(rt[x]),rt[x]=rt[rt[x]];
}
int main()
{
	read(n);
	for(int i=1;i<=n;++i)read(a[i]),rt[i]=i;
	for(LL i=1;i<=Mx;++i)
		for(int j=1,k;j<=n;j=rt[j]+1)
		{
			getroot(j);
			for(k=rt[j]+1;k<=n && a[j]+i>=a[k];k=rt[k]+1)getroot(k),rt[rt[j]]=rt[k];
			getroot(j),s=max(i*i+i+1-a[rt[j]],0LL),e=i*i+2*i-a[j];
			if(s<=e)
			{
				for(it=st.lower_bound(P(s,0));it!=st.begin() && (*(--it)).second>=s-1;it=st.erase(it))
					s=min(s,(*it).first),e=max(e,(*it).second);
				for(it=st.lower_bound(P(s,0));it!=st.end() && (*it).first<=e+1;it=st.erase(it))
					s=min(s,(*it).first),e=max(e,(*it).second);
				st.insert(P(s,e));
			}
		}
	return 0&printf("%lld",(*st.begin()).first? 0:(*st.begin()).second+1);;
}
/*
4
1 15 35553 2000000

5
1 50 100 150 200
*/