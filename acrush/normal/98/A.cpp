#include <string>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <list>
#include <map>
#include <set>
#include <bitset>
#include <functional>
#include <utility>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
 
using namespace std;
 
typedef long long int64;
typedef unsigned long long uint64;
#define two(X) (1<<(X))
#define twoL(X) (((int64)(1))<<(X))
#define contain(S,X) ((S&two(X))>0)
#define containL(S,X) ((S&twoL(X))>0)
typedef pair<int,int> ipair;
int countbit(int n) {return (n==0)?0:(1+countbit(n&(n-1)));}
int lowbit(int n) {return (n^(n-1))&n;}
const double pi=acos(-1.0);
const double eps=1e-11;
template<class T> T sqr(T x) {return x*x;}
template<class T> void checkmin(T &a,T b) {if (b<a) a=b;}
template<class T> void checkmax(T &a,T b) {if (b>a) a=b;}
#define SIZE(X) ((int)((X).size()))
#define LENGTH(X) ((int)((X).length()))
#define MP(A,B) make_pair(A,B)

const int p[24][6] =
{
  {1, 2, 3, 4, 5, 6},
  {1, 2, 5, 6, 4, 3},
  {1, 2, 4, 3, 6, 5},
  {1, 2, 6, 5, 3, 4},
  {2, 1, 4, 3, 5, 6},
  {2, 1, 5, 6, 3, 4},
  {2, 1, 3, 4, 6, 5},
  {2, 1, 6, 5, 4, 3},
  {3, 4, 2, 1, 5, 6},
  {3, 4, 5, 6, 1, 2},
  {3, 4, 1, 2, 6, 5},
  {3, 4, 6, 5, 2, 1},
  {4, 3, 1, 2, 5, 6},
  {4, 3, 5, 6, 2, 1},
  {4, 3, 2, 1, 6, 5},
  {4, 3, 6, 5, 1, 2},
  {5, 6, 1, 2, 3, 4},
  {5, 6, 3, 4, 2, 1},
  {5, 6, 2, 1, 4, 3},
  {5, 6, 4, 3, 1, 2},
  {6, 5, 2, 1, 3, 4},
  {6, 5, 3, 4, 1, 2},
  {6, 5, 1, 2, 4, 3},
  {6, 5, 4, 3, 2, 1}
};


int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	set<string> M;
	int R=0;
	char s[10];
	scanf("%s",s);
	sort(s,s+6);
	do{
		string g="";
		for (int i=0;i<6;i++) g+=s[i];
		if (M.find(g)!=M.end()) continue;
		R++;
		for (int k=0;k<24;k++)
		{
			string h="";
			for (int i=0;i<6;i++) h+=g[p[k][i]-1];
			M.insert(h);
		}
	}while (next_permutation(s,s+6)!=0);
	printf("%d\n",R);
	return 0;
}