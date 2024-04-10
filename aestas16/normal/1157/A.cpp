#pragma GCC diagnostic error "-std=c++11"
#include <cstdio>
#include <map>
using namespace std;
template<class T>void r(T &a)
{
    T s=0,w=1;a=0;char ch=getc(stdin);
    while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getc(stdin);}
    while(ch>='0'&&ch<='9'){s=s*10+ch-'0';ch=getc(stdin);}
    a=w*s;
}
template<class T,class... Y>void r(T& t,Y&... a){r(t);r(a...);}
int f(int n)
{
    n++;
    while(!(n%10))
        n/=10;
    return n;
}
map<int,bool>book;
int main()
{
    int n,ans=0;
    r(n);
    for(;!book[n];n=f(n))
    {
        book[n]=true;
        ans++;
    }
    printf("%d",ans);
    return 0;
}//afsda