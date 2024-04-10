#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;
typedef long long LL;
const int oo=1000020000;
const int V=1000100;
struct Bug
{
    int x,id;
}b[V];
bool cmpb(Bug x,Bug y)
{
    return x.x>y.x;
}
struct Stu
{
    int x,c,id;
}s[V];
bool cmps(Stu x,Stu y)
{
    return x.x>y.x;
}
struct Heap
{
    int a[V];
    int size;
    void init()
    {
        size=0;
    }
    void flow(int k)
    {
        while(k>1)
        {
            if(s[a[k]].c<s[a[k/2]].c)
            {
                swap(a[k],a[k/2]);
                k/=2;
            }
            else break;
        }
    }
    void push(int k)
    {
        a[++size]=k;
        flow(size);
    }
    int top()
    {
        return a[1];
    }
    void sink(int k)
    {
        while(k*2<=size)
        {
            int id=k,mi=s[a[k]].c;
            if(k*2<=size&&s[a[2*k]].c<mi)mi=s[a[2*k]].c,id=k*2;
            if(k*2+1<=size&&s[a[2*k+1]].c<mi)mi=s[a[2*k+1]].c,id=k*2+1;
            if(id==k)break;
            swap(a[id],a[k]);k=id;
        }
    }
    void pop()
    {
        a[1]=a[size];size--;
        sink(1);
    }
}H;
int ret[V],n,m,C;
bool check(int mid)
{
    H.init();
    int p=0;
    LL cs=0;
    for(int i=0;i<m;i+=mid)
    {
        while(p<n&&s[p].x>=b[i].x)
        {
            H.push(p);
            p++;
        }
        if(H.size==0)
        {
            return false;
        }
        int id=H.top();H.pop();
        cs+=s[id].c;
        for(int j=i;j<min(i+mid,m);j++)
        ret[b[j].id]=s[id].id;
    }
    if(cs<=C)return true;
    else return false;
}
int main()
{
    while(~scanf("%d%d%d",&n,&m,&C))
    {
        for(int i=0;i<m;i++)
        {
            scanf("%d",&b[i].x);
            b[i].id=i;
        }
        sort(b,b+m,cmpb);
        for(int i=0;i<n;i++)
        scanf("%d",&s[i].x);
        for(int i=0;i<n;i++)
        scanf("%d",&s[i].c);
        for(int i=0;i<n;i++)
        s[i].id=i;
        sort(s,s+n,cmps);
        int lo=0,up=m+1;
        while(lo+1<up)
        {
            int mid=(lo+up)/2;
            if(check(mid))up=mid;
            else lo=mid;
        }
        if(check(up))
        {
            puts("YES");
            for(int i=0;i<m;i++)
            printf("%d ",ret[i]+1);puts("");
        }
        else puts("NO");
    }
}