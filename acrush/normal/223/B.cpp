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

const int maxn=200000+5;

int n,m;
char a[maxn],b[maxn];
int f1[maxn],f2[maxn];
int s[26][maxn];

void prepare(int f[])
{
	int L=0;
	f[0]=0;
	for (int i=1;i<=n;i++)
	{
		if (L<m && b[L+1]==a[i]) L++;
		f[i]=L;
		if (f[i]==m) f[i]=m-1;
	}
}
bool solve()
{
	n=strlen(a+1);
	m=strlen(b+1);
	prepare(f1);
	reverse(a+1,a+n+1);
	reverse(b+1,b+m+1);
	prepare(f2);
	reverse(f2+1,f2+n+1);
	reverse(a+1,a+n+1);
	reverse(b+1,b+m+1);
	memset(s,0,sizeof(s));
	for (int c=0;c<26;c++) for (int i=1;i<=m;i++) s[c][i]=s[c][i-1]+(int)(b[i]==c+'a');
	for (int i=1;i<=n;i++)
	{
		if (f1[i-1]+f2[i+1]<m-1) return false;
		if (s[a[i]-'a'][f1[i-1]+1]==s[a[i]-'a'][m-f2[i+1]-1]) return false;
	}
	return true;
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	while (scanf("%s%s",a+1,b+1)!=-1)
		if (solve())
			printf("Yes\n");
		else
			printf("No\n");
	return 0;
}