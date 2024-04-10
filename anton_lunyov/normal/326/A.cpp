#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <complex>
#include <queue>
#pragma comment(linker, "/STACK:266777216")
using namespace std;

#define assert(f) { if(!(f)) { fprintf(stderr,"Assertion failed: "); fprintf(stderr,#f); fprintf(stderr,"\n"); exit(1); } }

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> PII;
typedef vector<PII> VPII;
typedef vector<double> VD;
typedef pair<double,double> PDD;

const int inf=1000000000;
const LL INF=LL(inf)*inf;
const double eps=1e-9;
const double PI=2*acos(0.0);
#define bit(n) (1<<(n))
#define bit64(n) ((LL(1))<<(n))
#define pb push_back
#define sz size()
#define mp make_pair
#define cl clear()
#define all(a) (a).begin(),(a).end()
#define fill(ar,val) memset((ar),(val),sizeof (ar))
#define MIN(a,b) {if((a)>(b)) (a)=(b);}
#define MAX(a,b) {if((a)<(b)) (a)=(b);}
#define sqr(x) ((x)*(x))
#define X first
#define Y second

//clock_t start=clock();
//fprintf(stderr,"time=%.3lfsec\n",0.001*(clock()-start));

int main()
{
#ifdef MY_SIDE
  freopen("a.in","r",stdin);
#endif
  char s[1111];
  int n;
  while(scanf("%s%d",s,&n)>0)
  {
    int cnt[26]={0};
    for(int i=0;s[i];i++)
      cnt[s[i]-'a']++;
    int num=0;
    for(int i=0;i<26;i++)
      if(cnt[i]) num++;
    string res="-1";
    if(num>n) puts("-1"); else
    {
      int L=0;
      int R=1111;
      while(L+1<R)
      {
        int M=(L+R)/2;
        int cur=0;
        for(int i=0;i<26;i++)
          cur += (cnt[i]+M-1)/M;
        if(cur>n) L=M; else {
          res="";
          for(int i=0;i<26;i++)
            for(int x=(cnt[i]+M-1)/M;x--;)
              res+=char('a'+i);
          while(res.sz<n) res+='a';
          R=M;
        }
      }
      printf("%d\n",R);
      puts(res.c_str());
    }
  }
  return 0;
}