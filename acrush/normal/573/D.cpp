#include <cstdio> 
#include <iostream> 
#include <cmath> 
#include <string> 
#include <list> 
#include <vector> 
#include <algorithm> 
#include <functional> 
#include <utility> 
#include <set> 
#include <map> 
#include <complex> 
#include <queue> 
#include <stack> 
#include <cstdlib> 
#include <ctime> 
#include <cstring> 
#include <string.h> 

using namespace std; 

typedef unsigned int uint; 
typedef long long int64; 
typedef unsigned long long uint64; 
typedef unsigned short ushort; 
typedef unsigned char uchar; 
typedef pair<int,int> ipair; 
typedef vector<int> VI; 
typedef vector<string> VS; 
typedef vector<double> VD; 
#define SIZE(A) ((int)(A.size()))
#define LENGTH(A) ((int)(A.length()))
#define MP(A,B) make_pair(A,B)
const double pi=acos(-1.0); 
const double eps=1e-11; 

const int maxn=30000+16;
const int64 oo=1000000000LL*1000000000LL;

int n;
ipair a[maxn],b[maxn];
int p[maxn];
int64 tree[maxn*8][6][6];
int ra[maxn];

void initialize(int k,int64 c[6][6])
{
	if (k<0 || k>=n) return;
	int pk=p[a[k].second];
	int64 e[6];
	e[1]=(k-2>=0 && b[k-2].second!=pk)?(int64)a[k].first*b[k-2].first:-oo;
	e[2]=(k-1>=0 && b[k-1].second!=pk)?(int64)a[k].first*b[k-1].first:-oo;
	e[3]=(b[k].second!=pk)?(int64)a[k].first*b[k].first:-oo;
	e[4]=(k+1<n && b[k+1].second!=pk)?(int64)a[k].first*b[k+1].first:-oo;
	e[5]=(k+2<n && b[k+2].second!=pk)?(int64)a[k].first*b[k+2].first:-oo;
	for (int i=0;i<6;i++) for (int j=0;j<6;j++) c[i][j]=-oo;
	c[0][0]=e[3]; c[0][1]=e[4]; c[0][2]=e[5];
	c[1][0]=e[2]; c[1][3]=e[4]; c[1][4]=e[5];
	c[2][1]=e[2]; c[2][3]=e[3]; c[2][5]=e[5];
	c[3][0]=e[1]; c[4][1]=e[1]; c[5][3]=e[1];
}
void combine(int64 c[6][6],int64 a[6][6],int64 b[6][6])
{
	for (int i=0;i<6;i++) for (int j=0;j<6;j++) c[i][j]=-oo;
	for (int i=0;i<6;i++) for (int j=0;j<6;j++) for (int k=0;k<6;k++) 
	{
		int64 t=a[i][k]+b[k][j];
		if (t>c[i][j]) c[i][j]=t;
	}
}
void init_tree(int id,int s,int t)
{
	if (s==t) { initialize(s,tree[id]); return; }
	int m=(s+t)/2;
	init_tree(id*2+1,s,m);
	init_tree(id*2+2,m+1,t);
	combine(tree[id],tree[id*2+1],tree[id*2+2]);
}
void update_tree(int id,int s,int t,int key)
{
	if (s==t) { initialize(s,tree[id]); return; }
	int m=(s+t)/2;
	if (key<=m) update_tree(id*2+1,s,m,key);
	else update_tree(id*2+2,m+1,t,key);
	combine(tree[id],tree[id*2+1],tree[id*2+2]);
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios_base::sync_with_stdio(false);
	int q;
	while (cin>>n>>q)
	{
		for (int i=0;i<n;i++) cin>>a[i].first;
		for (int i=0;i<n;i++) cin>>b[i].first;
		for (int i=0;i<n;i++) a[i].second=b[i].second=i;
		sort(a,a+n);
		sort(b,b+n);
		for (int i=0;i<n;i++) ra[a[i].second]=i;
		for (int i=0;i<n;i++) p[i]=i;
		init_tree(0,0,n-1);
		for (;q>0;q--)
		{
			int x,y;
			cin>>x>>y;
			--x;
			--y;
			swap(p[x],p[y]);
			if (x!=y)
			{
				update_tree(0,0,n-1,ra[x]);
				update_tree(0,0,n-1,ra[y]);
			}
			cout<<tree[0][0][0]<<endl;
		}
	}
	return 0;
}