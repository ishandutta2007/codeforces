#pragma GCC diagnostic error "-std=c++11"
#include <iostream>
#include <cstdio>
using namespace std;
template<class T>void r(T &a)
{
    T s=0,w=1;a=0;char ch=getc(stdin);
    while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getc(stdin);}
    while(ch>='0'&&ch<='9'){s=s*10+ch-'0';ch=getc(stdin);}
    a=w*s;
}
template<class T,class... Y>void r(T& t,Y&... a){r(t);r(a...);}
int a[200010],ans;
string answer;
void check(int le,int ri)
{
    int sum1=1,sum2=1;
    for(int i=le+1;le<=ri;i++)
    {
        if(a[i]<=a[i-1])break;
        sum1++;
    }
    for(int i=ri-1;i>=1;i--)
    {
        if(a[i]<=a[i+1])break;
        sum2++;
    }
    if(sum1>sum2)
    {
        for(int i=le;i<=le+sum1-1;i++)
        {
            ans++;
            answer+='L';
        }
    }
    else
    {
        for(int i=ri;i>=ri-sum2+1;i--)
        {
            ans++;
            answer+='R';
        }
    }
    return;
}
int main()
{
    int n,le=1,ri,last=0;
    r(n);
    ri=n;
    for(int i=1;i<=n;i++)
        r(a[i]);
    while(1)
    {
        if(a[le]<=last&&a[ri]<=last)break;
        if(le==ri)
        {
            ans++;
            answer+='R';
            break;
        }
        if(a[le]<a[ri]&&a[le]>last||a[le]>a[ri]&&a[ri]<=last)
        {
            last=a[le++];
            ans++;
            answer+='L';
        }
        else if(a[le]>a[ri]&&a[ri]>last||a[ri]>a[le]&&a[le]<=last)
        {
            last=a[ri--];
            ans++;
            answer+='R';
        }
        else if(a[le]==a[ri])
        {
            check(le,ri);
            break;
        }
    }
    printf("%d\n",ans);
    cout<<answer;
    return 0;
}