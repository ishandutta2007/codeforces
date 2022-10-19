#include <iostream>
#include <stack>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
#define N 10004
#define M 102
#define INF 1000000007
struct ban
{
    int h;
    map<int,int> a,b;
};
int p,m;
ban nt(char x)
{
    ban res;
    res.h=0;
    res.a[0]=x-'0';
    res.b[0]=x-'0';
    return res;
}
ban mer(ban a,ban b)
{
    ban res;
    res.h=a.h+b.h+1;
    if(p<m)
    {
        for(int i=0;i<=min(a.h,p);++i)
            for(int j=0;j<=min(b.h,p);++j)
            {
                if((i+j+1)<=p && (a.h-i+b.h-j)<=m)
                {
                    if(res.a.find(i+j+1)==res.a.end())
                        res.a[i+j+1]=-INF;
                    if(res.b.find(i+j+1)==res.b.end())
                        res.b[i+j+1]=INF;
                    res.a[i+j+1]=max(res.a[i+j+1],a.a[i]+b.a[j]);
                    res.b[i+j+1]=min(res.b[i+j+1],a.b[i]+b.b[j]);
                }
                if((i+j)<=p && (a.h-i+b.h-j+1)<=m)
                {
                    if(res.a.find(i+j)==res.a.end())
                        res.a[i+j]=-INF;
                    if(res.b.find(i+j)==res.b.end())
                        res.b[i+j]=INF;
                    res.a[i+j]=max(res.a[i+j],a.a[i]-b.b[j]);
                    res.b[i+j]=min(res.b[i+j],a.b[i]-b.a[j]);
                }
            }
    }
    else
    {
        for(int i=0;i<=min(a.h,m);++i)
            for(int j=0;j<=min(b.h,m);++j)
            {
                if((i+j+1)<=m && (a.h-i+b.h-j)<=p)
                {
                    if(res.a.find(a.h-i+b.h-j)==res.a.end())
                        res.a[a.h-i+b.h-j]=-INF;
                    if(res.b.find(a.h-i+b.h-j)==res.b.end())
                        res.b[a.h-i+b.h-j]=INF;
                    res.a[a.h-i+b.h-j]=max(res.a[a.h-i+b.h-j],a.a[a.h-i]-b.b[b.h-j]);
                    res.b[a.h-i+b.h-j]=min(res.b[a.h-i+b.h-j],a.b[a.h-i]-b.a[b.h-j]);
                }
                if((i+j)<=m && (a.h-i+b.h-j+1)<=p)
                {
                    if(res.a.find(a.h-i+b.h-j+1)==res.a.end())
                        res.a[a.h-i+b.h-j+1]=-INF;
                    if(res.b.find(a.h-i+b.h-j+1)==res.b.end())
                        res.b[a.h-i+b.h-j+1]=INF;
                    res.a[a.h-i+b.h-j+1]=max(res.a[a.h-i+b.h-j+1],a.a[a.h-i]+b.a[b.h-j]);
                    res.b[a.h-i+b.h-j+1]=min(res.b[a.h-i+b.h-j+1],a.b[a.h-i]+b.b[b.h-j]);
                }
            }
    }
    return res;
}

int n;
char a[N];
int main()
{
    cin>>a;
    n=strlen(a);
    cin>>p>>m;
    if(n==1)
    {
        cout<<a[0]<<endl;
        return 0;
    }
    stack<ban> b;
    for(int i=0;i<n;++i)
    {
        ban t;
        if(a[i]=='(' || a[i]=='?')
        {
            b.push(t);
        }
        else if(a[i]>='0' && a[i]<='9')
        {
            t=nt(a[i]);
            b.push(t);
        }
        else
        {
            ban t1,t2;
            t2=b.top();
            b.pop();
            b.pop();
            t1=b.top();
            b.pop();
            b.pop();
            t=mer(t1,t2);
            b.push(t);
            if(i==n-1)
            {
                cout<<t.a[p]<<endl;
                return 0;
            }
        }
    }
    return 0;
}