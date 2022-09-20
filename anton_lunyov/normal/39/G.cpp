#include <stdio.h>
#include <assert.h>
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

#define N 1111
char s[N];
int num;
string expr[N],ifs[N];
#define maxN 32768
int f[maxN];

bool dig(char c)
{
    return '0'<=c && c<='9';
}

bool cmp_sign(char c)
{
    return c=='=' || c=='>' || c=='<';
}

int n_;
char tmp[N];
int tmpi;

int eval(int &i)
{
    int ans=0;
    for(;tmp[i] && tmp[i]!=')';)
    {
        int sign=1;
        if(tmp[i]=='+') i++;
        if(tmp[i]=='-') sign=-1,i++;
        int res=1;
        for(;tmp[i] && tmp[i]!=')' && tmp[i]!='+' && tmp[i]!='-';)
        {
            char op='*';
            if(tmp[i]=='*') i++;
            if(tmp[i]=='/') op='/',i++;
            int x;
            if(dig(tmp[i]))
            {
                x=0;
                for(;dig(tmp[i]);i++)
                    x=10*x+tmp[i]-'0';
            }
            else
            {
                if(tmp[i]=='n') x=n_,i++; else
                {
                    i+=2;
                    x=f[eval(i)];
                    i++;
                }
            }
            if(op=='*') res=res*x%maxN; else
                res/=x;
        };
        ans=(ans+sign*res)%maxN;
        if(ans<0) ans+=maxN;
    };
    return ans;
}

int F(int n)
{
    int &res=f[n];
    n_=n;
    int i,j;
    for(j=0;j<num;j++)
    {
        bool logic=true;
        if(ifs[j].sz>0)
        {
            logic=false;
            tmpi=0;
            for(i=0;!cmp_sign(ifs[j][i]);i++)
                tmp[tmpi++]=ifs[j][i];
            tmp[tmpi]=0;
            int log1=eval(tmpi=0);
            char c=ifs[j][i];
            i++;
            if(c=='=') i++;
            tmpi=0;
            for(;i<ifs[j].sz;i++)
                tmp[tmpi++]=ifs[j][i];
            tmp[tmpi]=0;
            int log2=eval(tmpi=0);
            if(c=='<' && log1<log2) logic=true;
            if(c=='>' && log1>log2) logic=true;
            if(c=='=' && log1==log2) logic=true;
        }
        if(!logic) continue;
        tmpi=0;
        for(i=0;i<expr[j].sz;i++)
            tmp[tmpi++]=expr[j][i];
        tmp[tmpi]=0;
        return res=eval(tmpi=0);
    }
    for(;;);
}

int main()
{
   // freopen("in.txt","r",stdin);
    int val;
    while(scanf("%d",&val)>0)
    {
        char c;
        bool start=false;
        int n=0,i,j;
        while(scanf("%c",&c)>0)
        {
            if(c==' ' || c=='\n') continue;
            if(c=='}') break;
            if(c=='{') start=true; else
            if(start) s[n++]=c;
        }
        num=0;
        for(i=j=0;i<n;)
        {
            string ifsj="";
            if(s[i]=='i')
            {
                i+=3;
                for(;s[i+1]!='r';i++) ifsj+=s[i];
                i++;
            }
            ifs[j]=ifsj;
            i+=6;
            string tmp="";
            for(;s[i]!=';';i++) tmp+=s[i];
            expr[j]=tmp;
            i++;
            j++;
        }
        num=j;
        fill(f,255);
        int ans=-1;
        for(n=0;n<maxN;n++)
            if(F(n)==val) ans=n;
        printf("%d\n",ans);
    }
    return 0;
}