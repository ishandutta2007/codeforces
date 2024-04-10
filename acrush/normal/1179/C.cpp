#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef unsigned long long uint64;
#define two(X) (1<<(X))
#define twoL(X) (((int64)(1))<<(X))
#define contain(S,X) (((S)&two(X))!=0)
#define containL(S,X) (((S)&twoL(X))!=0)
const double pi=acos(-1.0);
const double eps=1e-11;
template<class T> inline void ckmin(T &a,T b){if(b<a) a=b;}
template<class T> inline void ckmax(T &a,T b){if(b>a) a=b;}
template<class T> inline T sqr(T x){return x*x;}
typedef pair<int,int> ipair;
#define SIZE(A) ((int)A.size())
#define LENGTH(A) ((int)A.length())
#define MP(A,B) make_pair(A,B)
#define PB(X) push_back(X)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,a) for(int i=0;i<(a);++i)
#define ALL(A) A.begin(),A.end()
using VI=vector<int>;

const int maxsize=(1<<20);

struct Node
{
	int sum;
	int max_psum;
};
Node tree[maxsize*4];

void update(int id,int s,int t,int key,int delta)
{
	tree[id].sum+=delta;
	if (s==t) { tree[id].max_psum=max(0,tree[id].sum); return; }
	int m=(s+t)/2;
	if (key<=m)
		update(id*2+1,s,m,key,delta);
	else
		update(id*2+2,m+1,t,key,delta);
	tree[id].max_psum=max(tree[id*2+1].max_psum,tree[id*2+1].sum+tree[id*2+2].max_psum);
}
void update(int key,int delta)
{
	update(0,0,maxsize-1,key,delta);
}

ipair calc(int id,int s,int t,int key)
{
	if (key>=t) return MP(tree[id].sum,tree[id].max_psum);
	int m=(s+t)/2;
	ipair ret=calc(id*2+1,s,m,key);
	if (key>m)
	{
		ipair w=calc(id*2+2,m+1,t,key);
		ret.second=max(ret.second,ret.first+w.second);
		ret.first+=w.first;
	}
	return ret;
}
ipair calc(int key)
{
	return calc(0,0,maxsize-1,key);
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
	int n,m;
	while (cin>>n>>m)
	{
		VI a(n);
		REP(i,n) { cin>>a[i]; a[i]=maxsize-a[i]; }
		VI b(m);
		REP(i,m) { cin>>b[i]; b[i]=maxsize-b[i]; }
		memset(tree,0,sizeof(tree));
		REP(i,n) update(a[i],1);
		REP(i,m) update(b[i],-1);
		int nq;
		cin>>nq;
		REP(cl,nq)
		{
			int tp,key,x;
			cin>>tp>>key>>x;
			--key;
			x=maxsize-x;
			if (tp==1)
			{
				update(a[key],-1);
				a[key]=x;
				update(a[key],1);
			}
			else
			{
				update(b[key],1);
				b[key]=x;
				update(b[key],-1);
			}
			int low=-1,high=maxsize;
			while (low+1<high)
			{
				int mid=(low+high)/2;
				if (calc(mid).second>0)
					high=mid;
				else
					low=mid;
			}
			int ret=(high==maxsize?-1:maxsize-high);
			printf("%d\n",ret);
		}
#ifndef _MSC_VER
		break;
#endif
	}
	return 0;
}