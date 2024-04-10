#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <string.h>

using namespace std;

typedef long long int64;
typedef unsigned long long uint64;
#define two(X) (1<<(X))
#define twoL(X) (((int64)(1))<<(X))
#define contain(S,X) (((S)&two(X))!=0)
#define containL(S,X) (((S)&twoL(X))!=0)
const double pi=acos(-1.0);
const double eps=1e-11;
template<class T> inline void checkmin(T &a,T b){if(b<a) a=b;}
template<class T> inline void checkmax(T &a,T b){if(b>a) a=b;}
template<class T> inline T sqr(T x){return x*x;}
typedef pair<int,int> ipair;
#define SIZE(A) ((int)A.size())
#define LENGTH(A) ((int)A.length())
#define MP(A,B) make_pair(A,B)
#define PB(X) push_back(X)

const int maxn=100000+16;
const int M=500;
const int L=maxn/M;

struct Segment
{
	int cnt;
	int pos[L+16];
	int val[L+16];
	void split_to(int c,Segment* s1,Segment* s2)
	{
		s1->cnt=c;
		s2->cnt=cnt-c;
		int p1=0,p2=0;
		for (int i=0;i<cnt;i++)
			if (pos[i]<c)
			{
				s1->pos[p1]=pos[i];
				s1->val[p1]=val[i];
				p1++;
			}
			else
			{
				s2->pos[p2]=pos[i]-c;
				s2->val[p2]=val[i];
				p2++;
			}
	}
	int solve(int s,int t,int target)
	{
		if (s>cnt-1 || t<0) return 0;
		int H=-1,T=cnt;
		for (;H+1<T;)
		{
			int M=H+(T-H)/2;
			if (val[M]<target) H=M;
			else T=M;
		}
		if (T>=cnt || val[T]!=target) return 0;
		int src=T;
		H=src,T=cnt;
		for (;H+1<T;)
		{
			int M=H+(T-H)/2;
			if (val[M]==target) H=M;
			else T=M;
		}
		if (s<=0 && t>=cnt-1) return T-src;
		int ret=0;
		for (int i=src;i<T;i++) if (pos[i]>=s && pos[i]<=t) ret++;
		return ret;
	}
};

int n;
int a[maxn];
int m;
Segment *seg[M+M+16];
int buffer_pos;
Segment seg_buffer[M*8+16];
int lastans=0;

Segment* new_seg()
{
	return &seg_buffer[buffer_pos++];
}
void decode(int &t)
{
	t=(t+lastans-1)%n+1;
}
void rebuild_buckets()
{
	buffer_pos=0;
	m=0;
	ipair q[L+16];
	for (int i=0;i<n;i+=L)
	{
		int c=min(L,n-i);
		seg[m]=new_seg();
		seg[m]->cnt=c;
		for (int k=0;k<c;k++) q[k]=MP(a[i+k],k);
		sort(q,q+c);
		for (int k=0;k<c;k++)
		{
			seg[m]->val[k]=q[k].first;
			seg[m]->pos[k]=q[k].second;
		}
		m++;
	}
}
int solve(int left_pos,int right_pos,int target)
{
	int ret=0;
	int s=0;
	for (int i=0;i<m;i++)
	{
		int t=s+seg[i]->cnt-1;
		if (s<=right_pos && t>=left_pos) ret+=seg[i]->solve(left_pos-s,right_pos-s,target);
		s=t+1;
	}
	return ret;
}
int cut_at(int pos)
{
	int s=0;
	for (int i=0;i<m;i++)
	{
		if (s==pos) return i;
		int t=s+seg[i]->cnt-1;
		if (t+1==pos) return i+1;
		if (pos>s && pos<=t)
		{
			m++;
			for (int k=m-1;k>i+1;k--) seg[k]=seg[k-1];
			Segment* tmp=seg[i];
			seg[i]=new_seg();
			seg[i+1]=new_seg();
			tmp->split_to(pos-s,seg[i],seg[i+1]);
			return i+1;
		}
		s=t+1;
	}
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	rebuild_buckets();
	int num_queries;
	for (scanf("%d",&num_queries);num_queries>0;num_queries--)
	{
		int t,left_pos,right_pos,target;
		scanf("%d",&t);
		if (t==1)
		{
			scanf("%d%d",&left_pos,&right_pos);
			decode(left_pos);
			decode(right_pos);
			left_pos--;
			right_pos--;
			if (left_pos>right_pos) swap(left_pos,right_pos);
			int p1=cut_at(left_pos);
			int p2=cut_at(right_pos);
			int p3=cut_at(right_pos+1);
			Segment *tmp=seg[p2];
			for (int i=p2;i>p1;i--) seg[i]=seg[i-1];
			seg[p1]=tmp;
		}
		else
		{
			scanf("%d%d%d",&left_pos,&right_pos,&target);
			decode(left_pos);
			decode(right_pos);
			decode(target);
			left_pos--;
			right_pos--;
			if (left_pos>right_pos) swap(left_pos,right_pos);
			lastans=solve(left_pos,right_pos,target);
			printf("%d\n",lastans);
		}
		if (m>=M+M) 
		{
			int s=0;
			for (int i=0;i<m;i++)
			{
				for (int j=0;j<seg[i]->cnt;j++) a[s+seg[i]->pos[j]]=seg[i]->val[j];
				s+=seg[i]->cnt;
			}
			rebuild_buckets();
		}
	}
	return 0;
}