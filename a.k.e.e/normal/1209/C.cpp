#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define enum(i,x,y) for(int i=(x);i<=(y);++i)
#define try(i,x,y) for(int i=(x);i>=(y);--i)
#define mp make_pair
#define pb push_back
#define v first
#define c second
template <typename TYPE> inline void chkmin(TYPE &a,TYPE b){b<a?a=b:0;}
template <typename TYPE> inline void chkmax(TYPE &a,TYPE b){a<b?a=b:0;}
template <typename TYPE> inline void readint(TYPE &x)
{
	x=0;int f=1;char c;
	for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+c-'0';
	x*=f;
}
typedef set<int>::iterator iter;
const int MAXN=200005;

int n,pre[MAXN],nxt[MAXN],col[MAXN];
vector<int> a[MAXN];
char s[MAXN];
set<int> c1;
void solve()
{
	memset(a,0,sizeof(a));
	readint(n);scanf("%s",s+1);s[0]='0';s[n+1]='9';
	enum(i,1,n)pre[i]=i-1,nxt[i]=i+1,col[i]=2;
	try(i,n,1)a[s[i]-'0'].pb(i);
	int cur=0;
	enum(i,1,n)
		if(s[i]<s[pre[i]])++cur;
	if(!cur)
	{
		enum(t,1,n)putchar('0'+col[t]);
		putchar('\n');return;
	}
	c1.clear();c1.insert(n+1);c1.insert(0);
	enum(k,0,9)
		for(auto i:a[k])
		{
			col[i]=1;
			iter itr=c1.lower_bound(i),itl=itr;--itl;
			int r=*itr,l=*itl;
			if(s[nxt[i]]<s[i])--cur;
			pre[nxt[i]]=pre[i];nxt[pre[i]]=nxt[i];
			if(s[nxt[i]]<s[pre[i]])++cur;
			if(s[r]<s[pre[r]])--cur;
			pre[r]=i;nxt[i]=r;
			if(s[r]<s[i])++cur;
			if(s[i]<s[pre[i]])--cur;
			pre[i]=l;nxt[l]=i;
			if(s[i]<s[l])++cur;
			c1.insert(i);
//cerr<<"("<<i<<","<<cur<<"):"<<endl;
//cerr<<"\t";enum(j,1,n)cerr<<pre[j]<<" ";cerr<<endl;
//cerr<<"\t";enum(j,1,n)cerr<<nxt[j]<<" ";cerr<<endl;
			if(!cur)
			{
				enum(t,1,n)putchar('0'+col[t]);
				putchar('\n');return;
			}
		}
	printf("-\n");
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("code.in","r",stdin);
	//freopen("code.out","w",stdout);
	#endif
	int T;
	readint(T);
	while(T--)solve();
	return 0;
}