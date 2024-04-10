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
int a[200010];
//int A[200010];
string answer;
int main()
{
    int n,le=1,ri,last=-300000,ans=0;
    r(n);
    ri=n;
    for(int i=1;i<=n;i++)
        r(a[i]);
    while(le<=ri)
    {
        if(a[le]<a[ri])
        {
            if(a[le]>last)
            {
                ans++;
                last=a[le];
                //A[ans]=a[le];
                answer+='L';
                le++;
            }
            else if(a[ri]>last)
            {
                ans++;
                last=a[ri];
                //A[ans]=a[ri];
                answer+='R';
                ri--;
            }
            else break;
        }
        else if(a[ri]<a[le])
        {
            if(a[ri]>last)
            {
                ans++;
                last=a[ri];
                //A[ans]=a[ri];
                answer+='R';
                ri--;
            }
            else if(a[le]>last)
            {
                ans++;
                last=a[le];
                //A[ans]=a[le];
                answer+='L';
                le++;
            }
            else break;
        }
        else if(a[le]>last)
        {
            ans++;
            last=a[le];
            //A[ans]=a[le];
            answer+='L';
            le++;
        }
        else break;
    }
    printf("%d\n",ans);
    cout<<answer;
    return 0;
}