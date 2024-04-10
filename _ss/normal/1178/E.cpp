#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
const ll maxn=1e6+10;
int n=1,a[maxn],counted[4],mark[maxn],t;
char chcd[4]={'h','a','b','c'};

void read()
{
    char ch=getchar();
    while (ch!='\n' && ch!=-1)
    {
        a[n++]=ch-'a'+1;
        counted[ch-'a'+1]++;
        ch=getchar();
    }
    n--;
}

void process()
{
    for (int i=1;i<=n;i++) mark[i]=0;
    int l=1,r=n,siz;
    while (a[l]!=t) l++;
    while (a[r]!=t) r--;
    siz=counted[t];
    if (l>1 && r<n)
    {
        int l1=1,r1=n;
        if (a[l1]!=a[r1])
        {
            if (l-1>n-r) l1++;
            else r1--;
        }
        while (a[l1]!=t && a[l1]==a[r1] && a[r1]!=t)
        {
            mark[l1]=mark[r1]=1;
            l1++;
            r1--;
            siz+=2;
        }
    }
    l++;
    r--;
    while (l<=r)
    {
        int l2=l,r2=r;
        while (a[l2]!=t) l2++;
        while (a[r2]!=t) r2--;
        if (l2>r2)
        {
            for (int i=r2+1;i<=l2-1;i++) mark[i]=1,siz++;
            if (a[l2-1]!=a[r2+1]) mark[l2-1]=0,siz--;
        }
        else
        {
            if (a[l]!=a[r])
            {
                if (l2-l>r-r2) l++;
                else r--;
            }
            while (a[l]!=t && a[r]!=t)
            {
                mark[l]=mark[r]=1;
                l++;
                r--;
                siz+=2;
            }
        }
        l=l2;
        r=r2;
        l++;
        r--;
    }
    if (siz>=n/2)
    {
        for (int i=1;i<=n;i++)
            if (a[i]==t || mark[i]) cout<<chcd[a[i]];
        exit(0);
    }
}

int main()
{
    //freopen("ss.inp","r",stdin);
    read();
    for (t=1;t<=3;t++) process();
    return 0;
}