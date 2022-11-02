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

const int maxsize=100000+5;
const int64 INF=(1LL<<60);

int n,m;
int a[maxsize],b[maxsize];
int64 ha,hb;
int64 ret;

int main()
{
#ifdef _MSC_VER
	if (0)
	{
		freopen("big.txt","w",stdout);
		printf("1000 1000\n");
		for (int i=0;i<1000;i++) printf("%d ",rand()%1000+1); printf("\n");
		for (int i=0;i<1000;i++) printf("%d ",rand()%1000+1); printf("\n");
		return 0;
	}
	freopen("input.txt","r",stdin);
	//freopen("big.txt","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	for (int i=0;i<m;i++) scanf("%d",&b[i]);
	ret=-1;
	for (int step=0;step<2;step++)
	{
		ha=hb=0;
		for (int i=0;i<n;i++) ha+=a[i];
		for (int i=0;i<m;i++) hb+=b[i];
		sort(a,a+n);
		sort(b,b+m);
		int64 sb=0;
		for (int k=0;k<m;k++)
		{
			if (m-k<=INF/ha)
			{
				int64 t=sb+ha*(m-k);
				if (ret<0 || t<ret) ret=t;
			}
			sb+=b[k];
		}
		for (int k=0;k<max(n,m);k++) swap(a[k],b[k]);
		swap(n,m);
	}
	cout<<ret<<endl;
	return 0;
}