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

#define N 50505
#define K 103
char s[N];
int dp[N][K];
int Prev[26][N];

int main()
{
#ifdef MY_SIDE
  freopen("b.in","r",stdin);
#endif
  while(scanf("%s",s)>0)
  {
    int n=strlen(s);
    for(int i=0;i<n;i++)
    {
      for(int c=0;c<26;c++)
        Prev[c][i] = i ? Prev[c][i-1] : -1;
      Prev[s[i]-'a'][i]=i;
    }
    for(int i=0;i<n;i++)
    {
      dp[i][0]=i+1;
      dp[i][1]=i;
      for(int k=2;k<K;k++)
      {
        dp[i][k]=-1;
        if(i==0) continue;
        dp[i][k] = dp[i-1][k];
        int j = dp[i-1][k-2];
        if(j>0) MAX(dp[i][k], Prev[s[i]-'a'][j-1]);
      }
    }
    int k;
    for(k=100;dp[n-1][k]<0;k--);
    fprintf(stderr,"%d\n",k);
    string pref="";
    for(int i=n;i--;)
    {
      if(k<=1) {
        string suf = pref;
        reverse(all(suf));
        string res = pref;
        if(k==1) res += s[i];
        res += suf;
        puts(res.c_str());
        break;
      }
      if(dp[i][k]==dp[i-1][k]) continue;
      pref+=s[i];
      k-=2;
    }
  }
  return 0;
}