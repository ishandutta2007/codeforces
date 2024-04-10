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

string str[]={"Gryffindor", "Hufflepuff", "Ravenclaw","Slytherin"};

const int maxn=10000+5;
const int maxsize=2000000+5;

int n;
char s[maxn];
int m;
ipair a[maxsize];

int get_id(char c)
{
	for (int i=0;i<4;i++) if (str[i][0]==c) return i;
	return -1;
}

int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	scanf("%d",&n);
	scanf("%s",s);
	m=1;
	a[0]=MP(0,0);
	for (int step=0;step<n;step++)
	{
		int key=get_id(s[step]);
		switch (key)
		{
		case 0: for (int i=0;i<m;i++) a[i].first++; break;
		case 1: for (int i=0;i<m;i++) a[i].first+=65536; break;
		case 2: for (int i=0;i<m;i++) a[i].second++; break;
		case 3: for (int i=0;i<m;i++) a[i].second+=65536; break;
		case -1:
			{
				int s=m;
				for (int i=0;i<m;i++)
				{
					ipair key=a[i];
					int v0=a[i].first&65535;
					int v1=a[i].first>>16;
					int v2=a[i].second&65535;
					int v3=a[i].second>>16;
					bool ext=true;
					int d=min(min(v0,v1),min(v2,v3));
					if (v0==d)
						if (ext) a[i].first++,ext=false;
						else a[s]=key,a[s].first++,s++;
					if (v1==d)
						if (ext) a[i].first+=65536,ext=false;
						else a[s]=key,a[s].first+=65536,s++;
					if (v2==d)
						if (ext) a[i].second++,ext=false;
						else a[s]=key,a[s].second++,s++;
					if (v3==d)
						if (ext) a[i].second+=65536,ext=false;
						else a[s]=key,a[s].second+=65536,s++;
				}
				sort(a,a+s);
				m=unique(a,a+s)-a;
				break;
			}
		}
	}
	bool r[4];
	memset(r,false,sizeof(r));
	for (int i=0;i<m;i++)
	{
		int v0=a[i].first&65535;
		int v1=a[i].first>>16;
		int v2=a[i].second&65535;
		int v3=a[i].second>>16;
		int d=min(min(v0,v1),min(v2,v3));
		if (v0==d) r[0]=true;
		if (v1==d) r[1]=true;
		if (v2==d) r[2]=true;
		if (v3==d) r[3]=true;
	}
	for (int i=0;i<4;i++) if (r[i])
		printf("%s\n",str[i].c_str());
	return 0;
}