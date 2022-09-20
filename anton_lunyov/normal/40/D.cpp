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

typedef vector<int> VI;
typedef pair<int,int> PII;
typedef long long LL;
typedef unsigned long long ULL;

#define bit(n) (1<<(n))
#define bit64(n) ((LL(1))<<(n))
#define inf 1000000000
#define eps 1e-9
#define PI 3.1415926535897932385
#define pb push_back
#define sz size()
#define mp make_pair
#define cl clear()
#define X first
#define Y second
#define all(a) a.begin(),a.end()
#define fill(ar,val) memset(ar,val,sizeof ar)
#define MIN(a,b) if(a>(b)) a=(b)
#define MAX(a,b) if(a<(b)) a=(b)
#define sqr(x) ((x)*(x))

#define p_len 4
const int p=10000;
#define NN 1000/p_len

struct num
{
    int len;
    int it[NN];

    num(int n=0)
    {
        for(len=0;n>0;n/=p) it[len++]=n%p;
    }

    bool read()
    {
        char w[NN*p_len];
        if(scanf("%s",w)==-1) return false;
        int i,n=strlen(w),m=0,p=1;
        len=0;
        for(i=0;i<n;i++)
        {
            m+=p*(w[n-i-1]-'0');p*=10;
            if((i+1)%p_len==0)
            {
                it[len++]=m;
                m=0;p=1;
            }
        }
        if(m>0) it[len++]=m;
        return true;
    }

    void print() const
    {
        if(len==0) printf("0"); else
        {
            int i=len-1;
            printf("%d",it[i]);
            char s[10];
            sprintf(s,"%%0%dd",p_len);
            for(i--;i>=0;i--) printf(s,it[i]);
        }
        printf("\n");
    }

    num operator+(const num &b) const
    {
        num s;
        int i,d=0;
        int maxlen=len>b.len?len:b.len;
        for(i=0;i<maxlen;i++)
        {
            if(i<len) d+=it[i];
            if(i<b.len) d+=b.it[i];
            s.it[i]=d%p;
            d/=p;
        }
        if(d>0) s.it[i++]=d;
        s.len=i;
        return s;
    }

    void operator+=(const num &b)
    {
        int i;
        int d=0;
        int maxlen=len>b.len?len:b.len;
        for(i=0;i<maxlen;i++)
        {
            if(i<len) d+=it[i];
            if(i<b.len) d+=b.it[i];
            it[i]=d%p;
            d/=p;
        }
        if(d>0) it[i++]=d;
        len=i;
    }

    void operator++()
    {
        int i;
        for(i=0;i<len && it[i]==p-1;i++) it[i]=0;
        if(i==len) it[len++]=1; else it[i]++;
    }

    num operator-(const num &b) const
    {
        num s;
        int i;
        int r,d=0;
        for(i=0;i<len;i++)
        {
            d+=it[i]-(i<b.len?b.it[i]:0);
            r=d%p;
            if(r<0) r+=p;
            s.it[i]=r;
            d=(d-r)/p;
        }
        for(i--;i>=0 && s.it[i]==0;i--);
        s.len=i+1;
        return s;
    }

    void operator-=(const num &b)
    {
        int i;
        int r,d=0;
        for(i=0;i<len;i++)
        {
            d+=it[i]-(i<b.len?b.it[i]:0);
            r=d%p;
            if(r<0) r+=p;
            it[i]=r;
            d=(d-r)/p;
        }
        for(i--;i>=0 && it[i]==0;i--);
        len=i+1;
    }

    void operator--()
    {
        int i;
        for(i=0;i<len && it[i]==0;i++) it[i]=p-1;
        it[i]--;
        if(it[len-1]==0) len--;
    }

    num operator*(int b) const
    {
        num prod(0);
        if(b==0) return prod;
        int i;
        int d=0;
        for(i=0;i<len;i++)
        {
            d+=it[i]*b;
            prod.it[i]=d%p;
            d/=p;
        }
        for(;d>0;d/=p) prod.it[i++]=d%p;
        prod.len=i;
        return prod;
    }

    void operator*=(int b)
    {
        if(b==0) { len=0; return; }
        int i;
        int d=0;
        for(i=0;i<len;i++)
        {
            d+=it[i]*b;
            it[i]=d%p;
            d/=p;
        }
        for(;d>0;d/=p) it[i++]=d%p;
        len=i;
    }

    bool operator==(const num &b) const
    {
        if(len!=b.len) return false;
        int i;
        for(i=len-1;i>=0 && it[i]==b.it[i];i--);
        return i<0;
    }

    bool operator!=(const num &b) const
    {
        if(len!=b.len) return true;
        int i;
        for(i=len-1;i>=0 && it[i]==b.it[i];i--);
        return i>=0;
    }

    bool operator<(const num &b) const
    {
        if(len!=b.len) return len<b.len;
        int i;
        for(i=len-1;i>=0 && it[i]==b.it[i];i--);
        return i>=0 && it[i]<b.it[i];
    }

    bool operator<=(const num &b) const
    {
        if(len!=b.len) return len<b.len;
        int i;
        for(i=len-1;i>=0 && it[i]==b.it[i];i--);
        return i<0 || it[i]<b.it[i];
    }

    bool operator>(const num &b) const
    {
        if(len!=b.len) return len>b.len;
        int i;
        for(i=len-1;i>=0 && it[i]==b.it[i];i--);
        return i>=0 && it[i]>b.it[i];
    }

    bool operator>=(const num &b) const
    {
        if(len!=b.len) return len>b.len;
        int i;
        for(i=len-1;i>=0 && it[i]==b.it[i];i--);
        return i<0 || it[i]>b.it[i];
    }

    num operator/(int q) const
    {
        num b;
        int i;
        int c=0;
        for(i=len-1;i>=0;i--)
        {
            c=p*c+it[i];
            b.it[i]=c/q;
            c%=q;
        }
        for(i=len-1;i>=0 && b.it[i]==0;i--);
        b.len=i+1;
        return b;
    }

    void operator/=(int q)
    {
        int i;
        int c=0;
        for(i=len-1;i>=0;i--)
        {
            c=p*c+it[i];
            it[i]=c/q;
            c%=q;
        }
        for(i=len-1;i>=0 && it[i]==0;i--);
        len=i+1;
    }

    int operator%(int b) const
    {
        int s=0;
        for(int i=len-1;i>=0;i--) s=(p*s+it[i])%b;
        return s;
    }
};

#define N 666
num p12[N];

int main()
{
    //freopen("d.in","r",stdin);
    //freopen("d.out","w",stdout);
    p12[0]=num(1);
    int n;
    for(n=1;n<N;n++)
        p12[n]=p12[n-1]*12;
    num a;
    while(a.read())
    {
        bool yes=false;
        int i,j,k;
        for(i=0;i<N && !yes;i++)
            for(j=0;j<=i && !yes;j++)
                if(p12[i]+p12[j]==a) yes=true;
        if(!yes){puts("NO");continue;}
        i--;j--;
        puts("YES");
        printf("1\n%d\n",i+j+1);
        printf("%d\n",(i+j)/2);
        for(k=(i+j)/2;k>=0;k--) if(k!=j && k!=i)
            (p12[k]+p12[i+j-k]).print();
    }
    return 0;
}