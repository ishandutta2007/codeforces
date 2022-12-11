#include <algorithm>
#include <iostream>
#include <sstream>
#include <utility>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <ctime>
#include <stack>
#include <map>
#include <set>
using namespace std;
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define fs first
#define sc second
#define LL long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define forit(it,S) for(__typeof((S).begin()) it = (S).begin(); it != (S).end(); it++)
#define abs(a) ((a)<0?-(a):(a))
#define sqr(a) ((a)*(a))
typedef pair<int, int> pii;
const double eps = 1e-9;
const int mod = (int)1e+9 + 7;
const double pi = acos(-1.0);
long long gcd(long long a,long long b)
{
 while(a>0)
 {
 	b%=a;
 	swap(a,b);
 }
 return(b);
}
int main()
{
//	freopen("*.in","r",stdin);
//	freopen("*.out","w",stdout);
	long long a,b,c,d,g,o=0;
	scanf("%I64d%I64d",&a,&b);
	if(a==1&&b==1){printf("1");return(0);}
	for(;a>1||b>1;)
	{
		c=a;d=b;
		o+=max(c,d)/min(c,d);	
		a=max(c,d)%min(c,d);
		b=min(c,d);
		g=gcd(a,b);
		a/=g;
		b/=g;
	}
	printf("%I64d",o);
	return 0;
}