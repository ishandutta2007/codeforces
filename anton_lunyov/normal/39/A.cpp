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

char s[111111];

bool dig(char c)
{
    return '0'<=c && c<='9';
}

int main()
{
   // freopen("in.txt","r",stdin);
    int a,i,x;
    while(scanf("%d",&a)>0)
    {
        scanf("%s",s+1);
        s[0]='+';
        int c[1111];
        int len=0;
        int ans=0;
        for(i=0;s[i];)
        {
            int sign=s[i]=='-'?-1:1;
            i++;
            if(dig(s[i]))
            {
                x=0;
                for(;dig(s[i]);i++)
                    x=10*x+s[i]-'0';
                i++;
            }
            else x=1;
            c[len++]=sign*x;
            if(s[i]!='a') ans+=sign*x;
            i+=3;
        }
        sort(c,c+len);
        for(i=0;i<len;i++)
            ans+=(a+i)*c[i];
        printf("%d\n",ans);
    }
    return 0;
}