#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#pragma comment(linker, "/STACK:16777216")
using namespace std;

#define bit(n) (1<<(n))
#define inf 1000000000
#define eps 1e-9
#define PI 3.1415926535897932385
#define pb push_back
#define sz size()
#define mp make_pair
#define cl clear()
#define all(a) a.begin(),a.end()
#define fill(ar,val) memset(ar,val,sizeof ar)
#define MIN(a,b) if(a>(b)) a=(b)
#define MAX(a,b) if(a<(b)) a=(b)
#define sqr(x) ((x)*(x))
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))

typedef vector<int> VI;
typedef pair<int,int> PII;
typedef __int64 LL;

int n;
char win[33333][33];//1 - first , 2 - second , 3 - draw

bool good(int a,int b)
{
    int p=1;
    int i;
    for(i=0;i<b;i++)
    {
        if(p>(n-1)/a) return false;
        p*=a;
    }
    return true;
}

char WIN(int a,int b)
{
    char &res=win[a][b];
    if(res) return res;
    if(!good(a,b)) return res=1;
    if(a==1 && !good(2,b)) return res=3;
    if(b==1 && !good(a,2)) return res=1+(n-a)%2;
    char wa=WIN(a+1,b);
    char wb=WIN(a,b+1);
    if(wa==2 || wb==2) return res=1;
    if(wa==3 || wb==3) return res=3;
    return res=2;
}

int main()
{
  //  freopen("in.txt","r",stdin);
    int a,b;
    while(scanf("%d%d%d",&a,&b,&n)>0)
    {
        fill(win,0);
        int res=WIN(a,b);
        if(res==1) puts("Masha"); else
        if(res==2) puts("Stas"); else
            puts("Missing");
    }
    return 0;
}