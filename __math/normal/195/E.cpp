#define _USE_MATH_DEFINES
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cfloat>
#include <ctime>
#include <cassert>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <numeric>
#include <list>
#include <iomanip>


#ifdef _DEBUG
#define typeof(X) std::identity<decltype(X)>::type //C++0x (for vs2010)
#else
#define typeof(X) __typeof__(X) // for gcc
#endif

#define sz(a)  int((a).size())
#define FOREACH(it, c) for (typeof((c).begin()) it=(c).begin(); it != (c).end(); ++it)
#define FOR(i,count) for (int i = 0; i < (count); i++)
#define V_CIN(v) do{for(int i = 0; i < sz(v); i++) cin >> (v)[i];}while(0)
#define all(c) (c).begin(),(c).end()

template <class T> void max_swap(T& a, const T& b) { a = max(a, b); }
template <class T> void min_swap(T& a, const T& b) { a = min(a, b); }

using namespace std;
static const double EPS = 1e-5;
typedef long long ll;
const int MODULO = 1000000007;
const int INF = 100000000; //1e8

typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef complex<double> Cd;

//BEGIN!!!

const int p=1000000007;
int ans,f[100001],w[100001];

int find(int x)
{
  if(f[x]==0)
    return x;
  int y=f[x];
  f[x]=find(f[x]);
  w[x]=(w[x]+w[y])%p;
  return f[x];
}

void merge(int x,int y,int z)
{
  int fy=find(y);
  w[fy]=(w[y]+z)%p;
  ans=(ans+w[fy])%p;
  f[fy]=x;
}

int main(void)
{
  int n;
  scanf("%d",&n);
  for(int i=1;i<=n;++i)
  {
    int m;
    scanf("%d",&m);
    for(int j=1;j<=m;++j)
    {
      int k,l;
      scanf("%d %d",&k,&l);
      merge(i,k,l);
    }
  }
  printf("%d\n",(ans+p)%p);
  return 0;
}