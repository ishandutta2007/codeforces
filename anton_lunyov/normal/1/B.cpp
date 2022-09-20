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
#define pi 3.1415926535897932385
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
//typedef long long LL;

int main()
{
    //freopen("in.txt","r",stdin);
    int T;
    for(scanf("%d%*c",&T);T--;)
    {
        char s[55];
        gets(s);
        int i,k,x,y;
        if(sscanf(s,"R%dC%d",&y,&x)==2)
        {
            int p=26;
            for(k=1;;k++)
            {
                if(x<=p) break;
                x-=p;
                p*=26;
            }
            x--;
            for(i=0;i<k;i++)
            {
                s[k-i-1]=x%26+'A';
                x/=26;
            }
            sprintf(s+k,"%d",y);
            puts(s);
        }
        else
        {
            int x=0,y=0;
            int p=26;
            i=0;
            for(;;)
            {
                x=26*x+(s[i]-'A');
                i++;
                if('A'>s[i] || s[i]>'Z') break;
                y+=p;
                p*=26;
            }
            x+=y+1;
            sscanf(s+i,"%d",&y);
            printf("R%dC%d\n",y,x);
        }
    }
    return 0;
}