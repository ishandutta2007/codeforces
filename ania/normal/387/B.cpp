#include<algorithm>
#include<bitset>
#include<cctype>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<deque>
#include<functional>
#include<iomanip>
#include<iostream>
#include<list>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#include<utility>
#include<vector>

using namespace std;

#define REP(i,a,b) for(int i = (a); i <= (b); ++i)
#define FORI(i,n) REP(i,1,n)
#define FOR(i,n) REP(i,0,int(n)-1)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define ll long long
#define FOREACH(i,t) for (typeof(t.begin()) i = t.begin(); i != t.end(); ++i)
#define fi first
#define se second

int a[3333], b[3333];

int main() {
   int n,m;
   scanf("%d%d", &n, &m);
   FOR(i,n) scanf("%d", &a[i]);
   FOR(j,m) scanf("%d", &b[j]);
   sort(a,a+n);
   sort(b,b+m);
   int pos = 0, res = 0;
   FOR(i,n) {
      while (pos < m && a[i] > b[pos]) pos++;
      if (pos >= m) res++;
      else pos++;
   }
   printf("%d\n", res);
   return 0;
}