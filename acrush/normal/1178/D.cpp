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

bool is_prime(int n)
{
	if (n<2) return false;
	for (int i=2;i*i<=n;i++) if (n%i==0) return false;
	return true;
}
void solve(int n)
{
	VI visited(n);
	vector<ipair> edges;
	int m=n;
	while (!is_prime(m))
	{
		int x=-1,y=-1;
		REP(i,n) if (!visited[i]) 
		{
			FOR(j,i+1,n) if (!visited[j] && (j-i+n)%n!=1 && (i-j+n)%n!=1)
			{
				x=i;
				y=j;
				break;
			}
			if (x>=0) break;
		}
		if (x<0)
		{
			printf("ERROR %d\n",n);
			exit(0);
		}
		visited[x]=visited[y]=1;
		edges.push_back(MP(x,y));
		m++;
	}
	printf("%d\n",n+SIZE(edges));
	REP(i,n) printf("%d %d\n",i+1,(i+1)%n+1);
	for (auto e:edges) printf("%d %d\n",e.first+1,e.second+1);
}
int main()
{
	std::ios::sync_with_stdio(false);
	// for (int n=3;n<=1000;n++) solve(n);
	int n;
	cin>>n;
	solve(n);
	return 0;
}