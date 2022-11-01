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

int n,m;
char a[25][25];

string rotate(string s,int &dx,int &dy)
{
	string r="";
	for (int i=0;i<dy;i++) for (int j=0;j<dx;j++) r+=s[j*dy+(dy-1-i)];
	swap(dx,dy);
	return r;
}
string getstr(int x1,int y1,int dx,int dy)
{
	string s="";
	for (int i=0;i<dx;i++) for (int j=0;j<dy;j++) s+=a[x1+i][y1+j];
	string r="";
	for (int step=0;step<4;step++)
	{
		if (dx<=dy && (r=="" || s<r)) r=s;
		s=rotate(s,dx,dy);
	}
	return r;
}
bool solve(int x,int y)
{
	set<string> M;
	for (int i=0;i<n;i+=x) for (int j=0;j<m;j+=y)
	{
		string s=getstr(i,j,x,y);
		if (M.find(s)!=M.end()) return false;
		M.insert(s);
	}
	return true;
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++) scanf("%s",a[i]);
	int rx=-1,ry=-1,cnt=0;
	for (int x=1;x<=n;x++) if (n%x==0)
		for (int y=1;y<=m;y++) if (m%y==0)
			if (solve(x,y))
			{
				cnt++;
				if (rx<0 || x*y<rx*ry) rx=x,ry=y;
			}
	printf("%d\n%d %d\n",cnt,rx,ry);
	return 0;
}