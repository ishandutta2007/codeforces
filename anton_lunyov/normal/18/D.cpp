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
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

typedef vector<int> VI;
typedef pair<int,int> PII;
//typedef long long LL;


#define p_len 4
const int p=10000;
#define NN 666/p_len

struct num
{
    int len;
    int it[NN];
    num(int n=0)
    {
        for(len=0;n>0;n/=p) it[len++]=n%p;
    }
};

void operator+=(num &a,const num &b)
{
    int i,div=0;
    for(i=0;i<a.len || i<b.len;i++)
    {
        if(i<a.len) div+=a.it[i];
        if(i<b.len) div+=b.it[i];
        a.it[i]=div%p;
        div/=p;
    }
    if(div>0) a.it[i++]=div;
    a.len=i;
}

num operator*(int b,const num &a)
{
    num prod(0);
    if(b==0) return prod;
    int i,div=0;
    for(i=0;i<a.len;i++)
    {
        div+=a.it[i]*b;
        prod.it[i]=div%p;
        div/=p;
    }
    for(;div>0;div/=p) prod.it[i++]=div%p;
    prod.len=i;
    return prod;
}

void operator*=(num &a,int b)
{
    if(b==0) a.len=0; else
    {
        int i,div=0;
        for(i=0;i<a.len;i++)
        {
            div+=a.it[i]*b;
            a.it[i]=div%p;
            div/=p;
        }
        for(;div>0;div/=p) a.it[i++]=div%p;
        a.len=i;
    }
}

void print(num &a)
{
    if(a.len==0) printf("0"); else
    {
        long i=a.len-1;
        printf("%d",a.it[i]);
        char s[10];
        sprintf(s,"%%0%dd",p_len);
        for(i--;i>=0;i--) printf(s,a.it[i]);
    }
    printf("\n");
}

#define N 5050
#define X 2000
int a[N];
int b[X+1];
int mark[N];

int main()
{
    int n;
    while(scanf("%d",&n)>0)
    {
        int i,x;
        for(i=0;i<n;i++)
        {
            char tmp[11];
            scanf("%s %d",tmp,&x);
            if(tmp[0]=='w') a[i]=-x-1; else a[i]=x+1;
        }
        fill(b,0);
        fill(mark,0);
        for(x=X;x>=0;x--)
        {
            int curw=-1;
            for(i=0;i<n;i++)
                if(mark[i]) curw=-1; else
                if(a[i]==-x-1) curw=i; else
                if(a[i]==x+1 && curw>=0)
                {
                    b[x]++;
                    for(int j=curw;j<=i;j++) mark[j]=1;
                    curw=-1;
                }
        }
        num p2(1);
        num ans(0);
        for(x=0;x<=X;x++)
        {
            ans+=b[x]*p2;
            p2*=2;
        }
        print(ans);
    }
    return 0;
}